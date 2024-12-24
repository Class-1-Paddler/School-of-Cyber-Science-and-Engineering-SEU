#ifndef DATACLASS_H
#define DATACLASS_H

#include<QString>       //QString类似C++中的string类
#include<QTime>         //用于记录每场比赛的时间信息
#include<QTextStream>   //Qt中用于处理Qt中的输入输出流，如QString类型等（注意不能处理QDataTime对象）
#include<QVector>  //Qt中的一种STL容器，类似C++中的vector。用于后续场次信息表和球员信息列表的信息存储
#include<QFile>



//SessionMessage类用于描述场次信息
class SessionMessage
{
private:
    QString number; // 球员编号
    //****************************************************************
    //请注意：球员编号之于球员姓名就像身份证号之于人
    //****************************************************************
    QString name; // 球员姓名
    QString team; // 球队名称
    int nThreeCount; // 三分球个数
    int nReboundCount; // 篮板个数
    int nDunkCount; // 扣篮成功次数
    int nBrokenCount; // 抢断次数
    int nScore; // 得分
    QDateTime time; // 比赛时间

public:

    //toString函数用于实现将球员信息转化为一个QString数据，其本质是对诸如QDateTime里面的toString等进行模仿
    //从而实现便于文件读取等功能
    QString toString()const
    {
        return number+"\t"+name+"\t"+team+"\t"+QString::number(nThreeCount)+"\t"+QString::number(nReboundCount)+
               "\t"+QString::number(nDunkCount)+"\t"+QString::number(nBrokenCount)+"\t"+QString::number(nScore)+
               "\t"+time.toString("yyyy-MM-dd hh:mm");
    }

    //默认的无参构造函数
    SessionMessage()
        : number(QString()), name(QString()), team(QString()),
        nThreeCount(0), nReboundCount(0), nDunkCount(0), nBrokenCount(0), nScore(0),
        time(QDateTime::currentDateTime()) {;};// 默认设置为当前时间

    //有参构造函数。通过初始化列表的方式
    SessionMessage(const QString& number, const QString& name, const QString& team,
                   int nThreeCount, int nReboundCount, int nDunkCount, int nBrokenCount, int nScore,
                   const QDateTime& time)
        : number(number), name(name), team(team),
        nThreeCount(nThreeCount), nReboundCount(nReboundCount), nDunkCount(nDunkCount),
        nBrokenCount(nBrokenCount), nScore(nScore),time(time){};

    // 拷贝构造函数
    SessionMessage(const SessionMessage& other)
        : number(other.number), name(other.name), team(other.team),
        nThreeCount(other.nThreeCount), nReboundCount(other.nReboundCount), nDunkCount(other.nDunkCount), nBrokenCount(other.nBrokenCount), nScore(other.nScore),
        time(other.time){;};//基础操作

    // 重载等号运算符
    SessionMessage& operator=(const SessionMessage& other)
    {
        if (this != &other) {
            number = other.number;
            name = other.name;
            team = other.team;
            nThreeCount = other.nThreeCount;
            nReboundCount = other.nReboundCount;
            nDunkCount = other.nDunkCount;
            nBrokenCount = other.nBrokenCount;
            nScore = other.nScore;
            time = other.time;
        }
        return *this;
    }

    // 成员函数
    QString getNumber() const { return number; }
    void setNumber(const QString& number) { this->number = number; }
    QString getName() const { return name; }
    void setName(const QString& name) { this->name = name; }
    QString getTeam() const { return team; }
    void setTeam(const QString& team) { this->team = team; }
    int getNThreeCount() const { return nThreeCount; }
    void setNThreeCount(int n) { nThreeCount = n; }
    int getNReboundCount() const { return nReboundCount; }
    void setNReboundCount(int n) { nReboundCount = n; }
    int getNDunkCount() const { return nDunkCount; }
    void setNDunkCount(int n) { nDunkCount = n; }
    int getNBrokenCount() const { return nBrokenCount; }
    void setNBrokenCount(int n) { nBrokenCount = n; }
    int getNScore() const { return nScore; }
    void setNScore(int n) { nScore = n; }
    QDateTime getTime() const { return time; }
    void setTime(const QDateTime& newTime) { time = newTime; }

};



//Player类用于存储球员信息
class Player
{
private:
    QString number; // 球员编号
    QString name; // 球员姓名
    QString team; // 球队名称
    int nThreeSum; // 三分球总个数
    int nReboundSum; // 篮板总个数
    int nDunkSum; // 扣篮总成功数
    int nBrokenSum; // 抢断总次数
    int nScoreSum; // 总得分

public:

    //同SessionMessage类，转化为一条QString信息
    QString toString()const
    {
         return number+"\t"+name+"\t"+team+"\t"+QString::number(nThreeSum)+"\t"+QString::number(nReboundSum)+
               "\t"+QString::number(nDunkSum)+"\t"+QString::number(nBrokenSum)+"\t"+QString::number(nScoreSum);
    }

    //空构造函数
    Player()
        : number(QString()), name(QString()), team(QString()),
        nThreeSum(0), nReboundSum(0), nDunkSum(0), nBrokenSum(0), nScoreSum(0){;};

    //有参构造函数
    Player(const QString& number, const QString& name, const QString& team,
           int nThreeSum, int nReboundSum, int nDunkSum, int nBrokenSum, int nScoreSum)
        : number(number), name(name), team(team),
        nThreeSum(nThreeSum), nReboundSum(nReboundSum), nDunkSum(nDunkSum), nBrokenSum(nBrokenSum), nScoreSum(nScoreSum){};

    //拷贝构造函数
    Player(const Player& member)
        : number(member.number), name(member.name), team(member.team),
        nThreeSum(member.nThreeSum), nReboundSum(member.nReboundSum), nDunkSum(member.nDunkSum),
        nBrokenSum(member.nBrokenSum), nScoreSum(member.nScoreSum){};

    //重载等号赋值运算符
    Player& operator=(const Player& other)
    {
        if (this != &other)//赋值运算符先考虑是不是自身给自身赋值
        {
            number = other.number;
            name = other.name;
            team = other.team;
            nThreeSum = other.nThreeSum;
            nReboundSum = other.nReboundSum;
            nDunkSum = other.nDunkSum;
            nBrokenSum = other.nBrokenSum;
            nScoreSum = other.nScoreSum;
        }
        return *this;
    }

    // 成员函数
    QString getNumber() const { return number; }
    void setNumber(const QString& num) { number = num; }
    QString getName() const { return name; }
    void setName(const QString& playerName) { name = playerName; }
    QString getTeam() const { return team; }
    void setTeam(const QString& teamName) { team = teamName; }
    int getThreeSum() const { return nThreeSum; }
    void setThreeSum(int threeSum) { nThreeSum = threeSum; }
    int getReboundSum() const { return nReboundSum; }
    void setReboundSum(int reboundSum) { nReboundSum = reboundSum; }
    int getDunkSum() const { return nDunkSum; }
    void setDunkSum(int dunkSum) { nDunkSum = dunkSum; }
    int getBrokenSum() const { return nBrokenSum; }
    void setBrokenSum(int brokenSum) { nBrokenSum = brokenSum; }
    int getScoreSum() const { return nScoreSum; }
    void setScoreSum(int scoreSum) { nScoreSum = scoreSum; }


};


Q_DECLARE_METATYPE(Player)
Q_DECLARE_METATYPE(SessionMessage)
#endif // DATACLASS_H
