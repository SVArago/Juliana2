#ifndef JULIANA2_H_
#define JULIANA2_H_

#include <QObject>
#include <QWebSocketServer>
#include <QWebSocket>

#include "nfc_thread.h"

class Juliana2 : public QObject
{
	Q_OBJECT

public:
	explicit Juliana2();
	void setup();

private slots:
	void onNewConnection();
	void onSocketDisconnected();
	void onCardScanned(QByteArray, QByteArray, QByteArray);

private:
	QWebSocketServer *server;
	QList<QWebSocket *> clients;
	NfcThread *nfcThread;
	QString eventMessage;
};

#endif