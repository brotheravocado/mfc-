#include "stdafx.h"
#include "MutexLock.h"


MutexLock::MutexLock(const CString &name)\
{
	mutex = CreateMutex(NULL, 0, name);
}


MutexLock::~MutexLock()
{
	CloseHandle(mutex);
}


// DWORD timeout
bool MutexLock::Lock(DWORD timeout)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
		if (mutex) {
			if (WaitForSingleObject(mutex, timeout) == WAIT_OBJECT_0)
				return true;
		}
	return false;
}


bool MutexLock::UNLOCK()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	if (mutex) {
		if (ReleaseMutex(mutex))
			return true;
	}
	return false;
}
