#include "filedownloader.h"

FileDownloader::FileDownloader(QUrl imageUrl, QObject *parent):
 QObject(parent)
{
    connect(&webController,SIGNAL(finished(QNetworkReply*)),this,SLOT(fileDownloaded(QNetworkReply*)));
    QNetworkRequest request(imageUrl);
    webController.get(request);
}

FileDownloader::~FileDownloader(){}

void FileDownloader::fileDownloaded(QNetworkReply* pReply){
    m_downloadedData = pReply->readAll();
    pReply->deleteLater();
    emit downloaded();
}

QByteArray FileDownloader::downloadedData() const {
    return m_downloadedData;
}
