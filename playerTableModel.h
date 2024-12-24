#ifndef PLAYERTABLEMODEL_H
#define PLAYERTABLEMODEL_H


#include <QAbstractTableModel>
#include"dataClass.h"

//本段主要实现球员信息列表的相关处理

class PlayerTableModel : public QAbstractTableModel
{
    Q_OBJECT

    //********************************************
    //数据成员
public:
    QVector<Player> m_playerVec;//存放球员信息的容器，声明为公有权限是没有办法的办法
public:
    enum Roles {
        IdRole=Qt::UserRole+1,
        CourseRole
    };//在 Qt 的模型/视图框架中，enum Roles 是一个用于定义自定义角色的枚举。这个枚举主要用于在自定义的 QAbstractItemModel
        //或 QAbstractListModel 中标识不同的数据角色，以便模型和视图可以正确地访问和显示数据。具体来说：
        //IdRole=Qt::UserRole+1：Qt::UserRole 是一个基于 Qt 的预定义角色的起始值。
        //Qt::UserRole 是一个预留的角色值，允许你在此基础上定义自己的角色。
        //IdRole 的值是 Qt::UserRole 加 1，这样可以确保它不会与 Qt 预定义的角色冲突。你可以将 IdRole 用于标识某种特定的数据，
        //比如项的唯一标识符。CourseRole：这个枚举成员也是一个自定义角色的标识符，你可以根据需要为其分配具体的值（比如 Qt::UserRole+2）
        //它用于标识模型中的另一种特定数据，例如课程相关的信息。
private:
    bool havehHeader=false;//判断是否设置了抬头（缺省时显然为否）
    QStringList hHeaderList;//表头的QString串


    //********************************************
    //成员函数
public:

    //构造函数
    PlayerTableModel(QObject* parent=nullptr):QAbstractTableModel(parent){};

    //返回表头数据，注意是RTTI，需要覆盖
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    //计算表格个多少行
    int rowCount(const QModelIndex& = QModelIndex()) const override{return m_playerVec.length();};

    //计算表格列数
    int columnCount(const QModelIndex&  = QModelIndex()) const override{return hHeaderList.length();}

    //显示表头内容，注意只是通过QStringList设置了表头的内容，还没有具体地显示出来
    void setHorizontalHeader(const QStringList&);

    //获取所需数据，role缺省状态下设置为DisplayRole，返回某单元格数据，当然通过对role的设置可以实现返回其它数据
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    //返回类型采用QVariant是为了与基类方法形成覆盖，此外QVariant还支持了更多种的返回类型

    //获取所需行的Player对象
    Player getPlayer(int row)const;

    //查询球员信息
    void search(int index,const QString& data);

    //在视图上输出新的数据
    void setDataInTable(const QVector<Player>& newVirtualPlayerVec);

    //删除整条球员的信息
    void delPlayers(const QModelIndexList& needDellist);

    //进行球员信息的筛选
    void filter(int index,bool ifUp,int num);


    //槽函数
public slots:
    //添加新的球员信息，容器和视图同步添加
    void addPlayer(const Player&) ;

    //清除球员信息，容器和视图中同步清除
    void clearPlayer();


signals:
    void addSuccess();//发布课程成功
    void addFailure(const QString&detail);//发布课程失败 参数为错误信息

};




#endif // PLAYERTABLEMODEL_H
