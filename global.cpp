#include "global.h"
#include<QFile>
#include<QMessageBox>
#include<QDateTime>

//在头文件中声明的静态数据成员需要在源文件中进行定义————头文件中并不分配内存空间嘛
QVector<SessionMessage> Global::SESSION_LIST;
QVector<Player> Global::PLAYER_LIST;
PlayerTableModel* Global::playerTableModel;
SessionTableModel* Global::sessionTableModel;



//更新球员信息
void Global::updatePlayerInfo(const QString&)
{
    Player p;
    bool ifExist=false;
    for(Player&iter:Global::PLAYER_LIST)
    {
        if(iter.getNumber()==iter.getNumber()){
            p=iter;
            ifExist=true;
            break;
        }
    }
    //如果存在就更新球员信息
    if(ifExist)
    {
        int threeNum=0,reboundNum=0,dunckNum=0,brokenNum=0,scoreNum=0;
        for(SessionMessage& iter:Global::SESSION_LIST)
        {
            threeNum+=iter.getNThreeCount();
            reboundNum+=iter.getNReboundCount();
            dunckNum+=iter.getNDunkCount();
            brokenNum+=iter.getNBrokenCount();
            scoreNum+=iter.getNScore();
        }
        p.setThreeSum(threeNum);
        p.setScoreSum(scoreNum);
        p.setReboundSum(reboundNum);
        p.setBrokenSum(brokenNum);
        p.setDunkSum(dunckNum);
    }
}

//添加场次信息，注意球员信息列表和场次列表之间的信息同步
void Global::AddSession(const SessionMessage &session)
{
    bool ifExist=false;

    //首先判断球员是否存在
    for(Player& iter : PLAYER_LIST)
    {
        //存在--更新PlayerList 添加sessionList
        if(iter.getNumber()==session.getNumber())
        {
            ifExist=true;
            iter.setDunkSum(iter.getDunkSum()+session.getNDunkCount());//扣篮
            iter.setBrokenSum(iter.getBrokenSum()+session.getNBrokenCount());//抢断
            iter.setReboundSum(iter.getReboundSum()+session.getNReboundCount());//篮板
            iter.setScoreSum(iter.getScoreSum()+session.getNScore());//得分
            iter.setThreeSum(iter.getThreeSum()+session.getNThreeCount());//三分
        }
    }
    if(ifExist)//添加场次信息
    {
        sessionTableModel->addSession(session);
        Global::SESSION_LIST.push_back(session);
        Global::updatePlayerInfo(session.getNumber());
        playerTableModel->setDataInTable(Global::PLAYER_LIST);
    }
    else if(!ifExist)//既往数据中没有该球员信息，球员信息和场次信息中同步进行信息添加
    {
        Player p;
        p.setNumber(session.getNumber());
        p.setBrokenSum(session.getNBrokenCount());
        p.setDunkSum(session.getNDunkCount());
        p.setName(session.getName());
        p.setReboundSum(session.getNReboundCount());
        p.setScoreSum(session.getNScore());
        p.setThreeSum(session.getNThreeCount());
        p.setTeam(session.getTeam());
        Global::PLAYER_LIST.push_back(p);
        playerTableModel->addPlayer(p);
        sessionTableModel->addSession(session);
        Global::SESSION_LIST.push_back(session);
    }

}

