#ifndef CREDENTIALSWINDOW_H
#define CREDENTIALSWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QTableWidget>

namespace Ui {
class CredentialsWindow;
}

class CredentialsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CredentialsWindow(QWidget *parent = nullptr, QString username = NULL);
    ~CredentialsWindow();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void attTable();

    void on_tableWidget_itemSelectionChanged();

    void on_pushButton_get_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::CredentialsWindow *ui;
    QString User_ID;
};

#endif // CREDENTIALSWINDOW_H
