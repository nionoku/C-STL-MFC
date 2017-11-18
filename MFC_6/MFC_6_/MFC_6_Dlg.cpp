
// MFC_6_Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFC_6_.h"
#include "MFC_6_Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// диалоговое окно CMFC_6_Dlg



CMFC_6_Dlg::CMFC_6_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_6__DIALOG, pParent)
	, m_ResultsEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_6_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULTS_EDIT, m_ResultsEdit);
}

BEGIN_MESSAGE_MAP(CMFC_6_Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CMFC_6_Dlg::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_OKCANCEL_BUTTON, &CMFC_6_Dlg::OnClickedOkcancelButton)
	ON_EN_CHANGE(IDC_RESULTS_EDIT, &CMFC_6_Dlg::OnChangeResultsEdit)
	ON_BN_CLICKED(IDC_RETRYCANCEL_BUTTON, &CMFC_6_Dlg::OnClickedRetrycancelButton)
	ON_BN_CLICKED(IDC_YESNO_BUTTON, &CMFC_6_Dlg::OnClickedYesnoButton)
	ON_BN_CLICKED(IDC_YESNOCANCEL_BUTTON, &CMFC_6_Dlg::OnClickedYesnocancelButton)
END_MESSAGE_MAP()


// обработчики сообщений CMFC_6_Dlg

BOOL CMFC_6_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFC_6_Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFC_6_Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFC_6_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_6_Dlg::OnBnClickedExitButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	{
		// TODO: Add your control notification handler code here
		////Ваш код начинается здесь////

		int iResults;
		iResults = MessageBox(L"Exit?",
			L"Are you sure want to Exit?",
			MB_YESNO + MB_ICONQUESTION);

		if (iResults == IDYES)
		{
			OnOK();
		}
	}

}

void CMFC_6_Dlg::OnClickedOkcancelButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	int iResults;
	iResults = MessageBox(L"You want Ok and Cancel buttons.",
		L"I am the second parametr of the MessageBox function",
		MB_OKCANCEL + MB_ICONSTOP 
		/*OKCancel*/);
	if (iResults == 1)
	{
		m_ResultsEdit = "You Clicked the Ok button";
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_ResultsEdit = "You clicked on the Cancel button";
		UpdateData(FALSE);
	}
}


void CMFC_6_Dlg::OnClickedRetrycancelButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	int iResults;
	iResults = MessageBox(L"You want Retry and Cancel buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_RETRYCANCEL + MB_ICONQUESTION);

	if (iResults == IDRETRY)
	{
		m_ResultsEdit = "You clicked on the Retry button.";
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_ResultsEdit = "You clicked on the Cancel button.";
		UpdateData(FALSE);
	}
}



void CMFC_6_Dlg::OnClickedYesnoButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	int iResults;
	iResults = MessageBox(L"You want Yes and No buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_YESNO + MB_ICONEXCLAMATION);

	if (iResults == IDOK)
	{
		m_ResultsEdit = "You clicked on the OK button.";
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		m_ResultsEdit = "You clicked on the NO button.";
		UpdateData(FALSE);
	}
}


void CMFC_6_Dlg::OnClickedYesnocancelButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	int iResults;
	iResults = MessageBox(L"You want Yes, No and Cancel buttons.",
		L"I am the second parameter of the MessageBox function",
		MB_YESNOCANCEL + MB_ICONINFORMATION);

	if (iResults == IDYES)
	{
		m_ResultsEdit = "You clicked on the Yes button.";
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		m_ResultsEdit = "You clicked on the No button";
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_ResultsEdit = "You clicked on the Cancel button.";
		UpdateData(FALSE);
	}
}





void CMFC_6_Dlg::OnChangeResultsEdit()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}





