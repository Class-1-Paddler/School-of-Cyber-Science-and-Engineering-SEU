#include "sessionmessageDlg.h"
#include "ui_sessionmessageDlg.h"
#include<QMessageBox>

//**********************************************************
//**********************************************************
//**********************************************************
//为简单起见，添加场次信息和修改场次信息利用同一个UI界面
//**********************************************************
//**********************************************************
//**********************************************************
//**********************************************************


SessionMessageDialog::SessionMessageDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SessionMessageDialog)
{
    ui->setupUi(this);
    setWindowTitle("编辑场次信息");
    ui->sessionDateTimeEdit->setDateTime(QDateTime::currentDateTime());//将默认时间设置为实时时间
    ui->sessionDateTimeEdit->setCalendarPopup(true);//设置时间时弹出日历表

}

SessionMessageDialog::~SessionMessageDialog()
{
    delete ui;
}

void SessionMessageDialog::on_submitPushButton_clicked()
{
    //注意本段函数只实现读取对话框中的场次信息功能，至于将场次信息同步到球员信息在其他部分实现

    //读取球员编号信息
    objectSessionMessage.setNumber(ui->playerNumLineEdit->text().trimmed());
    //trimmed()是QString类方法，用于去除字符串前后多余的空白字符，确保在将文本传递给其他部分之前，空格不会引起问题。
    if(objectSessionMessage.getNumber().isEmpty())
    {//处理未输入球员编号的情况
        QMessageBox::information(this,"操作提示","请输入球员编号");
        return;
    }

    //读取球员姓名
    objectSessionMessage.setName(ui->playerNameLineEdit->text().trimmed());
    if(objectSessionMessage.getName().isEmpty())
    {
        QMessageBox::information(this,"操作提示","请输入球员姓名");
        return;
    }

    //读取球队名称
    objectSessionMessage.setTeam(ui->teamLineEdit->text().trimmed());
    if(objectSessionMessage.getTeam().isEmpty())
    {
        QMessageBox::information(this,"操作提示","请输入球队名称");
        return;
    }

    //读取本场次三分球、篮板、扣篮、抢断和总得分数据
    objectSessionMessage.setNThreeCount(ui->threeCountSpinBox->value());
    objectSessionMessage.setNReboundCount(ui->reboundCountSpinBox->value());
    objectSessionMessage.setNDunkCount(ui->dunkCountSpinBox->value());
    objectSessionMessage.setNBrokenCount(ui->brokenCountSpinBox->value());
    objectSessionMessage.setNScore(ui->scoreSpinBox->value());

    //读取本场次时间数据
    objectSessionMessage.setTime(ui->sessionDateTimeEdit->dateTime());
    if(ifEdit){
        emit modifySessionMessage(objectSessionMessage,row,time);
    }else{
        emit addSessionMessage(objectSessionMessage);
    }
    accept();//表示“确认”按钮被点击。accept()是父类的方法
}


void SessionMessageDialog::on_cancelPushButton_clicked()
{
    reject();//表示“取消”被点击，reject()是父类的方法
}


void SessionMessageDialog::setData(const SessionMessage& objectSessionMessage,int row,const QDateTime&time)
{
    this->time=time;
    this->row=row;
    this->objectSessionMessage=objectSessionMessage;
    //球员的编号、姓名、球队等自身信息不可修改，设置权限
    ui->playerNumLineEdit->setReadOnly(true);
    ui->playerNameLineEdit->setReadOnly(true);
    ui->teamLineEdit->setReadOnly(true);
    //读取全部数据
    ui->playerNumLineEdit->setText(objectSessionMessage.getNumber());
    ui->playerNameLineEdit->setText(objectSessionMessage.getName());
    ui->teamLineEdit->setText(objectSessionMessage.getTeam());

    ui->threeCountSpinBox->setValue(objectSessionMessage.getNThreeCount());
    ui->reboundCountSpinBox->setValue(objectSessionMessage.getNReboundCount());
    ui->scoreSpinBox->setValue(objectSessionMessage.getNScore());
    ui->brokenCountSpinBox->setValue(objectSessionMessage.getNBrokenCount());
    ui->dunkCountSpinBox->setValue(objectSessionMessage.getNDunkCount());
    ifEdit=true;
}
