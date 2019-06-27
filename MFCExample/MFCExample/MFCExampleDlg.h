
// MFCExampleDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "atlimage.h"
#include "afxcmn.h"
#include "zoomctrl.h"
#include "ImageCtrl.h" // Image control 헤더 추가


// CMFCExampleDlg 대화 상자
class CMFCExampleDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCExampleDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCEXAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.




// 구현입니다.
protected:
	HICON m_hIcon;
	CImageCtrl m_image;//advanced image control 적용
	CZoomCtrl m_pic;// 시험용 추가 
	bool m_isOnEnChangeEditWidthHeight;



	double m_zoomFactor;//5.14 추가

	// 생성된 메시지 맵 함수 원래 있는 것
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
