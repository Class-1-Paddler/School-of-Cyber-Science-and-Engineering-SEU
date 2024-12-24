#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"sessionmessageDlg.h"
#include"global.h"
#include<QFileDialog>
#include<QDesktopServices>
#include<QMessageBox>
#include"searchDlg.h"
#include"filterDlg.h"


//构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("篮球联赛个人技术管理系统@57223126");

    ui->stackedWidget->setCurrentIndex(0);//初始状态下显示第一个stackWdiget——球员总信息列表
    QStringList playerListHeader;
    playerListHeader<<"球员编号"<<"球员姓名"<<"球队名称"<<"三分球总数"<<"篮板总数"<<"扣篮总数"<<"抢断总数"<<"总得分";
    m_playerModel.setHorizontalHeader(playerListHeader);//设置球员总信息列表的表头
    QStringList sessionListHeader;
    sessionListHeader<<"球员编号"<<"球员姓名"<<"球队名称"<<"本场三分"<<"本场篮板"<<"本场扣篮"<<"本场抢断"<<"本场得分"<<"比赛时间";
    m_sessionModel.setHorizontalHeader(sessionListHeader);//设置场次详细信息列表的表头

    //设置两个QTableView控件的数据模型。
    ui->tableView->setModel(&m_playerModel);
    ui->tableView_2->setModel(&m_sessionModel);


    //表列随着表格变化而自适应变化
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //选中时设置整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setFocusPolicy(Qt::NoFocus);
    //设置固定行高
    ui->tableView->verticalHeader()->setDefaultSectionSize(70);
    ui->tableView->horizontalHeader()->setStyleSheet("background-color:#F2F2F2; color: #7D667D; border: 1px solid #6c6c6c;");

    //表列随着表格变化而自适应变化
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //选中时设置整行选中
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->setFocusPolicy(Qt::NoFocus);
    //设置固定行高
    ui->tableView_2->verticalHeader()->setDefaultSectionSize(70);
    ui->tableView_2->horizontalHeader()->setStyleSheet("background-color:#F2F2F2; color: #7D667D; border: 1px solid #6c6c6c;");

    Global::setPlayerModel(&m_playerModel);
    Global::setSessionModel(&m_sessionModel);


    //界面样式美化

}

MainWindow::~MainWindow()
{
    delete ui;
}

//详细场次列表：添加场次信息
void MainWindow::on_pushButton_8_clicked()
{
    SessionMessageDialog addDlg(this);
    connect(&addDlg,&SessionMessageDialog::addSessionMessage,this,&MainWindow::handleAddSessionMessage);
    connect(&addDlg,SessionMessageDialog::modifySessionMessage,this,&MainWindow::handleModifySessionMessage);
    addDlg.exec();
}

//详细场次列表：删除场次详细信息
void MainWindow::on_pushButton_10_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView_2->selectionModel();
    QModelIndexList indexList=  selectionModel->selectedRows();
    m_sessionModel.deleteSessions(indexList);
}

//球员总信息列表：添加场次
void MainWindow::on_pushButton_clicked()
{
    SessionMessageDialog addDlg(this);
    connect(&addDlg,&SessionMessageDialog::addSessionMessage,this,&MainWindow::handleAddSessionMessage);
    connect(&addDlg,SessionMessageDialog::modifySessionMessage,this,&MainWindow::handleModifySessionMessage);
    addDlg.exec();
}



//球员总列表：删除球员信息
void MainWindow::on_pushButton_3_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    QModelIndexList indexList=  selectionModel->selectedRows();
    m_playerModel.delPlayers(indexList);
}

//球员总列表：查询球员信息
void MainWindow::on_pushButton_4_clicked()
{
    SearchDlg dlg(true,this);
    dlg.exec();
}

//球员总信息列表:筛选球员信息
void MainWindow::on_pushButton_5_clicked()
{
    filterDialog dlg(this);
    QStringList dataList,ruleList;
    dataList<<"三分球"<<"篮板"<<"扣篮"<<"抢断";//注意为了和场次信息列表界面中的“筛选”按钮形成复用，故这里不区分是本场还是总数
    ruleList<<"升序（从小到大）"<<"降序（从大到小）";
    dlg.setFilter(dataList,ruleList);//在filterDialog界面的下拉框中设置筛选的方法
    if(dlg.exec()==QDialog::Rejected)
        return;
    else//进入筛选操作
    {
        int columnIndex;//要看是依据哪一列排序
        if(dlg.filterDataSelect=="三分球") columnIndex=0;
        else if(dlg.filterDataSelect=="篮板") columnIndex=1;
        else if(dlg.filterDataSelect=="扣篮") columnIndex=2;
        else if(dlg.filterDataSelect=="抢断") columnIndex=3;
        int m=dlg.filterCountSelect;//获取需要筛选的数据个数
        if(dlg.filterRuleSelect=="降序（从大到小）")
        {//step2:排序数据：降序
            m_playerModel.filter(columnIndex,false,m);
        }
        else
        {//step2:排序数据：升序
            m_playerModel.filter(columnIndex,true,m);
        }
    }
}

