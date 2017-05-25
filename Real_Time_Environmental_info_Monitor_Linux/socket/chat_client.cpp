#include "chat_client.h"  
#include <QHostAddress>  
  
ChatClient::ChatClient( QObject *parent /* = NULL */ )  
    : QTcpSocket( parent )  
{  
    connect( this, SIGNAL(readyRead()), this, SLOT(OnReadyRead()) );  
    connect( this, SIGNAL(connected()), this, SLOT(OnConnected()) );  
}  
  
ChatClient::~ChatClient()  
{  
}  
  
void ChatClient::ConnectToServer( QString ip, quint16 port )
{  
    QString strip( ip );
    QHostAddress addr;  
    addr.setAddress( strip );  
    connectToHost( addr, port );  
}  
  
void ChatClient::Close()  
{  
    disconnectFromHost();  
    close();  
}  
  
//bool ChatClient::WriteData( const char *data, qint64 len )  
bool ChatClient::WriteData( const QByteArray & data )
{  
    //if(data)//检测数据不为空
    qint64 ret = write( data );

    if( 0 >= ret )  
        return false;  

    if(waitForBytesWritten( -1 )){                  // why ?
        printf("write result ret = %d\n",ret);      //显示发送数据的字节个数
        for(int i=0;i<12;i++)
        {
            printf("send data[%d]=%d\n",i,(int)data[i]);
        }
        waitForReadyRead( -1 );
        return true;
    }
    else{
        printf("send failed !\n");
        return false;
    }
    //waitForReadyRead( -1 );                     // why ?
}

bool ChatClient::checkConnectSate()
{
    this->isOpen();
}
  
void ChatClient::ParseData( const char *data, qint64 len )  
{  
    ;//printf( "receive data: %s\n", data );
}  
  
void ChatClient::OnReadyRead()  
{  
    char data[BUFFERSIZE_MAX] = { 0 };  
    qint64 len = read( data, BUFFERSIZE_MAX );
    if( len <= 0 )  
        return;  
    else  
        ParseData( data, len );  
}  
  
void ChatClient::OnConnected()  
{  
    printf( "connected: %d !\n", socketDescriptor() );  
}  
