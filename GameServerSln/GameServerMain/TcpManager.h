// TestServer.h: interface for the TestServer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTSERVER_H__CD091694_1C7D_42D0_A893_DB0B6482ADC8__INCLUDED_)
#define AFX_TESTSERVER_H__CD091694_1C7D_42D0_A893_DB0B6482ADC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "frame/netserver/NetServer.h"

class TcpManager : public mdk::NetServer  
{
public:
	TcpManager();
	virtual ~TcpManager();

protected:
	/*
	 *	���������߳�
	 */
	void* Main(void* pParam);
	
	/**
	 * �������¼��ص�����
	 * 
	 * ������ʵ�־�������ҵ����
	 * 
	 */
	void OnConnect(mdk::NetHost& host);
	/**
	 * ���ӹر��¼����ص�����
	 * 
	 * ������ʵ�־���Ͽ�����ҵ����
	 * 
	 */
	void OnCloseConnect(mdk::NetHost& host);
	/**
	 * ���ݵ���ص�����
	 * 
	 * ������ʵ�־���Ͽ�����ҵ����
	 * 
	*/
	void OnMsg(mdk::NetHost& host);
	
};

#endif // !defined(AFX_TESTSERVER_H__CD091694_1C7D_42D0_A893_DB0B6482ADC8__INCLUDED_)
