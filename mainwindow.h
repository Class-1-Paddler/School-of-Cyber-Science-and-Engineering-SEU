#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"playerTableModel.h"
#include"sessionTableModel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


private:
    Ui::MainWindow *ui;
    QString filePath="";//设置保存文件的路径
    QString playerFileName="playerList.txt";
    QString sessionFileName="sessionList.txt";
    SessionTableModel m_sessionModel;
    PlayerTableModel m_playerModel;



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots://相应按钮的槽函数

    //****************************************************
    //两个界面的pushButton按钮的槽函数
    void on_pushButton_clicked();//球员总信息列表：添加场次信息
    void on_pushButton_2_clicked();//详细场次列表：转到球员总信息列表
    void on_pushButton_3_clicked();//球员总列表：删除球员信息
    void on_pushButton_4_clicked();//球员总信息列表，查询球员信息
    void on_pushButton_5_clicked();//球员总信息列表:筛选球员信息
    void on_pushButton_6_clicked();//球员总信息列表：刷新当前界面
    void on_pushButton_7_clicked();//球员总信息列表：跳转到详细场次列表
    void on_pushButton_8_clicked();//详细场次列表：添加场次信息
    void on_pushButton_9_clicked();//详细场次列表：修改选中场次信息
    void on_pushButton_10_clicked();//详细场次列表：删除场次详细信息
    void on_pushButton_11_clicked();//详细场次列表：查询
    void on_pushButton_12_clicked();//球员总信息列表：保存当前界面的数据到文件
    void on_pushButton_13_clicked();//详细场次列表：刷新功能


    //****************************************************
    //菜单栏相关action的槽函数
    void on_action_triggered();//菜单栏“文件”下拉：“打开场次信息存储文件”的槽函数
    void on_action_2_triggered();//打开储存场次信息的文件
    void on_action_3_triggered();//导出全部信息到文件
    void on_action_4_triggered();//导入数据 球员文件和场次文件要求在同一个目录下面




    void handleAddSessionMessage(const SessionMessage&session);
    void handleModifySessionMessage(const SessionMessage&session,int row,const QDateTime&time);


};
#endif // MAINWINDOW_H
