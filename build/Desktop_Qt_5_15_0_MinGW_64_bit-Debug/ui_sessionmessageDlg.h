/********************************************************************************
** Form generated from reading UI file 'sessionmessageDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SESSIONMESSAGEDLG_H
#define UI_SESSIONMESSAGEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SessionMessageDialog
{
public:
    QWidget *layoutWidget;
    QGridLayout *SessionMessageDailogGridLayout;
    QLabel *dunkCountLabel;
    QSpinBox *dunkCountSpinBox;
    QLabel *scoreLabel;
    QSpinBox *brokenCountSpinBox;
    QSpinBox *scoreSpinBox;
    QLabel *reboundCountLabel;
    QSpinBox *threeCountSpinBox;
    QLabel *sessionTimeLabel;
    QSpinBox *reboundCountSpinBox;
    QLabel *playerNumLabel;
    QLabel *brokenCountLabel;
    QLabel *TeamLabel;
    QDateTimeEdit *sessionDateTimeEdit;
    QLineEdit *playerNameLineEdit;
    QLineEdit *playerNumLineEdit;
    QLabel *playerNameLabel;
    QLabel *threeCountLabel;
    QLineEdit *teamLineEdit;
    QPushButton *submitPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *SessionMessageDialog)
    {
        if (SessionMessageDialog->objectName().isEmpty())
            SessionMessageDialog->setObjectName(QString::fromUtf8("SessionMessageDialog"));
        SessionMessageDialog->resize(516, 633);
        SessionMessageDialog->setStyleSheet(QString::fromUtf8("background-color:rgb(221, 227, 216)"));
        layoutWidget = new QWidget(SessionMessageDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 100, 411, 511));
        SessionMessageDailogGridLayout = new QGridLayout(layoutWidget);
        SessionMessageDailogGridLayout->setObjectName(QString::fromUtf8("SessionMessageDailogGridLayout"));
        SessionMessageDailogGridLayout->setContentsMargins(0, 0, 0, 0);
        dunkCountLabel = new QLabel(layoutWidget);
        dunkCountLabel->setObjectName(QString::fromUtf8("dunkCountLabel"));

        SessionMessageDailogGridLayout->addWidget(dunkCountLabel, 12, 0, 2, 1);

        dunkCountSpinBox = new QSpinBox(layoutWidget);
        dunkCountSpinBox->setObjectName(QString::fromUtf8("dunkCountSpinBox"));

        SessionMessageDailogGridLayout->addWidget(dunkCountSpinBox, 12, 1, 2, 1);

        scoreLabel = new QLabel(layoutWidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));

        SessionMessageDailogGridLayout->addWidget(scoreLabel, 16, 0, 2, 1);

        brokenCountSpinBox = new QSpinBox(layoutWidget);
        brokenCountSpinBox->setObjectName(QString::fromUtf8("brokenCountSpinBox"));

        SessionMessageDailogGridLayout->addWidget(brokenCountSpinBox, 14, 1, 2, 1);

        scoreSpinBox = new QSpinBox(layoutWidget);
        scoreSpinBox->setObjectName(QString::fromUtf8("scoreSpinBox"));

        SessionMessageDailogGridLayout->addWidget(scoreSpinBox, 16, 1, 2, 1);

        reboundCountLabel = new QLabel(layoutWidget);
        reboundCountLabel->setObjectName(QString::fromUtf8("reboundCountLabel"));

        SessionMessageDailogGridLayout->addWidget(reboundCountLabel, 10, 0, 2, 1);

        threeCountSpinBox = new QSpinBox(layoutWidget);
        threeCountSpinBox->setObjectName(QString::fromUtf8("threeCountSpinBox"));

        SessionMessageDailogGridLayout->addWidget(threeCountSpinBox, 8, 1, 2, 1);

        sessionTimeLabel = new QLabel(layoutWidget);
        sessionTimeLabel->setObjectName(QString::fromUtf8("sessionTimeLabel"));

        SessionMessageDailogGridLayout->addWidget(sessionTimeLabel, 6, 0, 2, 1);

        reboundCountSpinBox = new QSpinBox(layoutWidget);
        reboundCountSpinBox->setObjectName(QString::fromUtf8("reboundCountSpinBox"));

        SessionMessageDailogGridLayout->addWidget(reboundCountSpinBox, 10, 1, 2, 1);

        playerNumLabel = new QLabel(layoutWidget);
        playerNumLabel->setObjectName(QString::fromUtf8("playerNumLabel"));

        SessionMessageDailogGridLayout->addWidget(playerNumLabel, 0, 0, 2, 1);

        brokenCountLabel = new QLabel(layoutWidget);
        brokenCountLabel->setObjectName(QString::fromUtf8("brokenCountLabel"));

        SessionMessageDailogGridLayout->addWidget(brokenCountLabel, 14, 0, 2, 1);

        TeamLabel = new QLabel(layoutWidget);
        TeamLabel->setObjectName(QString::fromUtf8("TeamLabel"));

        SessionMessageDailogGridLayout->addWidget(TeamLabel, 4, 0, 2, 1);

        sessionDateTimeEdit = new QDateTimeEdit(layoutWidget);
        sessionDateTimeEdit->setObjectName(QString::fromUtf8("sessionDateTimeEdit"));

        SessionMessageDailogGridLayout->addWidget(sessionDateTimeEdit, 6, 1, 2, 2);

        playerNameLineEdit = new QLineEdit(layoutWidget);
        playerNameLineEdit->setObjectName(QString::fromUtf8("playerNameLineEdit"));

        SessionMessageDailogGridLayout->addWidget(playerNameLineEdit, 2, 1, 2, 2);

        playerNumLineEdit = new QLineEdit(layoutWidget);
        playerNumLineEdit->setObjectName(QString::fromUtf8("playerNumLineEdit"));

        SessionMessageDailogGridLayout->addWidget(playerNumLineEdit, 0, 1, 2, 2);

        playerNameLabel = new QLabel(layoutWidget);
        playerNameLabel->setObjectName(QString::fromUtf8("playerNameLabel"));

        SessionMessageDailogGridLayout->addWidget(playerNameLabel, 2, 0, 2, 1);

        threeCountLabel = new QLabel(layoutWidget);
        threeCountLabel->setObjectName(QString::fromUtf8("threeCountLabel"));

        SessionMessageDailogGridLayout->addWidget(threeCountLabel, 8, 0, 2, 1);

        teamLineEdit = new QLineEdit(layoutWidget);
        teamLineEdit->setObjectName(QString::fromUtf8("teamLineEdit"));

        SessionMessageDailogGridLayout->addWidget(teamLineEdit, 4, 1, 2, 2);

        submitPushButton = new QPushButton(layoutWidget);
        submitPushButton->setObjectName(QString::fromUtf8("submitPushButton"));

        SessionMessageDailogGridLayout->addWidget(submitPushButton, 18, 1, 1, 1);

        cancelPushButton = new QPushButton(layoutWidget);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        SessionMessageDailogGridLayout->addWidget(cancelPushButton, 18, 2, 1, 1);


        retranslateUi(SessionMessageDialog);

        QMetaObject::connectSlotsByName(SessionMessageDialog);
    } // setupUi

    void retranslateUi(QDialog *SessionMessageDialog)
    {
        SessionMessageDialog->setWindowTitle(QCoreApplication::translate("SessionMessageDialog", "Dialog", nullptr));
        dunkCountLabel->setText(QCoreApplication::translate("SessionMessageDialog", "\346\211\243\347\257\256\346\254\241\346\225\260", nullptr));
        scoreLabel->setText(QCoreApplication::translate("SessionMessageDialog", "\346\234\254\345\234\272\345\276\227\345\210\206", nullptr));
        reboundCountLabel->setText(QCoreApplication::translate("SessionMessageDialog", "\347\257\256\346\235\277\344\270\252\346\225\260", nullptr));
        sessionTimeLabel->setText(QCoreApplication::translate("SessionMessageDialog", "\346\257\224\350\265\233\346\227\266\351\227\264", nullptr));
        playerNumLabel->setText(QCoreApplication::translate("SessionMessageDialog", "\347\220\203\345\221\230\347\274\226\345\217\267", nullptr));
        brokenCountLabel->setText(QCoreApplication::translate("SessionMessageDialog", "\346\212\242\346\226\255\346\254\241\346\225\260", nullptr));
        TeamLabel->setText(QCoreApplication::translate("SessionMessageDialog", "\347\220\203\351\230\237\345\220\215\347\247\260", nullptr));
        playerNameLabel->setText(QCoreApplication::translate("SessionMessageDialog", "\347\220\203\345\221\230\345\247\223\345\220\215", nullptr));
        threeCountLabel->setText(QCoreApplication::translate("SessionMessageDialog", "\344\270\211\345\210\206\347\220\203\344\270\252\346\225\260", nullptr));
        submitPushButton->setText(QCoreApplication::translate("SessionMessageDialog", "\346\217\220\344\272\244", nullptr));
        cancelPushButton->setText(QCoreApplication::translate("SessionMessageDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SessionMessageDialog: public Ui_SessionMessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SESSIONMESSAGEDLG_H
