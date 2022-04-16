#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "ui_login.h"
//#include "adminwindow.h"

namespace Ui {
class Login : public Ui_login {};
}

/*!
 * \brief Admin login popup
 * Serves as a UI for the popup admin page, which serves as a way to authenticate a user as an administrator.
 */

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    //! getAdminStatus
    /*!
     * \brief Method to return whether user is admin or not
     * \return Returns value of data member admin
     */
    bool getAdminStatus();

private slots:
    void on_loginButton_clicked();

signals:
    void Admin();

private:
    Ui::Login *ui; /*!< UI of admin login screen */
    QString username; /*!< Encrypted username */
    QString password; /*!< Encrypted password */
    bool admin; /*!< Status of authentication */
    //AdminWindow* adminWindow;
};

#endif // LOGIN_H
