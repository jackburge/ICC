
#include "serialPorts.h"
#include "mainwindow.h"
#include <QtDebug>
//
SerialPorts::SerialPorts()
{
	port = new QextSerialPort(QLatin1String("/dev/ttyAMA0"), QextSerialPort::Polling);
	port->setBaudRate(BAUD115200);
	port->setFlowControl(FLOW_OFF);
	port->setParity(PAR_NONE);
	port->setDataBits(DATA_8);
	port->setStopBits(STOP_1);
	port->setTimeout(500);
	port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);
	m_numBytes = 0;
	m_packetBuild = false;
	m_buff[0] = '\0';
}

SerialPorts::~SerialPorts()
{
	port->close();
	delete port;
}

QString SerialPorts::readSerialPorts()
{
    char inch = 0;

    while(((m_numBytes = port->bytesAvailable()) > 0) && (inch != '}'))
	{
		port->read(&inch, 1);
		if(inch == '{')
		{
			m_charCount = 0;
			m_packetBuild = true;
		}
	
		if(m_packetBuild)
		{
			m_buff[m_charCount++] = inch;
			if(inch == '}')
			{
				m_buff[m_charCount] =  '\0';
				m_packetBuild = false;
			}
		}
	}
	QString msg;
	if(!m_packetBuild)
	{
		msg= QLatin1String(m_buff);
		m_buff[0] = '\0';
	}
//     qDebug() << "Serial Data: " << msg;
	return msg;	
}

void SerialPorts::transmitMsg(QString msg)
{
//	port->open(QIODevice::ReadWrite | QIODevice::Unbuffered);
	port->write(msg.toAscii(), msg.length());
    qDebug() << msg << "  " << msg.toAscii();
}
//
