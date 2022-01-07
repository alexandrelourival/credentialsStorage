#include "loginwindow.h"
#include "./ui_loginwindow.h"
#include "credentialswindow.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    QSqlDatabase DataBase = QSqlDatabase::addDatabase("QSQLITE");
    QString dir=qApp->applicationDirPath();
    QString banco=dir+"/Database/db_storage.db";


    DataBase.setDatabaseName(banco);

    if(!DataBase.open()){
        QMessageBox::warning(this,"Error", "Failed to open database");
        this->close();
        return;
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1==0){
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    }
    else{
        ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
    }
}



void LoginWindow::on_pushButton_login_clicked()
{
    this->username = ui->lineEdit_username->text();
    this->password = ui->lineEdit_password->text();

    QSqlQuery query;

    if(query.exec("select * from logins where username='"+this->username+"' and password='"+this->password+"'")){

        int count = 0;

        while(query.next()){
            count++;
        }

        if(count>0){

            this->hide();
            CredentialsWindow credentials_window(nullptr, username);
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
            credentials_window.setModal(true);
            credentials_window.exec();
            this->show();

        }
        else{
            ui->label->setText("Username/Password incorrect!");
            ui->lineEdit_username->clear();
            ui->lineEdit_password->clear();
        }
    }
    else{
        QMessageBox::warning(this,"Error", "Query failed!");
    }
}


void LoginWindow::on_pushButton_register_clicked()
{
    RegisterWindow register_window;
    register_window.exec();
}
