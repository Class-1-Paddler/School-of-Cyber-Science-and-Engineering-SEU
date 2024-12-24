#ifndef SESSIONTABLEMODEL_H
#define SESSIONTABLEMODEL_H

#include <QAbstractTableModel>
#include"dataClass.h"

class SessionTableModel : public QAbstractTableModel
{
    Q_OBJECT

//***********************************
//数据成员
private:
    bool havehHeader=false;//和playerTableModel类一样，用于记载是否设置了表头

    QVector<SessionMessage>m_sessionVec;//存储场次信息列表，这里暂时放在私有权限中还没有出现问题

    QStringList hHeaderList;//表头的QString串

public:
    enum Roles {
        IdRole=Qt::UserRole+1,
        CourseRole
    };

//*********************************
//成员函数
public:

    //构造函数，通过explicit防止隐式转换
    explicit SessionTableModel(QObject *parent = nullptr):QAbstractTableModel(parent){};


    //返回表头数据
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    //返回表格的行数
    int rowCount(const QModelIndex& = QModelIndex()) const override
    {
        return m_sessionVec.length();
    }//这个函数很简单，直接用内联函数就行

    //返回表格的列数
    int columnCount(const QModelIndex& = QModelIndex()) const override
    {
        return hHeaderList.length();
    }

    //获取所需数据，role缺省状态下设置为DisplayRole，返回某单元格数据，当然通过对role的设置可以实现返回其它数据
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    //设置表头内容，注意只是通过QStringList设置了表头的内容，还没有具体地显示出来
    void setHorizontalHeader(const QStringList&);

    //返回场次信息
    SessionMessage getSession(int row);

    //查询场次信息
    void search(int index,const QString& data);

    //删除场次信息
    void deleteSessions(const QModelIndexList&list);

    //设置某处的场次信息——用于修改场次信息的二级函数
    void setSessionAt(int index,const SessionMessage&session);



public slots:
    void addSession(const SessionMessage&session) ;//添加场次信息并同时在视图中展示
    void clearSession();//清空场次信息并同时在视图中清空
    void setData(const QVector<SessionMessage>&sessionVec_);
    //z在视图上输出新数据





signals:
    void addSuccess();//发布课程成功
    void addFailure(const QString&detail);//发布课程失败 参数为错误信息

};


#endif // SESSIONTABLEMODEL_H
