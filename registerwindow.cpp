#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString confirm_password = ui->lineEdit_confirm_password->text();

    if(password == confirm_password)
    {
        QSqlQuery query_create;

        query_create.prepare("INSERT INTO logins (Username, Password) VALUES ('"+username+"','"+username+"')");


        if(query_create.exec()){
            QMessageBox::information(this,"Account Created","The user was registered successfully!");
            this->close();
        }
        else{
            ui->label->setText("Error: This account cannot be created.");
        }
    }
    else{
        ui->label->setText("Passwords don't match");
        ui->lineEdit_confirm_password->clear();
        ui->lineEdit_password->clear();
    }

}



void RegisterWindow::on_pushButton_cancel_clicked()
{
    this->close();
}

