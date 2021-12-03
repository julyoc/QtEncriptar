#ifndef CRYPTO_H
#define CRYPTO_H

#include <QObject>
#include <QCryptographicHash>

class Crypto : public QObject
{
    Q_OBJECT
public:
    explicit Crypto(QObject *parent = nullptr);
    ~Crypto();

    void setTxt(QString txt);
    QString getTxt();
    void crypt(QCryptographicHash::Algorithm algth);
    QString getCryptoTxt();
    QCryptographicHash::Algorithm getAlgth();

private:
    QString txt;
    QCryptographicHash::Algorithm algth;
    QString cryptoTxt;

signals:

};

#endif // CRYPTO_H
