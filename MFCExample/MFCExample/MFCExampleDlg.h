
// MFCExampleDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "atlimage.h"
#include "afxcmn.h"
#include "zoomctrl.h"
#include "ImageCtrl.h" // Image control ��� �߰�


// CMFCExampleDlg ��ȭ ����
class CMFCExampleDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFCExampleDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCEXAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.




// �����Դϴ�.
protected:
	HICON m_hIcon;
	CImageCtrl m_image;//advanced image control ����
	CZoomCtrl m_pic;// ����� �߰� 
	bool m_isOnEnChangeEditWidthHeight;



	double m_zoomFactor;//5.14 �߰�

	// ������ �޽��� �� �Լ� ���� �ִ� ��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CImage m_Img;
	 
	afx_msg void OnBnClickedImgbutton();

	CListBox m_listpath;
	CListBox m_listname;

	CStatic m_windowp;
	CStatic m_imgp;

	afx_msg void OnBnClickedDisbutton();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);

	CSliderCtrl m_ZoomBar;
	CButton m_PointerPB;

	afx_msg void OnBnClickedZoominpb();
	afx_msg void OnBnClickedFit();
	afx_msg void OnBnClickedZoomoutpb();


public:
	afx_msg void OnBnClickedButtonictrl();
};
