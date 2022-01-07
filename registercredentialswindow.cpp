#include "registercredentialswindow.h"
#include "ui_registercredentialswindow.h"

RegisterCredentialsWindow::RegisterCredentialsWindow(QWidget *parent, QString id) :
    QDialog(parent),
    ui(new Ui::RegisterCredentialsWindow)
{
    ui->setupUi(this);
    this->User_ID = id;
}

RegisterCredentialsWindow::~RegisterCredentialsWindow()
{
    delete ui;
}

void RegisterCredentialsWindow::on_pushButton_save_clicked()
{
    QString website = ui->lineEdit_site->text();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    QSqlQuery query_create;

    query_create.prepare("INSERT INTO logins_data (User_ID, Website, Username, Password) VALUES ("+this->User_ID+",'"+website+"','"+username+"','"+password+"')");


    if(query_create.exec()){
        QMessageBox::information(this,"Credential added","Credential has been successfully added.!");
        this->close();
    }
    else{
        QMessageBox::warning(this,"Error","This account cannot be created.");
    }

}


void RegisterCredentialsWindow::on_pushButton_cancel_clicked()
{
    this->close();
}