//修改场次信息
void Global::ModifySession(const SessionMessage &session,int row,const QDateTime&time)
{
    int minusThreeCount;//老的本场三分
    int plusThreeCount;//新的本场三分
    int minusReboundCount;//老的本场篮板
    int plusReboundCount;//新的本场篮板
    int minusDunkCount;//老的本场扣篮
    int plusDunkCount;//新的本场扣篮
    int minusBrokenCount;//老的本场抢断
    int plusBrokenCount;//新的本场抢断
    int minusScoreCount;//老的本场得分
    int plusScoreCount;//新的本场得分

    for(SessionMessage& iter:SESSION_LIST)
    {
        if(iter.getNumber()==session.getNumber()&&iter.getTime()==time)//通过球员和比赛时间确定出唯一场次
        {
            //获取旧信息
            minusThreeCount=iter.getNThreeCount();
            minusReboundCount=iter.getNReboundCount();
            minusDunkCount=iter.getNDunkCount();
            minusBrokenCount=iter.getNBrokenCount();
            minusScoreCount=iter.getNScore();

            //记录新信息
            plusThreeCount=session.getNThreeCount();
            plusReboundCount=session.getNReboundCount();
            plusDunkCount=session.getNDunkCount();
            plusBrokenCount=session.getNBrokenCount();
            plusScoreCount=session.getNScore();

            //修改场次信息
            iter.setName(session.getName());
            iter.setTeam(session.getTeam());

            iter.setNThreeCount(session.getNThreeCount());
            iter.setNReboundCount(session.getNReboundCount());
            iter.setNDunkCount(session.getNDunkCount());
            iter.setNBrokenCount(session.getNBrokenCount());
            iter.setNScore(session.getNScore());

            iter.setTime(session.getTime());

            updatePalyers();

            Global::sessionTableModel->setSessionAt(row,iter);//调用了修改场次信息的二级函数
        }
    }

    //球员信息列表中进行同步更新
    for(Player& iter:PLAYER_LIST)
    {
        if(iter.getNumber()==session.getNumber())//找到对应的球员信息，下面进行更新
        {
            iter.setThreeSum(iter.getThreeSum()-minusThreeCount+plusThreeCount);
            iter.setReboundSum(iter.getReboundSum()-minusReboundCount+plusReboundCount);
            iter.setDunkSum(iter.getDunkSum()-minusDunkCount+plusDunkCount);
            iter.setBrokenSum(iter.getBrokenSum()-minusBrokenCount+plusBrokenCount);
            iter.setScoreSum(iter.getScoreSum()-minusScoreCount+plusScoreCount);

            updatePalyers();

            Global::playerTableModel->setDataInTable(PLAYER_LIST);
        }
    }
}



//从文件读取数据
bool Global::getDataFromFile(const QString &playerFile, const QString &sessionFile)
{
    //先清空列表中的数据，否则可能重复读取
    Global::PLAYER_LIST.clear();
    Global::SESSION_LIST.clear();
    Global::sessionTableModel->clearSession();
    Global::playerTableModel->clearPlayer();

    //先读取球员数据
    QFile player_file(playerFile);
    QFile session_file(sessionFile);
    if(!player_file.open(QFile::ReadOnly|QFile::Text))
        return false;
    if(!session_file.open(QFile::ReadOnly|QFile::Text))
    {
        player_file.close();
        return false;
    }
    while(!player_file.atEnd())
    {
        QString line=player_file.readLine();//从文件player_file中读取一行文本，并将其存储在line中。
                                            //readLine() 方法读取文件中的一整行（包括换行符），并将其作为
                                            //QString 类型返回

        line.chop(1);//删除行末的最后一个字符（一般是换行符）
        QStringList lineData=line.split("\t");//制表符分隔数据，注意分隔方式要与SessionMessgae类中的toString函数相互统一
        if(lineData.length()!=8)
        {//保证每一条数据的8个信息全部读取完毕
            continue;
        }
        int threeNum=0,reboundNum=0,brokenNum=0,scoreNum=0,dunkNum=0;
        QString number,name,team;
        Player p;
        number=lineData.at(0);
        name=lineData.at(1);
        team=lineData.at(2);
        threeNum=lineData.at(3).toInt();
        reboundNum=lineData.at(4).toInt();
        dunkNum=lineData.at(5).toInt();
        brokenNum=lineData.at(6).toInt();
        scoreNum=lineData.at(7).toInt();
        p.setNumber(number);
        p.setBrokenSum(brokenNum);
        p.setDunkSum(dunkNum);
        p.setReboundSum(reboundNum);
        p.setName(name);
        p.setTeam(team);
        p.setThreeSum(threeNum);
        p.setScoreSum(scoreNum);
        Global::PLAYER_LIST.push_back(p);
    }
    while(!session_file.atEnd()){
        QString line=session_file.readLine();
        QStringList lineData=line.split("\t");//分割数据，注意分隔方式要与SessionMessgae类中的toString函数相互统一
        if(lineData.length()!=9){
            continue;
        }
        int threeNum=0,reboundNum=0,brokenNum=0,scoreNum=0,dunkNum=0;
        QString number,name,team;
        QDateTime time;
        SessionMessage p;
        number=lineData.at(0);
        name=lineData.at(1);
        team=lineData.at(2);
        threeNum=lineData.at(3).toInt();
        reboundNum=lineData.at(4).toInt();
        dunkNum=lineData.at(5).toInt();
        brokenNum=lineData.at(6).toInt();
        scoreNum=lineData.at(7).toInt();
        time=QDateTime::fromString(lineData.at(8),"yyyy-MM-dd hh:mm");
        p.setNumber(number);
        p.setNBrokenCount(brokenNum);
        p.setNDunkCount(dunkNum);
        p.setNReboundCount(reboundNum);
        p.setName(name);
        p.setTeam(team);
        p.setNThreeCount(threeNum);
        p.setNScore(scoreNum);
        Global::SESSION_LIST.push_back(p);
    }
    player_file.close();
    session_file.close();
    playerTableModel->setDataInTable(Global::PLAYER_LIST);
    sessionTableModel->setData(Global::SESSION_LIST);
    return true;
}

