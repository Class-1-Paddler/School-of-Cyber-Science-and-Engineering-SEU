#ifndef FILTERDLG_H
#define FILTERDLG_H

#include <QDialog>

namespace Ui {
class filterDialog;
}

class filterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit filterDialog(QWidget *parent = nullptr);
    ~filterDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::filterDialog *ui;


public:
    //设置两个下拉框中内容的函数
    void setFilter(const QStringList& dataList,const QStringList& ruleList);

public:
    QString filterDataSelect;//存储筛选的数据
    QString filterRuleSelect;//存储筛选的规则
    int filterCountSelect;//存储筛选的个数
};

#endif // FILTERDLG_H
