#pragma once
class MutexLock
{
public:
	MutexLock(const CString &name);
	virtual ~MutexLock();
	// DWORD timeout
	bool Lock(DWORD	timeout = INFINITE);
	bool UNLOCK();
private:
	HANDLE mutex;
};

