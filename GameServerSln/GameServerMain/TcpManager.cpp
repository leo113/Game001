// TestServer.cpp: implementation of the TestServer class.
//
//////////////////////////////////////////////////////////////////////

#include "TcpManager.h"
#include <stdio.h>
#include <string.h>
#include "ProtocolManager.h"

#ifndef WIN32
#include <unistd.h>
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TcpManager::TcpManager()
{
	SetIOThreadCount(4);//��������IO�߳�����
	SetWorkThreadCount(4);//���ù����߳���
	Listen(8888);
	Listen(6666);
	Listen(9999);
//	Connect("127.0.0.1",8888);//��������δ���ԣ���������ô��
}

TcpManager::~TcpManager()
{

}

/*
 *	���������߳�
 */
void* TcpManager::Main(void* pParam)
{
	while ( IsOk() )
	{
		//ִ��ҵ��
#ifndef WIN32
		usleep( 1000 * 1000 );
#else
		Sleep( 1000 );
#endif
	}
	
	return 0;
}

/**
 * �������¼��ص�����
 * 
 * ������ʵ�־�������ҵ����
 * 
 */
void TcpManager::OnConnect(mdk::NetHost& host)
{
	printf( "new client(%d) connect in\n", host.ID() );
}

/**
 * ���ӹر��¼����ص�����
 * 
 * ������ʵ�־���Ͽ�����ҵ����
 * 
 */
void TcpManager::OnCloseConnect(mdk::NetHost &host)
{
	printf( "client(%d) close connect\n", host.ID() );
}

void TcpManager::OnMsg(mdk::NetHost &host)
{
	//���豨�ĽṹΪ��2byte��ʾ���ݳ���+��������
	unsigned char c[256];
	/*
		��ȡ���ݳ��ȣ����Ȳ���2byteֱ�ӷ��أ��ȴ��´����ݵ���ʱ�ٶ�ȡ
		ֻ��ȡ2byte��false��ʾ��������ȡ�������ݴӻ�����ɾ�����´λ��ǿ��Զ���
	*/
	if ( !host.Recv( c, 2, true ) ) return;
	unsigned short len = 0;
	memcpy( &len, c, 2 );//�õ����ݳ���
	//test1 = (int(c[0]) << 24) + (int(c[1])<<16) + (int(c[2])<<8) + (int(c[3]));


	len += 2;//���ĳ��� = ����ͷ����+���ݳ���

	if ( len > 256 ) 
	{
		printf( "close client:invaild fromat msg\n" );
		host.Close();
		return;
	}
	if ( !host.Recv(c, len) ) return;//�����Ķ��������ӽ��ջ�����ɾ�������Բ����ܳ��Ȳ�������ʹ�����Ѿ��Ͽ���Ҳ���Զ�������
	
	//����Ϣ����ProtocolManager����
	ProtocolManager.GetInstance()->DiapathMessage(c);

}
