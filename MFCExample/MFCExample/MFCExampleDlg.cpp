
// MFCExampleDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFCExample.h"
#include "MFCExampleDlg.h"
#include "afxdialogex.h"
#include "ImageCtrl.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCExampleDlg 대화 상자

//참조 코드 시작

CMFCExampleDlg::CMFCExampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCEXAMPLE_DIALOG, pParent)
	//, m_filepath(_T(""))
	//, m_Filename(_T(""))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_zoomFactor = 1.0;//5.14 추가
}

void CMFCExampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_PIC, m_pic); // 이미지 출력 관련
									  //  DDX_Control(pDX, IDC_FILEPATH, m_Filepath);
									  //  DDX_Control(pDX, IDC_FILENAME, m_Filename);
									  //  DDX_Text(pDX, IDC_FILEPATH, m_filepath);
									  //  DDX_Text(pDX, IDC_FILENAME, m_Filename);
	//DDX_Control(pDX, IDC_STATIC, m_image);//advanced image control 적용
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
	//ON_STN_CLICKED(IDC_ZOOM_CTRL, &CMFCExampleDlg::OnStnClickedZoomCtrl) //5월 13일 ON_STN_CLICKED가 뭔지 찾아보고  빨간줄 해결할 것
	ON_BN_CLICKED(IDC_ZoomOutPB, &CMFCExampleDlg::OnBnClickedZoomoutpb)
	
	//ON_BN_CLICKED(IDC_BUTTON_ictrl, &CMFCExampleDlg::OnBnClickedButtonictrl)//advanced image control 적용
	ON_BN_CLICKED(IDC_BUTTON_ictrl, &CMFCExampleDlg::OnBnClickedButtonictrl)
END_MESSAGE_MAP()


// CMFCExampleDlg 메시지 처리기

BOOL CMFCExampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	

	//Pointer push button을 클릭 상태로 설정하기 
	m_PointerPB.SetCheck(1);

	//Zoom Bar 초기화
	m_ZoomBar.SetRange(1,100);
	m_ZoomBar.SetPageSize(5);
	m_ZoomBar.SetTicFreq(10);



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCExampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;

		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCExampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCExampleDlg::OnBnClickedImgbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CWnd *pWnd = (CWnd*)GetDlgItem(IDC_PIC);//파라미터로 특정 아이템의 ID를 입력해주면 그 아이템의 윈도우 포인터를 리턴

	CDC *dc = pWnd->GetDC();
	CStatic *staticSize = (CStatic*)GetDlgItem(IDC_PIC);
	CRect rect;
	
	CString path; // 이미지 파일의 경로를 받아올 변수
	CFileDialog dig(true);//true면 불러오기 대화상자, false면 저장 대화상자

	CString m_filepath;
	CString m_Filename;
	
	CString Imgwidth;
	CString Imgheight;
	CString imgp;

	//이미지 크기 출력 위한 변수
	int Iwidth=0;
	int Iheight=0;

	
	staticSize->GetClientRect(rect);//static의 크기를 얻어옴

		if (dig.DoModal() == IDOK) { // 다이얼로그가 종료될 때 반환되는 값을 검사, OK 버튼으로 종료되었을 경우 IDOK를 반환
			path = dig.GetPathName();
			m_Filename = dig.GetFileName();
		}
		else { return; }

		m_Img.Load(path); // 로드 안하면 계속 m_hBitmap 널값 들어가서 읽어올 수 없음 코드 뒤로 보내서 해결

		m_Img.Draw(dc->m_hDC, 0, 0, rect.right-rect.left, rect.bottom-rect.top);
		
		

		//이미지 크기 출력 코드
		Iwidth = m_Img.GetWidth();
		Iheight = m_Img.GetHeight();
		Imgwidth.Format(_T("%d"), Iwidth);
		Imgheight.Format(_T("%d"), Iheight);

		imgp = Imgwidth + "X" + Imgheight;
		m_imgp.SetWindowTextW(imgp);

		
		
		m_listpath.AddString(path);//얻어온 경로 list에 출력하기
		m_listname.AddString(m_Filename);//얻어온 이름 list에 출력하기

		//이미지 지정영역 출력위해 새로 추가하는 라인

		
}


void CMFCExampleDlg::OnBnClickedDisbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CRect rect;
	CStatic *staticSize = (CStatic*)GetDlgItem(IDC_PIC);
	staticSize->GetClientRect(rect);
	// 디스플레이 해상도 출력하는 부분

	int Wwidth = rect.right - rect.left; // 화면 가로
	int Wheight = rect.bottom - rect.top;

	CString Swidth; //정수를 문자열로 바꾸기
	CString Sheight;

	Swidth.Format(_T("%d"), Wwidth);
	Sheight.Format(_T("%d"), Wheight);

	CString winp = Swidth + "X" + Sheight; // 문자열 세 개 합쳐서 winp에 합치기

	m_windowp.SetWindowTextW(winp);// 디스플레이 해상도 나타내는 winp static text에 출력하기
}


void CMFCExampleDlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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





//void CMFCExampleDlg::OnBnClickedButtonictrl()  //advanced image control 적용
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//
//	CString path; // 이미지 파일의 경로를 받아올 변수
//	CFileDialog dig(true);//true면 불러오기 대화상자, false면 저장 대화상자
//
//	//CString m_filepath;
//	CString m_Filename;
//
//	if (dig.DoModal() == IDOK) { // 다이얼로그가 종료될 때 반환되는 값을 검사, OK 버튼으로 종료되었을 경우 IDOK를 반환
//		path = dig.GetPathName();
//		m_Filename = dig.GetFileName();
//	}
//	else { return; }
//
//	m_image.load(path);//advanced image control 적용
//}


void CMFCExampleDlg::OnBnClickedButtonictrl()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

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
