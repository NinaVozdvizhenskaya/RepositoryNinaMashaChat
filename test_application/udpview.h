#ifndef UDPVIEW_H
#define UDPVIEW_H

#include <QMainWindow>
#include "clientudp.h"
#include "serverudp.h"

namespace Ui {
class UDPView;
}

class UDPView : public QMainWindow
{
    Q_OBJECT

public:
    explicit UDPView(  QWidget *parent = 0);
    ~UDPView();
public slots:
     void set_input_message(QString mesa);
   //  void set_input_message_cl(QString mesa);
    void show_(QHostAddress _server, int _port, QString _nick_name);
private slots:
    void on_SendButton_2_clicked();

    void on_MessagelineEdit_2_textChanged(const QString &arg1);


    void on_MessagelineEdit_2_textEdited(const QString &arg1);

    //void on_MessagelineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_checkBox_2_clicked(bool checked);
public :
    ClientUDP * client;
    ServerUDP * server;
private:
    Ui::UDPView *ui;

    QHostAddress adr;
    int port;
    QString nick_name;


};

#endif // UDPVIEW_H
