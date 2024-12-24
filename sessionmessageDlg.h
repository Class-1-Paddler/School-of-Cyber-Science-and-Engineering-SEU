#ifndef SESSIONMESSAGEDLG_H
#define SESSIONMESSAGEDLG_H

#include <QDialog>
#include"dataClass.h"


namespace Ui {
class SessionMessageDialog;
}

class SessionMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SessionMessageDialog(QWidget *parent = nullptr);
    ~SessionMessageDialog();
signals:
    void addSessionMessage(const SessionMessage&session);
    void modifySessionMessage(const SessionMessage&session,int row,const QDateTime&time);
private:
    Ui::SessionMessageDialog *ui;
    bool ifEdit=false;
    QDateTime time;
    int row=0;
public:
    SessionMessage objectSessionMessage;//在SessionMessageDialog对话框中显然最好存储一下SessionMessage信息，为方便起见，将数据成员设置为公有的（尽管这样并不安全）

public:
    void setData(const SessionMessage& objectSession);//将已有的数据填充到SessionMessageDialog的对话框中，便于后续“修改场次信息”的函数

      void setData(const SessionMessage& objectSession,int row,const QDateTime&time);
private slots:

    void on_submitPushButton_clicked();
    void on_cancelPushButton_clicked();

};

#endif // SESSIONMESSAGEDLG_H
