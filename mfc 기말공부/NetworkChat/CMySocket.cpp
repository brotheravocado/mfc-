#include "stdafx.h"
#include "CMySocket.h"
#include "network2Dlg.h"

CMySocket::CMySocket()
{
}


CMySocket::~CMySocket()
{
}

void CMySocket::SetParent(CDialog*pWnd)
{
	m_pWnd = pWnd;
}

void CMySocket::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0)
		((Cnetwork2Dlg*)m_pWnd)->OnAccept();
	//CAsyncSocket::OnAccept(nErrorCode);
}


void CMySocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0)
		((Cnetwork2Dlg*)m_pWnd)->OnClose();
	//CAsyncSocket::OnClose(nErrorCode);
}


void CMySocket::OnConnect(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0)
		((Cnetwork2Dlg*)m_pWnd)->OnConnect();
	//CAsyncSocket::OnConnect(nErrorCode);
}


void CMySocket::OnSend(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0)
		((Cnetwork2Dlg*)m_pWnd)->OnSend();
	//CAsyncSocket::OnSend(nErrorCode);
}


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0)
		((Cnetwork2Dlg*)m_pWnd)->OnReceive();
	//CAsyncSocket::OnReceive(nErrorCode);
}
