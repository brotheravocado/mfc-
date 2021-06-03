#include "stdafx.h"
#include "ClientThread.h"
#include "ThreadSyncDlg.h"

ClientThread::ClientThread()
{
}


ClientThread::~ClientThread()
{
}


bool ClientThread::initInstance()
{
	// TODO: 여기에 구현 코드 추가.
	CThreadSyncDlg dlg;
	int nResponse = dlg.DoModal();
	return false;
}


int ClientThread::ExitInstance()
{
	// TODO: 여기에 구현 코드 추가.
	return CWinThread::ExitInstance();
}
