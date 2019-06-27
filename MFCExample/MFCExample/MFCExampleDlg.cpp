
// MFCExampleDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFCExample.h"
#include "MFCExampleDlg.h"
#include "afxdialogex.h"
#include "ImageCtrl.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCExampleDlg ��ȭ ����

//���� �ڵ� ����

CMFCExampleDlg::CMFCExampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCEXAMPLE_DIALOG, pParent)
	//, m_filepath(_T(""))
	//, m_Filename(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_zoomFactor = 1.0;//5.14 �߰�
}

void CMFCExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_PIC, m_pic); // �̹��� ��� ����
									  //  DDX_Control(pDX, IDC_FILEPATH, m_Filepath);
									  //  DDX_Control(pDX, IDC_FILENAME, m_Filename);
									  //  DDX_Text(pDX, IDC_FILEPATH, m_filepath);
									  //  DDX_Text(pDX, IDC_FILENAME, m_Filename);
	//DDX_Control(pDX, IDC_STATIC, m_image);//advanced image control ����
	DDX_Control(pDX, IDC_PIC, m_pic);

	DDX_Control(pDX, IDC_LISTpath, m_listpath);
	DDX_Control(pDX, IDC_LISTname, m_listname);
	//  DDX_Text(pDX, IDC_EDIT2, m_windowp);
	//  DDX_Control(pDX, IDC_EDIT2, m_windowp);
	DDX_Control(pDX, IDC_WINSTATIC, m_windowp);
	DDX_Control(pDX, IDC_IMGSTATIC, m_imgp);


	DDX_Control(pDX, IDC_SLIDER1, m_ZoomBar);
	DDX_Control(pDX, IDC_PointerPB, m_PointerPB);
}

BEGIN_MESSAGE_MAP(CMFCExampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_IMGBUTTON, &CMFCExampleDlg::OnBnClickedImgbutton)
	ON_BN_CLICKED(IDC_DISBUTTON, &CMFCExampleDlg::OnBnClickedDisbutton)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CMFCExampleDlg::OnNMCustomdrawSlider1)


	ON_BN_CLICKED(IDC_ZoomInPB, &CMFCExampleDlg::OnBnClickedZoominpb)
	ON_BN_CLICKED(IDC_FIT, &CMFCExampleDlg::OnBnClickedFit)
	//ON_STN_CLICKED(IDC_ZOOM_CTRL, &CMFCExampleDlg::OnStnClickedZoomCtrl) //5�� 13�� ON_STN_CLICKED�� ���� ã�ƺ���  ������ �ذ��� ��
	ON_BN_CLICKED(IDC_ZoomOutPB, &CMFCExampleDlg::OnBnClickedZoomoutpb)
	
	//ON_BN_CLICKED(IDC_BUTTON_ictrl, &CMFCExampleDlg::OnBnClickedButtonictrl)//advanced image control ����
	ON_BN_CLICKED(IDC_BUTTON_ictrl, &CMFCExampleDlg::OnBnClickedButtonictrl)
END_MESSAGE_MAP()


// CMFCExampleDlg �޽��� ó����

BOOL CMFCExampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	

	//Pointer push button�� Ŭ�� ���·� �����ϱ� 
	m_PointerPB.SetCheck(1);

	//Zoom Bar �ʱ�ȭ
	m_ZoomBar.SetRange(1,100);
	m_ZoomBar.SetPageSize(5);
	m_ZoomBar.SetTicFreq(10);



	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMFCExampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCExampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;

		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCExampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCExampleDlg::OnBnClickedImgbutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CWnd *pWnd = (CWnd*)GetDlgItem(IDC_PIC);//�Ķ���ͷ� Ư�� �������� ID�� �Է����ָ� �� �������� ������ �����͸� ����

	CDC *dc = pWnd->GetDC();
	CStatic *staticSize = (CStatic*)GetDlgItem(IDC_PIC);
	CRect rect;
	
	CString path; // �̹��� ������ ��θ� �޾ƿ� ����
	CFileDialog dig(true);//true�� �ҷ����� ��ȭ����, false�� ���� ��ȭ����

	CString m_filepath;
	CString m_Filename;
	
	CString Imgwidth;
	CString Imgheight;
	CString imgp;

	//�̹��� ũ�� ��� ���� ����
	int Iwidth=0;
	int Iheight=0;

	
	staticSize->GetClientRect(rect);//static�� ũ�⸦ ����

		if (dig.DoModal() == IDOK) { // ���̾�αװ� ����� �� ��ȯ�Ǵ� ���� �˻�, OK ��ư���� ����Ǿ��� ��� IDOK�� ��ȯ
			path = dig.GetPathName();
			m_Filename = dig.GetFileName();
		}
		else { return; }

		m_Img.Load(path); // �ε� ���ϸ� ��� m_hBitmap �ΰ� ���� �о�� �� ���� �ڵ� �ڷ� ������ �ذ�

		m_Img.Draw(dc->m_hDC, 0, 0, rect.right-rect.left, rect.bottom-rect.top);
		
		

		//�̹��� ũ�� ��� �ڵ�
		Iwidth = m_Img.GetWidth();
		Iheight = m_Img.GetHeight();
		Imgwidth.Format(_T("%d"), Iwidth);
		Imgheight.Format(_T("%d"), Iheight);

		imgp = Imgwidth + "X" + Imgheight;
		m_imgp.SetWindowTextW(imgp);

		
		
		m_listpath.AddString(path);//���� ��� list�� ����ϱ�
		m_listname.AddString(m_Filename);//���� �̸� list�� ����ϱ�

		//�̹��� �������� ������� ���� �߰��ϴ� ����

		
}


