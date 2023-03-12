#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H


#include <QObject>
#include <QByteArray>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

class FileDownloader : public QObject
{
    Q_OBJECT
public:
    explicit FileDownloader(QUrl imageurl,QObject *parent = nullptr);
    virtual ~FileDownloader();
    QByteArray downloadedData() const;

signals:
    void downloaded();

private slots:
    void fileDownloaded(QNetworkReply* pReply);
private :
    QNetworkAccessManager webController;
    QByteArray m_downloadedData;

};
#endif // FILEDOWNLOADER_H
