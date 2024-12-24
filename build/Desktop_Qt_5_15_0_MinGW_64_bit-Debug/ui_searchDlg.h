/********************************************************************************
** Form generated from reading UI file 'searchDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDLG_H
#define UI_SEARCHDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SearchDlg
{
public:
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *SearchDlg)
    {
        if (SearchDlg->objectName().isEmpty())
            SearchDlg->setObjectName(QString::fromUtf8("SearchDlg"));
        SearchDlg->resize(673, 383);
        SearchDlg->setStyleSheet(QString::fromUtf8("background-color:\n"
"rgb(221, 227, 216)"));
        comboBox = new QComboBox(SearchDlg);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 120, 151, 41));
        lineEdit = new QLineEdit(SearchDlg);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 120, 391, 41));
        pushButton = new QPushButton(SearchDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 260, 201, 61));

        retranslateUi(SearchDlg);

        QMetaObject::connectSlotsByName(SearchDlg);
    } // setupUi

    void retranslateUi(QDialog *SearchDlg)
    {
        SearchDlg->setWindowTitle(QCoreApplication::translate("SearchDlg", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SearchDlg", "\347\220\203\345\221\230\347\274\226\345\217\267", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SearchDlg", "\347\220\203\345\221\230\345\220\215\347\247\260", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("SearchDlg", "\347\220\203\351\230\237\345\220\215\347\247\260", nullptr));

        pushButton->setText(QCoreApplication::translate("SearchDlg", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDlg: public Ui_SearchDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDLG_H
