#include "playerTableModel.h"
#include<QDebug>
#include "global.h"


QVariant  PlayerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{//三个参数中，section表示行或列的索引；orientation指定请求的头部是水平表头还是垂直表头，

    //首先处理异常情况，增强程序的健壮性
    if(havehHeader==false)//处理表头尚未设置的情况，提高程序的健壮性
        return  QVariant();

    if (role != Qt::DisplayRole)//如果请求的角色不是Qt::DisplayRole，也返回一个空的QVariant。
                                //通常表头的数据角色只有 Qt::DisplayRole是有意义的
        return QVariant();


    //可能的异常情况处理完毕，下面开始进行正常的表头信息读取
    if (orientation == Qt::Horizontal)//表格抬头按行
        return hHeaderList.at(section);//返回某一列的标题（尽管我们设计的table都是这样）
    else if (orientation == Qt::Vertical)
        return section + 1;
    else return QVariant();
}


//获取所需数据，role缺省状态下设置为DisplayRole，返回某单元格数据，当然通过对role的设置可以实现返回其它数据
QVariant  PlayerTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();//处理需要读取的单元格不合理的情况，增强程序的健壮性

    if (role == Qt::DisplayRole)//当role被设置为“获取显示在视图中的数据时”的DisplayRole宏时读取单元格详细数据
    {
        const Player& course = m_playerVec.at(index.row());
        switch (index.column()) {
        case 0: return course.getNumber();break;//球员编号
        case 1: return course.getName();break;//球员姓名
        case 2: return course.getTeam(); break;//球队名称
        case 3: return course.getThreeSum();break;//三分球总数
        case 4 : return course.getReboundSum();break;//篮板总数
        case 5: return course.getDunkSum();break;//扣篮总数
        case 6: return course.getBrokenSum();break;//抢断总数
        case 7: return course.getScoreSum();break;//总得分
        default: return QVariant();
        }
    }
    else  if(role==CourseRole)
        return QVariant::fromValue(m_playerVec.at(index.row()));

    else  if(role==IdRole)
        return m_playerVec.at(index.row()).getNumber();

    else return QVariant();
}

//设置表头内容，注意只是通过QStringList设置了表头的内容，还没有具体地显示出来
void  PlayerTableModel::setHorizontalHeader(const QStringList& headerList)
{
    this->hHeaderList=headerList;
    this->havehHeader=true;
}

//返回相应行的Player对象
Player PlayerTableModel::getPlayer(int row)const
{
    return m_playerVec.at(row);//返回选中行的对象
}

//在视图上输出新的数据
void  PlayerTableModel::setDataInTable(const QVector<Player>& newVirtualPlayerVec)
{
    beginResetModel();
    m_playerVec=newVirtualPlayerVec;
    endResetModel();
}

//查询球员信息
void PlayerTableModel::search(int index, const QString &data)
{
    switch(index)//选择分支中要善用switch-case语句，采用switch语句明显比if-else语句方便许多
    {
    case 0://按球员编号查询
    {
        QVector<Player> temp;
        for(Player* iter=Global::PLAYER_LIST.begin();iter!=Global::PLAYER_LIST.end();++iter)
        {
            if(iter->getNumber()==data)
                temp.push_back(*iter);
        }
        setDataInTable(temp);
        break;
    }

    case 1://按球员姓名查找
    {
        QVector<Player> tempVec;
        for(Player& iter:Global::PLAYER_LIST)//利用C++11的迭代器
        {
            if(iter.getName()==data)
                tempVec.push_back(iter);
        }
        setDataInTable(tempVec);
        break;
    }

    case 2://按球队名称查找
    {
        QVector<Player> tempVec;
        for(Player& iter:Global::PLAYER_LIST)
        {
            if(iter.getTeam()==data)
                tempVec.push_back(iter);
        }
        setDataInTable(tempVec);
        break;
    }
    }

}

//删除整条球员的信息
void PlayerTableModel::delPlayers(const QModelIndexList& needDelList)
{
    QStringList numList;//创建一个numList用于记需要删除的球员姓名

    for(auto& iter:needDelList)//iter的类型不太搞得清楚，用C++11的自动类型推断
        numList.push_back(getPlayer(iter.row()).getNumber());//将需要删除的球员的信息全部统一到numList当中

    QVector<Player> tempVec;//存储更新后的数据集合（亦即不需要删除的部分）

    for(auto& iter:m_playerVec)
    {
        if(!numList.contains(iter.getNumber()))
            tempVec.push_back(iter);
        else
            Global::deletePlayer(iter.getNumber());
    }

    setDataInTable(tempVec);//在playerTable界面进行数据更新
}

//进行球员信息的筛选
void PlayerTableModel::filter(int index, bool ifUp,int num)
{
    if(ifUp)
    {//升序
        switch (index)
        {
        case 0://按三分球筛选
            std::sort(m_playerVec.begin(), m_playerVec.end(),
                      [](const Player& p1, const Player& p2)
                      { return p1.getThreeSum() < p2.getThreeSum(); });
            //采用了Lambda函数
            break;
        case 1://按篮板筛选
            std::sort(m_playerVec.begin(), m_playerVec.end(), [](const Player& p1, const Player& p2) { return p1.getReboundSum() < p2.getReboundSum(); });
            break;
        case 2://扣篮
            std::sort(m_playerVec.begin(), m_playerVec.end(), [](const Player& p1, const Player& p2) { return p1.getDunkSum()< p2.getDunkSum(); });
            break;
        case 3://抢断
            std::sort(m_playerVec.begin(), m_playerVec.end(), [](const Player& p1, const Player& p2) { return p1.getBrokenSum()< p2.getBrokenSum(); });
            break;
        default:
            break;
        }
    }
    else{//降序
        switch (index)
        {
        case 0://三分球
            std::sort(m_playerVec.begin(), m_playerVec.end(), [](const Player& p1, const Player& p2) { return p1.getThreeSum() > p2.getThreeSum(); });
            break;
        case 1://篮板
            std::sort(m_playerVec.begin(), m_playerVec.end(), [](const Player& p1, const Player& p2) { return p1.getReboundSum() > p2.getReboundSum(); });
            break;
        case 2://扣篮
            std::sort(m_playerVec.begin(), m_playerVec.end(), [](const Player& p1, const Player& p2) { return p1.getDunkSum()> p2.getDunkSum(); });
            break;
        case 3://抢断
            std::sort(m_playerVec.begin(), m_playerVec.end(), [](const Player& p1, const Player& p2) { return p1.getBrokenSum()> p2.getBrokenSum(); });
            break;
        default:
            break;
        }
    }
    setDataInTable(m_playerVec.mid(0,num));
}

//添加球员信息（容器和视图中同步添加）
void  PlayerTableModel::addPlayer(const Player& newMember)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());//通知视图即将插入数据
    //QModelIndex()：表示插入行的位置在模型的根（即顶层），这是一个无效的索引，用于表示根位置。
    //rowCount()：表示新数据的起始行索引，rowCount() 返回当前模型的行数，也就是新数据将插入到模型的最后一行。
    //rowCount()：表示新数据的结束行索引，和起始索引相同，表示插入一行。
    m_playerVec.push_back(newMember);
    endInsertRows();
}

//清除球员信息（容器和视图中同步清除）
void  PlayerTableModel::clearPlayer()
{
    beginResetModel();
    m_playerVec.clear();
    endResetModel();
}

