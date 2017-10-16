
// MFC_2_Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFC_2_.h"
#include "MFC_2_Dlg.h"
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


// диалоговое окно CMFC_2_Dlg



CMFC_2_Dlg::CMFC_2_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_2__DIALOG, pParent)
//	, m_(_T(""))
	, m_EnableCheck(FALSE)
	, m_VisibleCheck(FALSE)
	, m_TestEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_2_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_TEST_EDIT, m_);
	//  DDX_Control(pDX, IDC_TEST_EDIT, m_TestEdit);
	DDX_Check(pDX, IDC_ENABLED_CHECK, m_EnableCheck);
	DDX_Check(pDX, IDC_VISIBLE_CHECK, m_VisibleCheck);
	DDX_Text(pDX, IDC_TEST_EDIT, m_TestEdit);
}

BEGIN_MESSAGE_MAP(CMFC_2_Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CMFC_2_Dlg::OnClickedExitButton)
	ON_BN_CLICKED(IDC_TEST_BUTTON, &CMFC_2_Dlg::OnClickedTestButton)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CMFC_2_Dlg::OnClickedClearButton)
	ON_BN_CLICKED(IDC_VISIBLE_CHECK, &CMFC_2_Dlg::OnClickedVisibleCheck)
	ON_BN_CLICKED(IDC_ENABLED_CHECK, &CMFC_2_Dlg::OnClickedEnabledCheck)
	ON_EN_CHANGE(IDC_TEST_EDIT, &CMFC_2_Dlg::OnChangeTestEdit)
END_MESSAGE_MAP()


// обработчики сообщений CMFC_2_Dlg

BOOL CMFC_2_Dlg::OnInitDialog()
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

	//Устаноить переменную флажка VisibleCheck и EnabledCheck в состояние
	//TRUE
	m_VisibleCheck = TRUE;
	m_EnableCheck = TRUE;
	//Обновить экран
	UpdateData(FALSE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFC_2_Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_2_Dlg::OnPaint()
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
HCURSOR CMFC_2_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_2_Dlg::OnClickedExitButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	OnOK();
}


void CMFC_2_Dlg::OnClickedTestButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	///Присвоить переменной окна редактирования IDC_TEST_EDIT значение This is a Test. 
	m_TestEdit = "This is a Test";
	//// Обновить экран UpdateData(FALSE);
	UpdateData(FALSE);
}


void CMFC_2_Dlg::OnClickedClearButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	///Присвоить переменной окна редактирования IDC_TEST_EDIT значение NULL. 
	m_TestEdit = " ";
	//// Обновить экран
	UpdateData(FALSE);
}


void CMFC_2_Dlg::OnClickedVisibleCheck()
{
	// TODO: добавьте свой код обработчика уведомлений
	////(содержимое эрана передается переменным элементов управления)
	UpdateData(TRUE);
	///Если отметка флажка Visible зделать окно редактирования видимым
	///А если нет - то невидимым
	if (m_VisibleCheck == TRUE)
		GetDlgItem(IDC_TEST_EDIT)->ShowWindow(SW_SHOW);
	else
		GetDlgItem(IDC_TEST_EDIT)->ShowWindow(SW_HIDE);
}


void CMFC_2_Dlg::OnClickedEnabledCheck()
{
	// TODO: добавьте свой код обработчика уведомлений
	////Обновить значения переменных элементов управления,
	////(содержимое эрана передается переменным элементов управления)
	UpdateData(TRUE);
	///Если отметка флажка Enable зделать окно редактирования видимым
	///А если нет - то невидимым
	if (m_EnableCheck == TRUE)
		GetDlgItem(IDC_TEST_EDIT)->EnableWindow(SW_SHOW);
	else
		GetDlgItem(IDC_TEST_EDIT)->EnableWindow(SW_HIDE);
}


void CMFC_2_Dlg::OnChangeTestEdit()
{
		// TODO:  Добавьте код элемента управления
		///Обновить переменные
	UpdateData(TRUE);
	///Содать переменную типа CString, присвоить ей значение
	///переменной m_TestEdit и выполнить перевод символов в верхний
	///регистр.
	CString UpperValue;
	UpperValue = m_TestEdit;
	UpperValue.MakeUpper();

	///Если в окне редактирования напечатано PAINT 
	///запускается редактор PAINT и окно редактирования становится пустым.
	if (UpperValue == "PAINT")
	{
		system("mspaint.exe");
		m_TestEdit = " ";
		UpdateData(FALSE);
	}

	///Если в окне редактирования напечатано CALCULATOR 
	///запускается калькулятор и окно редактирования становится пустым.
	if (UpperValue == "CALCULATOR")
	{
		system("calc.exe");
		m_TestEdit = " ";
		UpdateData(FALSE);
	}
}
