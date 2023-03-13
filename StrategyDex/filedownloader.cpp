#include "filedownloader.h"
#include <iostream>

FileDownloader::FileDownloader(QUrl url, QObject *parent):
 QObject(parent)
{
    connect(&webController,SIGNAL(finished(QNetworkReply*)),this,SLOT(fileDownloaded(QNetworkReply*)));
    QNetworkRequest request(url);
    webController.get(request);
}

FileDownloader::~FileDownloader(){}

void FileDownloader::fileDownloaded(QNetworkReply* pReply){
    std::cout<<"Raw datas downloaded"<<std::endl;
    m_downloadedData = pReply->readAll();
    pReply->deleteLater();
    emit downloaded();
}

QByteArray FileDownloader::downloadedData() const {
    return m_downloadedData;
}
