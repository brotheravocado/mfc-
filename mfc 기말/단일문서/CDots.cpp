#include "stdafx.h"
#include "CDots.h"

IMPLEMENT_SERIAL(CDots,CObject,1) // �����ݷ� �ϸ� �ȵ� 
//CDots�� ����ȭ�ϰڴ�.


CDots::CDots()
{
}


CDots::~CDots()
{
}
CDots::CDots(CPoint ptFrom, CPoint ptTo) {
	m_ptFrom = ptFrom;
	m_ptTo = ptTo;
}
void CDots::Draw(CDC *pDC) {
	pDC->MoveTo(m_ptFrom);
	pDC->LineTo(m_ptTo);
}
void CDots::Serialize(CArchive &ar) {
	if (ar.IsStoring()) {
		ar << m_ptFrom << m_ptTo;
	}
	else {
		ar >> m_ptFrom >> m_ptTo;
	}
}