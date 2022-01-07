#ifndef REGISTERCREDENTIALSWINDOW_H
#define REGISTERCREDENTIALSWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class RegisterCredentialsWindow;
}

class RegisterCredentialsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterCredentialsWindow(QWidget *parent = nullptr, QString id = NULL);
    ~RegisterCredentialsWindow();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::RegisterCredentialsWindow *ui;
    QString User_ID;
};

#endif // REGISTERCREDENTIALSWINDOW_H
