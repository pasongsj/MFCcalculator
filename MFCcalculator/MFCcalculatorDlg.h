
// MFCcalculatorDlg.h: 헤더 파일
//

#pragma once


// CMFCcalculatorDlg 대화 상자
class CMFCcalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCcalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 연산 과정을 보여주는 디스플레이
	CString m_Display_EditCtrl;


	afx_msg void OnBnClickedButtonMultiple();


	afx_msg void OnBnClickedButtonPluse();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();

	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtondivide();
	afx_msg void OnBnClickedButtonMinus();

	afx_msg void OnBnClickedButtonAllclear();
private:
	// 계산을 완료하고 지나간 이전 디스플레이
	CString m_Before_EditCtrl;
	bool m_isOper;
	int Calculate();

};
