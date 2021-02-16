
// ExamserverDlg.h: 헤더 파일
//

#pragma once


#define MAX_USER_COUNT 50

#define NM_CHAT_DATA	1 //채팅 데이터

class CExamserverDlg;

class MyServer : public TW_ServerSocket
{
private:
	CExamserverDlg* mp_parent;

public:
	MyServer(CExamserverDlg *ap_parent) : TW_ServerSocket(0x27, MAX_USER_COUNT, new TW_UserData)
	{
		mp_parent = ap_parent;
	}

	virtual void AddWorkForAccept(TW_UserData* ap_user);
	virtual void AddWorkForCloseUser(TW_UserData* ap_user, int a_error_code);
	virtual int ProcessRecvData(SOCKET ah_socket, unsigned char a_msg_id, char *ap_recv_data, BS a_body_size);



};




// CExamserverDlg 대화 상자
class CExamserverDlg : public CDialogEx
{

private:
	MyServer m_server;

// 생성입니다.
public:
	CExamserverDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	void AddEventString(const wchar_t* ap_string);


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAMSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_event_list;
protected:
	afx_msg LRESULT OnAcceptUser(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnReadAndClose(WPARAM wParam, LPARAM lParam);
};
