#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crypto.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_submit_clicked()
{
    Crypto crp;
    crp.setTxt(this->ui->texto->toPlainText());
    if (this->ui->md4->isChecked()) crp.crypt(QCryptographicHash::Md4);
    if (this->ui->md5->isChecked()) crp.crypt(QCryptographicHash::Md5);
    if (this->ui->sha1->isChecked()) crp.crypt(QCryptographicHash::Sha1);
    if (this->ui->sha224->isChecked()) crp.crypt(QCryptographicHash::Sha224);
    if (this->ui->sha512->isChecked()) crp.crypt(QCryptographicHash::Sha512);
    if (this->ui->sha256->isChecked()) crp.crypt(QCryptographicHash::Sha256);
    if (this->ui->sha3_512->isChecked()) crp.crypt(QCryptographicHash::Sha3_512);
    this->ui->textoEncriptado->setPlainText(crp.getCryptoTxt());
    QTextStream(stdout) << crp.getTxt() << "\n" << crp.getCryptoTxt() << "\n\n";
}
