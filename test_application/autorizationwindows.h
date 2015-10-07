#ifndef AUTORIZATIONWINDOWS_H
#define AUTORIZATIONWINDOWS_H

#include <QMainWindow>
#include <QHostAddress>
#include "udpview.h"

namespace Ui {
class AutorizationWindows;
}

class AutorizationWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit AutorizationWindows(QWidget *parent = 0);
    ~AutorizationWindows();
    QHostAddress get_server();
    int get_port();
    QString get_nickneme();



signals:
    void exit_(QHostAddress _server, int _port, QString _nick_name);

private slots:


    void on_server_editingFinished();
    void on_nickname_editingFinished();
    void on_spinBox_editingFinished();
    void on_connect_clicked();


signals:
    void closed_();


private:
    Ui::AutorizationWindows *ui;

    QWidget *parent;
    QHostAddress server;
    QString nick_name;
    int port;
    bool isServer;

};

#endif // AUTORIZATIONWINDOWS_H