//将数据输出到文件中
bool Global::outPutToFile(const QString &playerFile, const QString &sessionFile)
{
    QFile player_file(playerFile);
    QFile session_file(sessionFile);
    if(!player_file.open(QFile::WriteOnly))
    {
        return false;
    }
    if(!session_file.open(QFile::WriteOnly))
    {
        player_file.close();
        return false;
    }

    //开始正式输出
    for(SessionMessage& iter:Global::SESSION_LIST)
    {
        QString line=iter.toString()+"\n";
        session_file.write(line.toUtf8());//保证编码格式
    }
    for(Player& iter:Global::PLAYER_LIST)
    {
        QString line=iter.toString()+"\n";
        player_file.write(line.toUtf8());
    }
    player_file.close();
    session_file.close();
    return true;
}

//筛选后的数据输出到文件，注意是右边的按钮而非菜单栏的按钮
bool Global::FilteroutPutToFile(const QString &PlayerFile)
{
    QFile file(PlayerFile);

    if(!file.open(QFile::WriteOnly))
    {
        return false;
    }

    //正式输出
    for(Player&iter:Global::playerTableModel->m_playerVec)
    {
        QString line=iter.toString()+"\n";
        file.write(line.toUtf8());
    }
    file.close();//切记关闭文件
    return true;
}


//删除球员信息（要求信息的同步更新）
void Global::deletePlayer(const QString& num)
{
    int index=-1;

    //处理球员信息列表
    for(Player&iter:PLAYER_LIST)
    {
        index++;
        if(iter.getNumber()==num)
        {
            PLAYER_LIST.removeAt(index);
            break;
        }
    }

    //处理场次信息列表
    QVector<SessionMessage>temp;
    for(SessionMessage&iter:SESSION_LIST)
    {
        if(iter.getNumber()!=num)
        temp.push_back(iter);
    }
    SESSION_LIST=temp;
    sessionTableModel->setData(temp);

}

//删除场次信息（要求信息的同步更新）
void Global::deleteSession(const QString &num, const QDateTime &time)
{
    int index=-1;

    int minusThreeCount;//需要减去的三分球信息
    int minusReboundCount;//需要减去的篮板信息
    int minusDunkCount;//需要减去的扣篮总数
    int minusBrokenCount;//需要减去的抢断总数
    int minusScoreCount;//需要减去的分数

    //处理场次信息列表
    for(SessionMessage& iter:SESSION_LIST)
    {
        index++;
        if(iter.getNumber()==num&&iter.getTime()==time)
        {
            SESSION_LIST.removeAt(index);
            minusThreeCount=iter.getNThreeCount();
            minusReboundCount=iter.getNReboundCount();
            minusDunkCount=iter.getNDunkCount();
            minusBrokenCount=iter.getNBrokenCount();
            minusScoreCount=iter.getNScore();
            break;
        }
    }

    //处理球员信息列表
    for(Player& iter:PLAYER_LIST)
    {
        if(iter.getNumber()==num)//找到了相应的球员信息
        {
            iter.setThreeSum(iter.getThreeSum()-minusThreeCount);
            iter.setReboundSum(iter.getReboundSum()-minusReboundCount);
            iter.setDunkSum(iter.getDunkSum()-minusDunkCount);
            iter.setBrokenSum(iter.getBrokenSum()-minusBrokenCount);
            iter.setScoreSum(iter.getScoreSum()-minusScoreCount);

            updatePalyers();
            Global::playerTableModel->setDataInTable(PLAYER_LIST);

            break;
        }
    }
}

//刷新球员信息
void Global::updatePalyers()
{
    QStringList numList;
    for(SessionMessage& iter:SESSION_LIST)
    {
        numList.push_back(iter.getNumber());
    }
    numList.removeDuplicates();//删除掉重复的球员编号，保证numList里面没有重复

    QVector<Player>temp;//创建一个临时的球员容器
    for(Player& iter:PLAYER_LIST)
    {
        if(numList.contains(iter.getNumber()))
        {
            temp.push_back(iter);//将满足相关球员编号的球员信息加进去
        }
    }

    PLAYER_LIST=temp;
    for(QString& iter:numList)
    {
        updatePlayerInfo(iter);
    }
}


