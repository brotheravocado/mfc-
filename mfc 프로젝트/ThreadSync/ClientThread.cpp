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
	// TODO: ���⿡ ���� �ڵ� �߰�.
	CThreadSyncDlg dlg;
	int nResponse = dlg.DoModal();
	return false;
}


int ClientThread::ExitInstance()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	return CWinThread::ExitInstance();
}
