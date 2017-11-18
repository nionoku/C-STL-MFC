
// MFC_7Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFC_7.h"
#include "MFC_7Dlg.h"
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


// диалоговое окно CMFC_7Dlg



CMFC_7Dlg::CMFC_7Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CMFC_7Dlg::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_DRAWGRAPHICS_BUTTON, &CMFC_7Dlg::OnClickedDrawgraphicsButton)
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// обработчики сообщений CMFC_7Dlg

BOOL CMFC_7Dlg::OnInitDialog()
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

	////////Мой код начинается здесь///////////

	///Установить системный таймер
	int iInstallResult;
	iInstallResult = SetTimer(1, 10, NULL);
	if (iInstallResult == FALSE)
	{
		MessageBox("Cannot install timer",
			"Error message",
			MB_OK + MB_ICONERROR);
	}

	//Выбрать радиокнопку RED
	m_dlg.m_RedRadio = 0;

	m_Radius = 50;
	m_Direction = 1;

	////////Мой код заканчивается здесь///////////


	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFC_7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_7Dlg::OnPaint()
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
		
		////Мой код начинается здесь////

		//	OnDrawgraphicsButton();

		///Создать объект контекста устройства(DC)
		CPaintDC dc(this);

		//Создать новое перо
		CPen MyNewPen;
		//MyNewPen.CreatePen(PS_SOLID, 10, RGB(255,0,0));

		switch (m_dlg.m_RedRadio)
		{
		case 0:
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(255, 0, 0));
			break;
		case 1:
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(0, 255, 0));
			break;
		case 2:
			MyNewPen.CreatePen(PS_SOLID, 10, RGB(0, 0, 255));
			break;
		}
		//Выбрать перо
		CPen* pOriginalPen;
		pOriginalPen = dc.SelectObject(&MyNewPen);
		//	CRect MyRectangle(20, 10, 120,110);

		CRect MyRectangle(20, 10, 20 + m_Radius * 2, 10 + m_Radius * 2);

		//Нарисовать круг
		dc.Ellipse(&MyRectangle);

		//Выбрать первоначальное перо
		dc.SelectObject(pOriginalPen);

		////Мой код заканчивается здесь////
		
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFC_7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_7Dlg::OnBnClickedExitButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	OnOK();
}


void CMFC_7Dlg::OnClickedDrawgraphicsButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_dlg.DoModal();
}


void CMFC_7Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: добавьте свой код обработчика сообщений
	KillTimer(1);
}


void CMFC_7Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	MessageBeep((WORD)-2);


	m_Radius = m_Radius + m_Direction;
	if (m_Radius >= 50)
	{
		m_Direction = -1;
	}
	if (m_Radius <= 10)
	{
		m_Direction = 1;
	}


	CDialogEx::OnTimer(nIDEvent);
}
