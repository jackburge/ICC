#ifndef SERIALPORTS_H
#define SERIALPORTS_H

#include <QMainWindow>
#include "qextserialport/src/qextserialport.h"

class QextSerialPort;

class SerialPorts
{

public:
    SerialPorts();
    ~SerialPorts();
	QString readSerialPorts();
	void transmitMsg(QString);	
private:
	QextSerialPort *port;
	int m_numBytes;
    char m_buff[128];
	bool m_packetBuild;
	bool m_packetBuilt;
	int m_charCount;
};
#endif
