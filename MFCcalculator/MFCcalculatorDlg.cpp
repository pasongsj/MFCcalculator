
// MFCcalculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCcalculator.h"
#include "MFCcalculatorDlg.h"
#include "afxdialogex.h"
#include<string>

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


// CMFCcalculatorDlg 대화 상자

CMFCcalculatorDlg::CMFCcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCALCULATOR_DIALOG, pParent)
	, m_Display_EditCtrl(_T(""))
	, m_Before_EditCtrl(_T(""))
	, m_isOperDone(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Display_EditCtrl);
	DDX_Text(pDX, IDC_EDIT2, m_Before_EditCtrl);
}

BEGIN_MESSAGE_MAP(CMFCcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Multiple, &CMFCcalculatorDlg::OnBnClickedButtonMultiple)
	ON_BN_CLICKED(IDC_BUTTON_Pluse, &CMFCcalculatorDlg::OnBnClickedButtonPluse)
	ON_BN_CLICKED(IDC_BUTTON_1, &CMFCcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_3, &CMFCcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_2, &CMFCcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_0, &CMFCcalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_AllClear, &CMFCcalculatorDlg::OnBnClickedButtonAllclear)
	ON_BN_CLICKED(IDC_BUTTON_4, &CMFCcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CMFCcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CMFCcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CMFCcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CMFCcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CMFCcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_Equal, &CMFCcalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_divide, &CMFCcalculatorDlg::OnBnClickedButtondivide)
	ON_BN_CLICKED(IDC_BUTTON_Minus, &CMFCcalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_ClearEntry, &CMFCcalculatorDlg::OnBnClickedButtonClearentry)
END_MESSAGE_MAP()


// CMFCcalculatorDlg 메시지 처리기

BOOL CMFCcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCcalculatorDlg::OnPaint()
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
HCURSOR CMFCcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCcalculatorDlg::OnBnClickedButtonAllclear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Display_EditCtrl = "";
	m_Before_EditCtrl = "";
	UpdateData(FALSE);

}



void CMFCcalculatorDlg::OnBnClickedButton0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('0');
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('1');
	UpdateData(FALSE);
}

void CMFCcalculatorDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('2');
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('3');
	UpdateData(FALSE);
}

void CMFCcalculatorDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('4');
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('5');
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('6');
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('7');
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('8');
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	AddNumber('9');
	UpdateData(FALSE);
}

void CMFCcalculatorDlg::AddNumber(char _Num)
{
	if (true == m_isOperDone)
	{
		m_Display_EditCtrl = "";
		m_isOperDone = false;
	}
	m_Display_EditCtrl += _Num;
}


int CMFCcalculatorDlg::Calculate()
{
	 // 마지막 문자가 연산자라면 return;
	int LastChar = (m_Display_EditCtrl[m_Display_EditCtrl.GetLength() - 1]);
	if (LastChar == static_cast<int>(OperationSymbol::Pluse)
		|| LastChar == static_cast<int>(OperationSymbol::Minus)
		|| LastChar == static_cast<int>(OperationSymbol::Multiple)
		|| LastChar == static_cast<int>(OperationSymbol::Divide))
	{
		return INT_MIN;
	}

	int result_number = 0;
	m_Before_EditCtrl = m_Display_EditCtrl;


	std::vector<int> NumberStack;
	std::vector<OperationSymbol> OperStack;
	CString CurNumber;
	CurNumber = "";
	bool iscal = false;
	for (int i = 0; i < m_Display_EditCtrl.GetLength(); ++i)
	{
		if ('0' <= m_Display_EditCtrl[i] && m_Display_EditCtrl[i] <= '9')
		{
			CurNumber += m_Display_EditCtrl[i];
		}
		else
		{
			int curstacknum = _ttoi(CurNumber);
			CurNumber = "";

			if (OperStack.size() > 0)
			{
				if (OperStack.back() == OperationSymbol::Multiple)
				{
					int beforeNum = NumberStack.back();
					NumberStack.pop_back();
					curstacknum = beforeNum * curstacknum;
					OperStack.pop_back();
					iscal = true;
				}
				else if (OperStack.back() == OperationSymbol::Divide)
				{
					int beforeNum = NumberStack.back();
					NumberStack.pop_back();
					curstacknum = beforeNum / curstacknum;
					OperStack.pop_back();
					iscal = true;

				}
			}
			NumberStack.push_back(curstacknum);
			if ('=' == m_Display_EditCtrl[i])
			{
				break;
			}
			OperStack.push_back(static_cast<OperationSymbol>(m_Display_EditCtrl[i]));
		}
	}

	// 숫자 입력이 없는경우
	if (OperStack.size() <= 0 && false == iscal)
	{
		m_Display_EditCtrl.Delete(m_Display_EditCtrl.GetLength() - 1);
		return INT_MIN;
	}
	result_number = NumberStack[0];
	for (int i = 1; i < NumberStack.size(); ++i)
	{
		if (OperStack[i - 1] == OperationSymbol::Pluse)
		{
			result_number += NumberStack[i];
		}
		else
		{
			result_number -= NumberStack[i];

		}
	}


	return result_number;
}


