#ifndef GLOBAL_H
#define GLOBAL_H
#include"dataClass.h"
#include"playerTableModel.h"
#include"sessionTableModel.h"

//在基于Player和SessionMessage的PlayerTableModel和SessionTableModel修改时无法互相同步的封装下，
//通过一个偏顶层的“全局”方法来进行修改

class Global
{
public://数据成员
    static SessionTableModel* sessionTableModel;
    static PlayerTableModel* playerTableModel;
    static QVector<SessionMessage> SESSION_LIST;
    static QVector<Player> PLAYER_LIST;

public:
    explicit Global(){};//构造函数
    virtual ~Global(){};//析构函数，注意声明为虚函数

    static void setPlayerModel(PlayerTableModel*model){playerTableModel=model;}//赋值数据成员
    static void setSessionModel(SessionTableModel*model){sessionTableModel=model;}//赋值数据成员

    static void AddSession(const SessionMessage&session);//添加场次信息，注意球员信息列表和场次列表之间的信息同步
    static void ModifySession(const SessionMessage&session,int row,const QDateTime&time);//修改场次信息
    static bool getDataFromFile(const QString&playerFile,const QString&sessionFile);//从文件中读取数据
    static bool outPutToFile(const QString&PlayerFile,const QString&sessionFile);//写出到文件
    static bool FilteroutPutToFile(const QString&PlayerFile);//筛选后的数据输出到文件
    static void deletePlayer(const QString&num);//删除球员信息（要求信息的同步更新）
    static void deleteSession(const QString&num,const QDateTime&time);//删除场次信息（要求信息的同步更新）
    static void updatePalyers();//刷新球员信息

    static void updatePlayerInfo(const QString&number);
};

#endif // GLOBAL_H
