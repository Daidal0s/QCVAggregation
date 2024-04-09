#include "Hash.h"

QByteArray Hash::hash(QString&& text2hash)
{
    if (text2hash == QString(""))
        return QByteArray();
    
    QCryptographicHash hashGen(QCryptographicHash::Sha512);

    hashGen.addData(text2hash.toUtf8());

    QByteArray hash = hashGen.result().toHex();

    return hash;
}