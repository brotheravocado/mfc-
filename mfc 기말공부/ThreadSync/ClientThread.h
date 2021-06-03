#pragma once
#include <afxwin.h>
class ClientThread :
	public CWinThread
{
public:
	ClientThread();
	virtual ~ClientThread();
	virtual bool initInstance();
	virtual int ExitInstance();
};

