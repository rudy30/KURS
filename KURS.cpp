#include <afxext.h>
#include <windows.h>
#include <afxwin.h>
#include "resource.h"
//#include "resrc1.h"
class CMyDialog : public CDialog
{
protected:
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	
};

class CMyDialog : public CDialog
{
public:
	CMyDialog(CWnd* pParent = NULL);
	enum { IDD = IDD_DIALOG1};
	CListBox m_size;
	int	m_datatype;
	CEdit  m_matrix;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);
protected:
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	
};
CMyDialog::CMyDialog(CWnd* pParent)
	: CDialog(CMyDialog::IDD, pParent)
{
	m_datatype = 1;
}


void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, m_size);
	DDX_Slider(pDX, IDC_SLIDER2, m_size);
	DDX_Slider(pDX, IDC_SLIDER3, m_size);
	DDX_Slider(pDX, IDC_SLIDER4, m_size);
	DDX_Slider(pDX, IDC_SLIDER5, m_size);
	
}





void CMyDialog::OnCancel()
{
	CDialog::OnCancel();
}
BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
}

class CMyFrameWnd :public CFrameWnd
{
public:
	CMyFrameWnd();
protected:
	CStatusBar m_wndStatusBar;
	CToolBar m_wndToolBar;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnQuit();
	afx_msg void OnAbout();
//	afx_msg void OnFormulaResult();
//	afx_msg void OnFormulaRun();
//	afx_msg void OnDialog();
//	afx_msg void OnFileOpen();
//	afx_msg void OnFileSave();
//	afx_msg void OnFileRename();
//	afx_msg void OnHelp();
	DECLARE_MESSAGE_MAP();
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_FILE_QUIT, OnQuit)
	ON_WM_CREATE()
//	ON_COMMAND(ID_FORMULA_RESULT, OnFormulaResult)
//	ON_COMMAND(ID_FORMULA_RUN, OnFormulaRun)
//	ON_COMMAND(ID_DIALOG, OnDialog)
//	ON_COMMAND(ID_FILE_OPEN40003, OnFileOpen)
//	ON_COMMAND(ID_FILE_SAVERENAME, OnFileSave)
//	ON_COMMAND(ID_FILE_RENAME, OnFileRename)
//	ON_COMMAND(ID_HELP40008, OnHelp)
END_MESSAGE_MAP();

static UINT indicators[] =
{
	ID_SEPARATOR,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


CMyFrameWnd::CMyFrameWnd()
{
	Create(NULL, "My first programm",
		WS_OVERLAPPEDWINDOW, rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU1));
};

int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == 1)
		return -1;
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD	| WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) 
		||!m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;
	}

	if(!m_wndStatusBar.Create(this)||!m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT)))
	{
		return 0;
	}
}
//void CMyFrameWnd::OnHelp()
//{
//	::MessageBox(NULL, "...", "help", MB_OK | MB_ICONEXCLAMATION);
//}
//void CMyFrameWnd::OnFileRename()
//{
//	::MessageBox(NULL, "...", "rename", MB_OK | MB_ICONEXCLAMATION);
//}
//void CMyFrameWnd::OnFileSave()
//{
//	::MessageBox(NULL, "...", "save", MB_OK | MB_ICONEXCLAMATION);
//}
//void CMyFrameWnd::OnFileOpen()
//{
//	::MessageBox(NULL, "...", "open", MB_OK | MB_ICONEXCLAMATION);
//}
//void CMyFrameWnd::OnDialog()
//{
//	::MessageBox(NULL, "...", "Dialog", MB_OK | MB_ICONEXCLAMATION);
//}
//void CMyFrameWnd::OnFormulaRun()
//{
//	::MessageBox(NULL, "...", "Run", MB_OK | MB_ICONEXCLAMATION);
//}
//void CMyFrameWnd::OnFormulaResult()
//{
//	::MessageBox(NULL, "...", "Result", MB_OK | MB_ICONEXCLAMATION);
//}
void CMyFrameWnd::OnAbout()
{
	::MessageBox(NULL,  "Copyright by Semerenko", "About", MB_OK | MB_ICONEXCLAMATION);
}
void CMyFrameWnd::OnQuit()
{
	SendMessage(WM_CLOSE);
};
class CMyApp :public CWinApp
{
public:
	virtual BOOL InitInstance();
};
BOOL CMyApp::InitInstance()
{
	CMyFrameWnd *pMainWnd = new CMyFrameWnd;
	m_pMainWnd = pMainWnd;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
};



CMyApp app;
