/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *passwordLabel;
    QLabel *titleLabel;
    QPushButton *loginButton;
    QLineEdit *usernameEntry;
    QLabel *usernameLabel;
    QLineEdit *passwordEntry;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(345, 215);
        passwordLabel = new QLabel(Login);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(40, 100, 61, 16));
        titleLabel = new QLabel(Login);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(120, 10, 111, 51));
        QFont font;
        font.setPointSize(14);
        titleLabel->setFont(font);
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(120, 130, 111, 31));
        usernameEntry = new QLineEdit(Login);
        usernameEntry->setObjectName(QString::fromUtf8("usernameEntry"));
        usernameEntry->setGeometry(QRect(120, 70, 111, 21));
        usernameLabel = new QLabel(Login);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setGeometry(QRect(40, 70, 71, 21));
        passwordEntry = new QLineEdit(Login);
        passwordEntry->setObjectName(QString::fromUtf8("passwordEntry"));
        passwordEntry->setGeometry(QRect(120, 100, 111, 21));
        QFont font1;
        font1.setPointSize(12);
        passwordEntry->setFont(font1);
        passwordEntry->setEchoMode(QLineEdit::Password);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Login", "Password:", nullptr));
        titleLabel->setText(QCoreApplication::translate("Login", "Admin Login", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "Login", nullptr));
        usernameLabel->setText(QCoreApplication::translate("Login", "Username:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
