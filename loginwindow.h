#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_login_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::LoginWindow *ui;
    QString password;
    QString username;
};
#endif // LOGINWINDOW_H
