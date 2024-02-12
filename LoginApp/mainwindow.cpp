#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("D:/c++/examples/LoginApp/login.png");
    ui->label_image->setPixmap(pix.scaled(ui->label_image->width(),ui->label_image->height(),Qt::KeepAspectRatio));

    this->setStyleSheet("background-color: lightblue;");
    ui->groupBox->setStyleSheet("border:1px solid gray;");
    ui->groupBox->setStyleSheet("title{subcontrol-origin: margin;subcontrol-position:top center;padding:0 3px;}");
    ui->btnLogin->setStyleSheet("QPushButton:enabled { background-color: gray; }\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "admin" && password == "test")
    {
        QMessageBox::information(this,"Login Succesful","Username and Password is correct!");
        ui->btnLogin->setStyleSheet("QPushButton:enabled { background-color: green; }\n");
        hide();
        secDialog = new SecDialog(this);
        secDialog->show();
    }
    else if(username == password)
    {
        QMessageBox::warning(this,"Login warning", "Username and Password can not be same!Try Again");
        ui->lineEdit_password->clear();
        ui->lineEdit_username->clear();
        ui->btnLogin->setStyleSheet("QPushButton:enabled { background-color: gray; }\n");
    }
    else
    {
        QMessageBox::critical(this,"Login Error", "Username or Password is wrong!");
        ui->btnLogin->setStyleSheet("QPushButton:enabled { background-color: red; }\n");
        ui->lineEdit_password->clear();
        ui->lineEdit_username->clear();
    }
}