//球员总信息列表：刷新当前界面
void MainWindow::on_pushButton_6_clicked()
{
    m_playerModel.setDataInTable(Global::PLAYER_LIST);
    QMessageBox::information(this,"操作提示","刷新成功");
}

//球员总信息列表：跳转到详细场次列表
void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


//详细场次列表：修改选中场次信息
void MainWindow::on_pushButton_9_clicked()
{
    QItemSelectionModel *selectionModel = ui->tableView_2->selectionModel();
    if(selectionModel->selectedRows().isEmpty()){
        QMessageBox::warning(this,"error","未选中行!");
        return;
    }
    QModelIndex index=  selectionModel->selectedRows().first();
    SessionMessageDialog addDlg(this);
    addDlg.setData(m_sessionModel.getSession(index.row()),index.row(),m_sessionModel.getSession(index.row()).getTime());
    connect(&addDlg,&SessionMessageDialog::addSessionMessage,this,&MainWindow::handleAddSessionMessage);
    connect(&addDlg,SessionMessageDialog::modifySessionMessage,this,&MainWindow::handleModifySessionMessage);
    addDlg.exec();
}

//详细场次列表：查询
void MainWindow::on_pushButton_11_clicked()
{
    SearchDlg dlg(false,this);
    dlg.exec();

}


//详细场次列表：刷新功能
void MainWindow::on_pushButton_13_clicked()
{
    m_sessionModel.setData(Global::SESSION_LIST);
    QMessageBox::information(this,"操作提示","刷新成功");
}


void MainWindow::handleAddSessionMessage(const SessionMessage &session)
{
    Global::AddSession(session);
}

void MainWindow::handleModifySessionMessage(const SessionMessage &session,int row,const QDateTime&time)
{
    Global::ModifySession(session,row,time);
}

//菜单栏“文件”下拉：“打开场次信息存储文件”的槽函数
void MainWindow::on_action_triggered()
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString fullPath = filePath+"/"+playerFileName;
    QUrl fileUrl = QUrl::fromLocalFile(fullPath);
    QDesktopServices::openUrl(fileUrl);
}

//打开储存场次信息的文件
void MainWindow::on_action_2_triggered()
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString fullPath =filePath+"/"+sessionFileName;
    QUrl fileUrl = QUrl::fromLocalFile(fullPath);
    QDesktopServices::openUrl(fileUrl);
}

//导出全部信息到文件
void MainWindow::on_action_3_triggered()
{
    //首先选择目录
    QString dir=QFileDialog::getExistingDirectory();
    //创建
    bool res=Global::outPutToFile(dir+"/"+playerFileName,dir+"/"+sessionFileName);
    if(res)
    {
        QMessageBox::information(this,"success","保存成功!");
        filePath=dir;
    }
    else{
        QMessageBox::warning(this,"failure","保存失败!");
    }
}

//导入数据 球员文件和场次文件要求在同一个目录下面
void MainWindow::on_action_4_triggered()
{
    // 选择目录
    QString directory = QFileDialog::getExistingDirectory(this, tr("选择目录"));

    if (directory.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("未选择目录"));
        return;
    }

    // 设置文件路径
    QString playerFileNameFull = directory + "/"+playerFileName;
    QString sessionFileNameFull = directory + "/"+sessionFileName;

    // 判断目录下面是否存在 playerFileName 和 sessionFileName 两个文件
    QFileInfo playerFileInfo(playerFileNameFull);
    QFileInfo sessionFileInfo(sessionFileNameFull);

    if (!playerFileInfo.exists() || !sessionFileInfo.exists()) {
        QMessageBox::warning(this, tr("警告"), tr("目录下缺少必要的文件"));
        return;
    }
    bool res=Global::getDataFromFile(playerFileNameFull,sessionFileNameFull);
    if(res){
        filePath=directory;
        QMessageBox::information(this,"success","导入数据成功!");
    }
    else{
        QMessageBox::warning(this,"failure","导入数据失败!");
    }
}

//详细场次列表：转换到球员的总信息列表
void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//球员总信息列表：保存当前界面的数据到文件
void MainWindow::on_pushButton_12_clicked()
{
    // 选择目录
    QString directory = QFileDialog::getExistingDirectory(this, tr("选择目录"));

    if (directory.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("未选择目录"));
        return;
    }

    // 设置文件路径
    QString playerFileNameFull = directory + "/"+"filter_"+playerFileName;
    if(Global::FilteroutPutToFile(playerFileNameFull))
    {
        QMessageBox::information(this,"success","导出成功!");
    }
    else{
        QMessageBox::warning(this,"failure","导出失败!");
    }
}

