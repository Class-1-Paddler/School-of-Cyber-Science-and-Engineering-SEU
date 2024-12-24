#include "sessionTableModel.h"
#include"global.h"
#include<QDebug>


//返回表头数据
QVariant SessionTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    //处理不满足预期的情况，增强健壮性
    if(havehHeader==false)//处理表头尚未设置的情况，增强程序的健壮性
        return  QVariant();
    if (role != Qt::DisplayRole)//如果请求的角色不是Qt::DisplayRole，也返回一个空的QVariant。
                                //通常表头的数据角色只有 Qt::DisplayRole是有意义的
        return QVariant();

    //开始处理符合预期的部分
    if (orientation == Qt::Vertical)//表头垂直，返回选中行的表头
        return section + 1;

    else if (orientation == Qt::Horizontal)//表头水平，返回列的表头
        return hHeaderList.at(section);//section给出了具体哪一列的表头

    else return QVariant();
}

//获取所需数据，role缺省状态下设置为DisplayRole，返回某单元格数据，当然通过对role的设置可以实现返回其它数据
QVariant SessionTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())//处理非预期情况（尽管不大可能出现）
        return QVariant();

    if(role==Qt::DisplayRole)//当role为一般的缺省时，返回所需的单元格信息
    {
        const SessionMessage& courseMessage=m_sessionVec.at(index.row());
        if(index.column()==0)
            return courseMessage.getNumber();//返回球员编号
        else if(index.column()==1)
            return courseMessage.getName();//返回球员姓名
        else if(index.column()==2)
            return courseMessage.getTeam();//返回球队名称
        else if(index.column()==3)
            return courseMessage.getNThreeCount();//返回本场三分
        else if(index.column()==4)
            return courseMessage.getNReboundCount();//返回本场篮板
        else if(index.column()==5)
            return courseMessage.getNDunkCount();//返回本场扣篮
        else if(index.column()==6)
            return courseMessage.getNBrokenCount();
        else if(index.column()==7)
            return courseMessage.getNScore();
        else if(index.column()==8)
            return courseMessage.getTime();
        else return QVariant();
    }//返回单元格信息结束，下面考虑其它情况
    //*************************这里采用switch-case语句疑更好

    else if(role==IdRole)
        return m_sessionVec.at(index.row()).getNumber();
    else if(role==CourseRole)
        return QVariant::fromValue(m_sessionVec.at(index.row()));
    else return QVariant();
}

//设置表头内容，注意只是通过QStringList设置了表头的内容，还没有具体地显示出来
void  SessionTableModel::setHorizontalHeader(const QStringList& headerList)
{
    hHeaderList=headerList;
    havehHeader=true;//设置为true
}


//返回场次信息
SessionMessage SessionTableModel::getSession(int row)
{
    return m_sessionVec.at(row);
}

//搜索场次信息，和playerTableModel中的差不多
void SessionTableModel::search(int index, const QString &data)
{
    switch(index)
    {
    case 0://球员编号
    {
        QVector<SessionMessage> temp;
        for(SessionMessage& iter:Global::SESSION_LIST)
        {
            if(iter.getNumber()==data){
                temp.push_back(iter);
            }
        }
        setData(temp);
        break;
    }

    case 1://球员姓名
    {
        QVector<SessionMessage> temp;
        for(SessionMessage& iter:Global::SESSION_LIST)
        {
            if(iter.getName()==data){
                temp.push_back(iter);
            }
        }
        setData(temp);
        break;
    }

    case 2://球队名称
    {
        QVector<SessionMessage> temp;
        for(SessionMessage& iter:Global::SESSION_LIST)
        {
            if(iter.getTeam()==data){
                temp.push_back(iter);
            }
        }
        setData(temp);
        break;
    }
    }

}

//删除场次信息，原理同player中的
void SessionTableModel::deleteSessions(const QModelIndexList &list)
{
    QVector<int> rowList;
    for(auto& iter:list)
    {
        rowList.push_back(iter.row());
    }
    QVector<SessionMessage>temp;
    for(int i=0;i<m_sessionVec.length();i++){
        if(!rowList.contains(i))
            temp.push_back(m_sessionVec.at(i));
        else
            Global::deleteSession(m_sessionVec.at(i).getNumber(),m_sessionVec.at(i).getTime());
    }
    setData(temp);
    Global::updatePalyers();
}

//设置某处的场次信息——用于修改场次信息的二级函数
void SessionTableModel::setSessionAt(int index, const SessionMessage &session)
{
    m_sessionVec[index]=session;
}

//添加场次信息并同时在视图中展示
void  SessionTableModel::addSession(const SessionMessage &course)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_sessionVec.push_back(course);
    endInsertRows();
}

//清空场次信息并同时在视图中清空
void  SessionTableModel::clearSession()
{
    beginResetModel();
    m_sessionVec.clear();
    endResetModel();
}


//z在视图上输出新数据
void SessionTableModel::setData(const QVector<SessionMessage>&playerVec_)
{
    beginResetModel();
    m_sessionVec=playerVec_;
    endResetModel();
}
