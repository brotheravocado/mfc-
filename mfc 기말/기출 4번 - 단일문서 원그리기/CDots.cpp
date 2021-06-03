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
CDots::CDots(CPoint ptF) {
	m_pt = ptF;

}
void CDots::Draw(CDC *pDC) {
	
	pDC->Ellipse(m_pt.x - 10, m_pt.y - 10, m_pt.x + 10, m_pt.y + 10);
}
void CDots::Serialize(CArchive &ar) {
	if (ar.IsStoring()) {
		ar << m_pt;
	}
	else {
		ar >> m_pt;
	}
}