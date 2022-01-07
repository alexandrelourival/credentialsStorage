#include "credentialswindow.h"
#include "ui_credentialswindow.h"
#include "registercredentialswindow.h"

CredentialsWindow::CredentialsWindow(QWidget *parent, QString username) :
    QDialog(parent),
    ui(new Ui::CredentialsWindow)
{
    ui->setupUi(this);
    ui->label_user->setText("User: "+username);
    QSqlQuery query_id;
    query_id.prepare("select User_ID from logins where username='"+username+"'");
    query_id.exec();
    query_id.next();
    QString id = query_id.value(0).toString();

    this->User_ID = id;
    attTable();
}

CredentialsWindow::~CredentialsWindow()
{
    delete ui;
}

void CredentialsWindow::on_pushButton_add_clicked()
{
    ui->label_password->clear();
    RegisterCredentialsWindow register_credentials_window(nullptr, this->User_ID);
    register_credentials_window.exec();
    attTable();
}


void CredentialsWindow::on_pushButton_remove_clicked()
{
    ui->label_password->clear();
    int row = ui->tableWidget->currentRow();
    QString website = ui->tableWidget->item(row,0)->text();
    QSqlQuery query_delete;

    query_delete.prepare("delete from logins_data where Website='"+website+"'");

    if(query_delete.exec()){
        QMessageBox::information(this,"Credential deleted","The credential was successfully deleted.");
    }else{
        QMessageBox::warning(this,"Error","Unable to delete this credential.");
    }

    attTable();
}

void CredentialsWindow::attTable()
{
    ui->tableWidget->clear();
    ui->label_password->clear();

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->tableWidget->setColumnWidth(0,275);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setHorizontalHeaderLabels(QString("Website;Username").split(";"));

    QSqlQuery query_credentials;

    query_credentials.prepare("select Website, Username from logins_data where User_ID = "+this->User_ID);

    if(query_credentials.exec()){
        int i = 0;
        while(query_credentials.next()){
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(query_credentials.value(0).toString()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(query_credentials.value(1).toString()));
            i++;
        }
    }else{
        QMessageBox::warning(this,"ERROR", "Error to get credentials!");
        return;
    }
}


void CredentialsWindow::on_tableWidget_itemSelectionChanged()
{
    ui->label_password->clear();
}


void CredentialsWindow::on_pushButton_get_clicked()
{
    int row = ui->tableWidget->currentRow();
    QString website = ui->tableWidget->item(row,0)->text();
    QSqlQuery query_password;

    query_password.prepare("select Password from logins_data where Website='"+website+"'");

    query_password.exec();
    query_password.next();
    QString password = query_password.value(0).toString();

    ui->label_password->setText(password);
    ui->pushButton_get->setEnabled(false);
}


void CredentialsWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->pushButton_get->setEnabled(true);
}

