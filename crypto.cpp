#include "crypto.h"

Crypto::Crypto(QObject *parent) : QObject(parent)
{

}

Crypto::~Crypto() {
    this->txt.~QString();
    this->cryptoTxt.~QString();
}

QString Crypto::getTxt() {
    return this->txt;
}

void Crypto::setTxt(QString txt) {
    this->txt = txt;
}

void Crypto::crypt(QCryptographicHash::Algorithm algth) {
    this->algth = algth;
    QByteArray barr;
    //barr.fromStdString(this->txt.toStdString());
    barr.contains(this->txt.toStdString());
    this->cryptoTxt = QString(QCryptographicHash::hash(barr, algth).toHex());
    barr.~QByteArray();
}

QString Crypto::getCryptoTxt() {
    return this->cryptoTxt;
}

QCryptographicHash::Algorithm Crypto:: getAlgth() {
    return this->algth;
}

