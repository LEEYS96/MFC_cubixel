
// MFCExample.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCExampleApp:
// �� Ŭ������ ������ ���ؼ��� MFCExample.cpp�� �����Ͻʽÿ�.
//

class CMFCExampleApp : public CWinApp
{
public:
	CMFCExampleApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCExampleApp theApp;