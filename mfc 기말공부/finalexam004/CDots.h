#pragma once
#include <afx.h>
class CDots :
	public CObject
{
	DECLARE_SERIAL(CDots)
public:
	CDots();
	~CDots();
	CDots(CPoint ptF);
	void Draw(CDC *pDC);
	void Serialize(CArchive &ar);
private:
	CPoint m_pt;
};

