#include "searchDlg.h"
#include "ui_searchDlg.h"
#include"global.h"
SearchDlg::SearchDlg(bool ifTotal,QWidget *parent)
    : QDialog(parent),m_ifTotal(ifTotal)
    , ui(new Ui::SearchDlg)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(0);
    setWindowTitle("查询信息");
}

SearchDlg::~SearchDlg()
{
    delete ui;
}

//搜索
void SearchDlg::on_pushButton_clicked()
{

    QString data=ui->lineEdit->text();
    if(m_ifTotal)
        Global::playerTableModel->search(ui->comboBox->currentIndex(),data);
    else
        Global::sessionTableModel->search(ui->comboBox->currentIndex(),data);
    accept();
}

