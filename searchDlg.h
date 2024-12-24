#ifndef SEARCHDLG_H
#define SEARCHDLG_H

#include <QDialog>
#include<QMessageBox>

namespace Ui {
class SearchDlg;
}

class SearchDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDlg(bool ifTotal,QWidget *parent = nullptr);
    ~SearchDlg();

private slots:
    void on_pushButton_clicked();

private:
    bool m_ifTotal=false;
    Ui::SearchDlg *ui;

// protected:
//     void helpRequested()  {
//         QMessageBox::information(this, "Information", "可以进行修改");
//     }
};

#endif // SEARCHDLG_H