void CMFCcalculatorDlg::OnBnClickedButtonEqual() // 연산
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Display_EditCtrl += "=";
	int result = Calculate();
	CString str;
	if (INT_MIN == result)
	{
		return;
	}
	str.Format(_T("%d"), result);
	m_Display_EditCtrl += str;
	m_Before_EditCtrl = m_Display_EditCtrl;
	m_isOperDone = true;
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButtondivide()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Display_EditCtrl += "/";
	SetOperation(OperationSymbol::Divide);
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButtonMinus()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Display_EditCtrl += "-";
	SetOperation(OperationSymbol::Minus);
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButtonMultiple()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);
	m_Display_EditCtrl += "*";
	SetOperation(OperationSymbol::Multiple);
	UpdateData(FALSE);
}


void CMFCcalculatorDlg::OnBnClickedButtonPluse()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Display_EditCtrl += "+";
	SetOperation(OperationSymbol::Pluse);
	UpdateData(FALSE);
}

void CMFCcalculatorDlg::SetOperation(OperationSymbol _Oper)
{
	UpdateData(TRUE);
	if (true == m_isOperDone)
	{
		int index = m_Display_EditCtrl.GetLength() - m_Display_EditCtrl.Find('=')-1;
		m_Display_EditCtrl = m_Display_EditCtrl.Right(index);
		m_isOperDone = false;
	}
	int LastChar = (m_Display_EditCtrl[m_Display_EditCtrl.GetLength() - 1]);
	if (LastChar == static_cast<int>(OperationSymbol::Pluse)
		|| LastChar == static_cast<int>(OperationSymbol::Minus)
		|| LastChar == static_cast<int>(OperationSymbol::Multiple)
		|| LastChar == static_cast<int>(OperationSymbol::Divide))
	{
		m_Display_EditCtrl.Delete(m_Display_EditCtrl.GetLength() - 1);
	}
	switch (_Oper)
	{
	case CMFCcalculatorDlg::OperationSymbol::None:
		break;
	case CMFCcalculatorDlg::OperationSymbol::Pluse:
		m_Display_EditCtrl += "+";
		break;
	case CMFCcalculatorDlg::OperationSymbol::Minus:
		m_Display_EditCtrl += "-";
		break;
	case CMFCcalculatorDlg::OperationSymbol::Multiple:
		m_Display_EditCtrl += "*";
		break;
	case CMFCcalculatorDlg::OperationSymbol::Divide:
		m_Display_EditCtrl += "/";
		break;
	default:
		break;
	}
	UpdateData(FALSE);
	
}


void CMFCcalculatorDlg::OnBnClickedButtonClearentry()
{
	UpdateData(TRUE);
	m_Display_EditCtrl.Delete(m_Display_EditCtrl.GetLength() - 1);
	UpdateData(FALSE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
