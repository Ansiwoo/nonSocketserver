
// Examserver.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "Examserver.h"
#include "ExamserverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExamserverApp

BEGIN_MESSAGE_MAP(CExamserverApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CExamserverApp 생성

CExamserverApp::CExamserverApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CExamserverApp 개체입니다.

CExamserverApp theApp;


// CExamserverApp 초기화

BOOL CExamserverApp::InitInstance()
{

	CWinApp::InitInstance();


	

	CExamserverDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	return FALSE;
}

