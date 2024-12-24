#include "filterDlg.h"
#include "ui_filterDlg.h"

filterDialog::filterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::filterDialog)
{
    ui->setupUi(this);
    setWindowTitle("数据筛选");
}

filterDialog::~filterDialog()
{
    delete ui;
}

void filterDialog::on_buttonBox_accepted()
{
    filterDataSelect=ui->dataComboBox->currentText();//将筛选的数据格式存储到filterDialog类的公有成员中
    filterRuleSelect=ui->ruleComboBox->currentText();//将筛选的规则存储到filterDialog类的公有成员中
    filterCountSelect=ui->spinBox->value();//将筛选的个数存储到filterDialog类的公有成员中
    accept();
}

void filterDialog::setFilter(const QStringList &dataList, const QStringList &ruleList)
{
    ui->dataComboBox->addItems(dataList);//将dataList中所有的项添加到下拉表的项目中
    ui->dataComboBox->setCurrentIndex(0);//将下拉表dataComboBox的索引设为0，即缺省时选择下拉表的第1个项目

    ui->ruleComboBox->addItems(ruleList);
    ui->ruleComboBox->setCurrentIndex(0);
}

