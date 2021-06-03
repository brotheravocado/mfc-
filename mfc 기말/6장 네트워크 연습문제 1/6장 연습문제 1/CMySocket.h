#pragma once
#include <afxsock.h>

class CMySocket :
	public CAsyncSocket
{
private:
	CDialog*m_pWnd;
public:

	CMySocket();
	virtual~CMySocket();
	void SetParent(CDialog* pWnd);
protected:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};

