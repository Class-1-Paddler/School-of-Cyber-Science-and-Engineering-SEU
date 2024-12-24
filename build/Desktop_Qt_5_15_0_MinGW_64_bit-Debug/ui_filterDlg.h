/********************************************************************************
** Form generated from reading UI file 'filterDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDLG_H
#define UI_FILTERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_filterDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *dataComboBox;
    QComboBox *ruleComboBox;
    QSpinBox *spinBox;

    void setupUi(QDialog *filterDialog)
    {
        if (filterDialog->objectName().isEmpty())
            filterDialog->setObjectName(QString::fromUtf8("filterDialog"));
        filterDialog->resize(774, 467);
        filterDialog->setStyleSheet(QString::fromUtf8("background:\n"
"rgb(221, 227, 216)"));
        buttonBox = new QDialogButtonBox(filterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(440, 320, 241, 111));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(filterDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 90, 168, 31));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(filterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 150, 168, 31));
        label_2->setFont(font);
        label_3 = new QLabel(filterDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 210, 168, 31));
        label_3->setFont(font);
        dataComboBox = new QComboBox(filterDialog);
        dataComboBox->setObjectName(QString::fromUtf8("dataComboBox"));
        dataComboBox->setGeometry(QRect(290, 90, 271, 31));
        ruleComboBox = new QComboBox(filterDialog);
        ruleComboBox->setObjectName(QString::fromUtf8("ruleComboBox"));
        ruleComboBox->setGeometry(QRect(290, 150, 271, 31));
        spinBox = new QSpinBox(filterDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(290, 210, 271, 31));

        retranslateUi(filterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), filterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), filterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(filterDialog);
    } // setupUi

    void retranslateUi(QDialog *filterDialog)
    {
        filterDialog->setWindowTitle(QCoreApplication::translate("filterDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("filterDialog", "\347\255\233\351\200\211\346\225\260\346\215\256", nullptr));
        label_2->setText(QCoreApplication::translate("filterDialog", "\347\255\233\351\200\211\350\247\204\345\210\231", nullptr));
        label_3->setText(QCoreApplication::translate("filterDialog", "\347\255\233\351\200\211\346\225\260\347\233\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filterDialog: public Ui_filterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERDLG_H