void CMFCExampleDlg::OnBnClickedDisbutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CRect rect;
	CStatic *staticSize = (CStatic*)GetDlgItem(IDC_PIC);
	staticSize->GetClientRect(rect);
	// ���÷��� �ػ� ����ϴ� �κ�

	int Wwidth = rect.right - rect.left; // ȭ�� ����
	int Wheight = rect.bottom - rect.top;

	CString Swidth; //������ ���ڿ��� �ٲٱ�
	CString Sheight;

	Swidth.Format(_T("%d"), Wwidth);
	Sheight.Format(_T("%d"), Wheight);

	CString winp = Swidth + "X" + Sheight; // ���ڿ� �� �� ���ļ� winp�� ��ġ��

	m_windowp.SetWindowTextW(winp);// ���÷��� �ػ� ��Ÿ���� winp static text�� ����ϱ�
}


void CMFCExampleDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void CMFCExampleDlg::OnBnClickedZoominpb() //5.14 !!!
{
	m_zoomFactor *= 1.2;
	m_pic.SetZoomFactor(m_zoomFactor);
	m_pic.AdjustScrollbars();
	m_pic.Invalidate();
}



void CMFCExampleDlg::OnBnClickedFit()
{
	m_zoomFactor = 1.0;
	m_pic.SetZoomFactor(m_zoomFactor);
	m_pic.AdjustScrollbars();
	m_pic.Invalidate();
}



void CMFCExampleDlg::OnBnClickedZoomoutpb()
{
	m_zoomFactor *= 0.8;
	m_pic.SetZoomFactor(m_zoomFactor);
	m_pic.AdjustScrollbars();
	m_pic.Invalidate();
}





//void CMFCExampleDlg::OnBnClickedButtonictrl()  //advanced image control ����
//{
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//
//	CString path; // �̹��� ������ ��θ� �޾ƿ� ����
//	CFileDialog dig(true);//true�� �ҷ����� ��ȭ����, false�� ���� ��ȭ����
//
//	//CString m_filepath;
//	CString m_Filename;
//
//	if (dig.DoModal() == IDOK) { // ���̾�αװ� ����� �� ��ȯ�Ǵ� ���� �˻�, OK ��ư���� ����Ǿ��� ��� IDOK�� ��ȯ
//		path = dig.GetPathName();
//		m_Filename = dig.GetFileName();
//	}
//	else { return; }
//
//	m_image.load(path);//advanced image control ����
//}


void CMFCExampleDlg::OnBnClickedButtonictrl()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	int i;
	IStream* pStream = NULL; 
	CFile cFile; BYTE *pBuffer = NULL; DWORD dwRead; CString buff;
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_CREATEPROMPT | OFN_PATHMUSTEXIST, _T("All Image Files (*.bmp;*.dib;*.jpg;*.jpeg;*.jpe;*.jfif;*.gif;*.tif;*.tiff;*.png;*.ico;*.wmf;*.emf)|*.bmp;*.dib;*.jpg;*.jpeg;*.jpe;*.jfif;*.gif;*.tif;*.tiff;*.png;*.ico;*.wmf;*.emf|Windows Bitmap (*.bmp;*.dib)|*.bmp;*.dib|JPEG Compressed Image (*.jpg;*.jpeg;*.jpe;*.jfif)|*.jpg;*.jpeg;*.jpe;*.jfif|Graphics Interchange Format (*.gif)|*.gif|Tagged Image File Format (*.tif;*.tiff)|*.tif;*.tiff|Portable Network Graphics (*.png)|*.png|Icon (*.ico)|*.ico|Windows Meta File (*.wmf)|*.wmf|Windows Enhanced Meta File (*.emf)|*.emf||"), this);

	if (fileDlg.DoModal() == IDOK) m_image.load(fileDlg.GetPathName());

	

	m_isOnEnChangeEditWidthHeight = false;
	buff.Format(_T("%d"), (int)m_image.getWidth()); GetDlgItem(IDC_EDIT_WIDTH)->SetWindowTextW(buff);
	buff.Format(_T("%d"), (int)m_image.getHeight()); GetDlgItem(IDC_EDIT_HEIGHT)->SetWindowTextW(buff);
	m_isOnEnChangeEditWidthHeight = true;
	GetDlgItem(5)->EnableWindow(m_image.isImageShown());
	//GetDlgItem(IDC_BUTTON_SAVEAS)->EnableWindow(m_image.isImageShown());

}
