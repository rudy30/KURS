#include <afxext.h>
#include <windows.h>
#include <afxwin.h>
#include "resource.h"



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
	afx_msg void OnDialog();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFormulaRun();
	afx_msg void OnFormulaResult();
	DECLARE_MESSAGE_MAP();
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_FILE_QUIT, OnQuit)
	ON_COMMAND(ID_DIOLOG, OnDialog)
	ON_COMMAND(ID_RESULT, OnFormulaResult)
	ON_COMMAND(ID_RUN, OnFormulaRun)
	ON_COMMAND(ID_FILE_OPEN40009, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)

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



void CMyFrameWnd::OnFileSave()
{
	::MessageBox(NULL, "...", "save", MB_OK | MB_ICONEXCLAMATION);
}
void CMyFrameWnd::OnFileOpen()
{
	::MessageBox(NULL, "...", "open", MB_OK | MB_ICONEXCLAMATION);
}
void CMyFrameWnd::OnDialog()
{
	::MessageBox(NULL, "...", "Dialog", MB_OK | MB_ICONEXCLAMATION);
}
void CMyFrameWnd::OnFormulaRun()
{
	::MessageBox(NULL, "...", "Run", MB_OK | MB_ICONEXCLAMATION);
}
void CMyFrameWnd::OnFormulaResult()
{
	::MessageBox(NULL, "...", "Result", MB_OK | MB_ICONEXCLAMATION);
}
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
