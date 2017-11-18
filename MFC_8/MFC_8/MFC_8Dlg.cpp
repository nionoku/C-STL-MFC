
// MFC_8Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFC_8.h"
#include "MFC_8Dlg.h"
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


// диалоговое окно CMFC_8Dlg



CMFC_8Dlg::CMFC_8Dlg(CWnd* pParent /*=NULL*/)											//конструктор
	: CDialogEx(IDD_MFC_8_DIALOG, pParent)
	, m_PenWidth(0)
	, m_PenStyle(0)
	, m_data(0)
	, m_IsDrawing(false)
	, m_pMF(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	////////////////////////////////////////
	////-Ваш код начинается здесь -////

	m_PenColor = RGB(0, 0, 0); // Начальный цвет кисти
	m_PenWidth = 1;			   // Начальный размер кисти


							   ////-Ваш код заканчивается здесь -////
							   /////////////////////////////////////////
	m_BrushStyle = 0;
}

void CMFC_8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_PENWIDTH, m_PenWidth);
	DDX_Text(pDX, IDC_PENWIDTH, m_PenWidth);
	DDV_MinMaxInt(pDX, m_PenWidth, 1, 32);
	DDX_Radio(pDX, IDC_SOLID_PEN, m_PenStyle);
	DDX_CBIndex(pDX, IDC_SHAPES, m_data);
	DDX_Control(pDX, IDC_SHAPES, m_ShapesCombo);
	DDX_Control(pDX, IDC_BRUSHSTYLE, m_BrushStyleList);
}

BEGIN_MESSAGE_MAP(CMFC_8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEARBTN, &CMFC_8Dlg::OnBnClickedClearbtn)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_STN_CLICKED(IDC_PENCOLOR, &CMFC_8Dlg::OnStnClickedPencolor)
	ON_BN_CLICKED(IDC_CLEARBTN2, &CMFC_8Dlg::OnBnClickedClearbtn2)
	ON_CBN_SELCHANGE(IDC_SHAPES, &CMFC_8Dlg::OnCbnSelchangeShapes)
	ON_LBN_SELCHANGE(IDC_BRUSHSTYLE, &CMFC_8Dlg::OnSelchangeBrushstyle)
	ON_STN_CLICKED(IDC_BRUSHCOLOR, &CMFC_8Dlg::OnClickedBrushcolor)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// обработчики сообщений CMFC_8Dlg

BOOL CMFC_8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();																  //начальные условия

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
			
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
/////////////////////////////////////////////


//-----------------Для рабочей области--------------------------------
//Получить указатель на элемент управления Picture
	CWnd* p_Canvas = GetDlgItem(IDC_CANVAS);

	//Записать координаты окна в переменную m_Canvas
	p_Canvas->GetWindowRect(&m_Canvas);

	//Сопоставить координаты для клиентской области
	ScreenToClient(&m_Canvas);

	//Изменить координаты окна
	m_Canvas.DeflateRect(2, 2, 1, 1);

//--------------------Для прямоугольник выбора цвета 1 - большой-----------------------------

	//Получить указатель на элемент управления
	CWnd* pPenColor = GetDlgItem(IDC_PENCOLOR);

	//Получить координаты элемента управления
	pPenColor->GetWindowRect(&m_PenColorSwatch);

	//Изменить координаты относительно клиентской области
	ScreenToClient(&m_PenColorSwatch);

//------------------Для выбора размера кисти-------------------------------

	//Получить указатель на элемент управления
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);

	/*Установить диапазон значений непосредственно для IDC_SPIN1*/
	pSpin->SetRange(1, 32);

	//Установить начальное значение счетчика в 1;
	pSpin->SetPos(1);

	//--------------------Для прямоугольника выбора цвета 2-----------------------------

	//Получить указатель на элемент управления
	CWnd* pBrushColor = GetDlgItem(IDC_BRUSHCOLOR);

	//Получить координаты элемента управления
	pBrushColor->GetWindowRect(&m_BrushColorSwatch);

	//Изменить координаты относительно клиентской области
	ScreenToClient(&m_BrushColorSwatch);

	//Cузить рамку
	m_BrushColorSwatch.DeflateRect(2, 2, 1, 1);

	//--------------------Для прямоугольника выбора цвета 3-----------------------------

	//Получить указатель на элемент управления
	CWnd* pPreviewColor = GetDlgItem(IDC_BRUSHPREVIEW);

	//Получить координаты элемента управления
	pPreviewColor->GetWindowRect(&m_BrushPreviewSwatch);

	//Изменить координаты относительно клиентской области
	ScreenToClient(&m_BrushPreviewSwatch);

	//Cузить рамку
	m_BrushPreviewSwatch.DeflateRect(2, 2, 1, 1);

	//Установить начальный цвет кисти
	m_BrushColor = RGB(0, 0, 0);

	//Создать белую кисть
	m_Brush.CreateStockObject(WHITE_BRUSH);

	
	//-----------------Переопределение комман баттон--------------------------------

	m_ShapesCombo.AddString(L"FreeHand");
	m_ShapesCombo.AddString(L"Lines");
	m_ShapesCombo.AddString(L"Ovals");
	m_ShapesCombo.AddString(L"Rectangle");

	//-------------------------------------------------
	
	//Установить начальную позицию курсора
	m_ShapesCombo.SetCurSel(0);

	//----------------------------------------------

	//Добавить названия стилей в элемент ListBox
	m_BrushStyleList.AddString(L"none");
	m_BrushStyleList.AddString(L"Solid");
	m_BrushStyleList.AddString(L"LL-UR Diagonal");
	m_BrushStyleList.AddString(L"UL-LR Diagonal");
	m_BrushStyleList.AddString(L"Grid");
	m_BrushStyleList.AddString(L"Grid Diagonal");
	m_BrushStyleList.AddString(L"Horizontal");
	m_BrushStyleList.AddString(L"Vertical");
	m_BrushStyleList.AddString(L"White");
	m_BrushStyleList.AddString(L"Light Gray");
	m_BrushStyleList.AddString(L"Medium Gray");
	m_BrushStyleList.AddString(L"Dark Gray");
	m_BrushStyleList.AddString(L"Black");

	//Установить начальную позицию курсора на 8 элементе
	m_BrushStyleList.SetCurSel(8);

//----------------------------------------------
	//Разместить в памяти объект метафайла
	m_pMF = new CMetaFileDC;
	//Создать МетаФайл
	m_pMF->Create();

/////////////////////////////////////////////////////////////
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFC_8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_8Dlg::OnPaint()												//рисование объектов на экране, перерисовывание
{
	CPaintDC dc(this);

	//Закрытие метафайла
	HMETAFILE hmf = m_pMF->Close();
	//Воспроизведение метафайла
	dc.PlayMetaFile(hmf);

	//Присваивание указателя на старый объект переменной temp
	CMetaFileDC* temp = new CMetaFileDC;
	//Закрытие объекта
	temp->Create();
	//Проигрование метафайла
	temp->PlayMetaFile(hmf);

	//Удаление метаструктуры и метафайла
	DeleteMetaFile(hmf);
	//delete hmf;

	//Присваивание временного указателя постоянному
	m_pMF = temp;
	/*Если первый раз была вызвана функия OnPaint, то вызавать очистку экрана*/
	static int(firstTime) = TRUE;
	if (firstTime)
	{
		OnBnClickedClearbtn();
		firstTime = FALSE;
	}

	/*if (IsIconic())
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
	}*/
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFC_8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


																						//отчистка экрана, нажатие на кнопку
void CMFC_8Dlg::OnBnClickedClearbtn()
{
	// TODO: добавьте свой код обработчика уведомлений
	//Получить указатель на контекст устройства
	CClientDC dc(this);

//////////////////////////	
	//Закрыть метафайл
	HMETAFILE hmf = m_pMF->Close();
	//Удалить данные о метафайле
	::DeleteMetaFile(hmf);
	//delete hmf;

	//Cоздать новый метафайл
	m_pMF = new CMetaFileDC;
	m_pMF->Create();
	m_pMF->SetAttribDC(dc);
///////////////////////////	
	
	//Выбрать нулевое перо
	dc.SelectStockObject(NULL_PEN);

	//Очистить окно
	dc.Rectangle(m_Canvas);

/////////////////////////////////
//Записать команды в метафайл
	m_pMF->SelectStockObject(NULL_PEN);
	m_pMF->Rectangle(m_Canvas.left, m_Canvas.top,
	m_Canvas.right + 1, m_Canvas.bottom + 1);
}

																							//проверка нажатия левой кнопки мыши по рабочей области
void CMFC_8Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	/////-Ваш код начинается здесь-///

	//Проверить было ли нажатие внутри области рисования.
	
	if (m_Canvas.PtInRect(point))
	{
	
		//Присвоить координаты начала двум переменным
		m_LineStart = point;
		m_LineEnd = point;
		
		//Включение рисованя 

		if (m_ShapesCombo.GetCurSel() == 0) m_IsDrawing = false;
		else m_IsDrawing = true;

		//Обновить и присвоить новый цвет кисти
		m_Pen.DeleteObject();
		//Обновить переменные значениями в окне прграммы
		UpdateData(TRUE);
		//Создать новую кисть с учетом формы, размера и цвета.
		m_Pen.CreatePen(m_PenStyle, m_PenWidth, m_PenColor);

		//Захватить мышь
		SetCapture();
	
	}
	/////-Ваш код заканчивается здесь-/////

	CDialogEx::OnLButtonDown(nFlags, point);
}

																									//Рисуем линию, движение мыши
void CMFC_8Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	////-Ваш код начинается здесь-////	
	
	if ((nFlags & MK_LBUTTON) && m_Canvas.PtInRect(point))
	{

		if (m_IsDrawing && (nFlags & MK_LBUTTON) && m_Canvas.PtInRect(point))
		{

			//Нарисовать фигуру методом резиновой нити
			DrawShape(true);

			//Поменять координаты конца на текущее положение курсора
			m_LineStart = m_LineEnd;

			//Стереть предыдущую и нарисовать новую фигуру
			DrawShape(true);
		}

		else
		{
			//Получить указатель на контекст устройства
			CClientDC dc(this);

			dc.SelectObject(&m_Pen);

			//Присвоить координаты щелчка переменной m_LineEnd
			m_LineEnd = point;

			//Нарисовать линию
			dc.MoveTo(m_LineStart);
			dc.LineTo(m_LineEnd);

			//Присвоить текущее переменной m_LineStart значение позиции курсора
			m_LineStart = m_LineEnd;
		}	
		
	}	
	
	////-Ваш код закачивается здесь-////
	
	CDialogEx::OnMouseMove(nFlags, point);
}

																						//действие по отпусканию кнопки мыши
void CMFC_8Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	
	////-Ваш код начинается здесь-////

	//Отключить режим рисования
	m_IsDrawing = FALSE;

	/*Если мышка отпущена внутри области рисования, то нарисовать фигуру окончательно*/
	if (m_Canvas.PtInRect(point))
	{
		m_LineEnd = point;
		DrawShape();
	}
	//Если нет, то стереть
	else
	{
		DrawShape(true);
	}
	m_LineStart = point;

	//Отпустить мышь
	ReleaseCapture();

	////-Ваш код заканчивается здесь-////
	
	CDialogEx::OnLButtonUp(nFlags, point);
}

																									//выбор цвета, прямоугольник 1
void CMFC_8Dlg::OnStnClickedPencolor()
{
	// TODO: добавьте свой код обработчика уведомлений

	/*Создать объект класса диалоговой панели выбора цвета и передать ему в конструкторе текущее значение цвета*/ 
	CColorDialog dlg(m_PenColor);

	//Вывод диалогового окна
	if (dlg.DoModal() == IDOK)
	{
		//Установка цвета
		m_PenColor = dlg.GetColor();

		//Создание кисти
		CBrush swatch;
		swatch.CreateSolidBrush(m_PenColor);

		//Получить объект контекста устройства
		CClientDC dc(this);

		//Закрашивание индикатора выбранным цветом
		dc.FillRect(&m_PenColorSwatch, &swatch);
	}
}


void CMFC_8Dlg::OnBnClickedClearbtn2()
{
	// TODO: добавьте свой код обработчика уведомлений
	OnOK();
}


void CMFC_8Dlg::OnCbnSelchangeShapes()
{
	// TODO: добавьте свой код обработчика уведомлений
}

																								//Рисование резиновой нитью
void CMFC_8Dlg::DrawShape(bool stretch)
{
	//Получить объект контекста устройства
	CClientDC dc(this);

	//Установить атрибуты DC
	dc.SetAttribDC(dc);
	dc.IntersectClipRect(m_Canvas);

	m_pMF->SetAttribDC(dc);
	dc.IntersectClipRect(m_Canvas);
	m_pMF->IntersectClipRect(m_Canvas);

	//Получить номер позиции из спика названий фигур
	int drawmode = m_ShapesCombo.GetCurSel();

	//Выбрать перо
	dc.SelectObject(&m_Pen);
	dc.SelectObject(&m_Brush); 

	//Записать операторы в метафайл
	m_pMF->SelectObject(&m_Pen);
	m_pMF->SelectObject(&m_Brush);

	//Метод резиновой нити
	if (stretch && drawmode != 0)
	{
		//Установить метод резиновой нити
		dc.SetROP2(R2_NOT);
	}

	//Конструкция выбора фигуры
	switch (drawmode)
	{
		//Свободное рисование
	case 0:
		dc.MoveTo(m_LineStart);
		dc.LineTo(m_LineEnd);
		
		//Записать операторы в метафайл
		m_pMF->MoveTo(m_LineStart);
		m_pMF->LineTo(m_LineEnd);

		m_LineStart = m_LineEnd;
		break;
		//Рисование линий
	case 1:
		dc.MoveTo(m_LineStart);
		dc.LineTo(m_LineEnd);		
		/*Записать операторы в метафайл, если не выбран режим резиновой нити*/
		if (!stretch)
		{
			m_pMF->MoveTo(m_LineStart);
			m_pMF->LineTo(m_LineEnd);
		}
		break;
		//Рисование элипсов
	case 2:
		dc.Ellipse(CRect(m_LineStart, m_LineEnd));
		//Записать операторы в метафайл
		if (!stretch)
		{
			m_pMF->Ellipse(CRect(m_LineStart, m_LineEnd));
		}
		break;
		//Рисование прямоугольника
	case 3:
		dc.Rectangle(CRect(m_LineStart, m_LineEnd));
		//Записать операторы в метафайл
		if (!stretch)
		{
			m_pMF->Rectangle(CRect(m_LineStart, m_LineEnd));
		}
		break;
	}
}

																							//обраротчик стилей заливки
void CMFC_8Dlg::OnSelchangeBrushstyle()
{
	// TODO: добавьте свой код обработчика уведомлений

	//Удалить предыдущий объект
	m_Brush.DeleteObject();

	//Получить номер выбранной позиции
	int style = m_BrushStyleList.GetCurSel();

	//По номеру создать кисть, с выбранным стилем
	switch (style)
	{
	case 0:
		m_Brush.CreateStockObject(NULL_BRUSH);
		break;

	case 1:
		m_Brush.CreateSolidBrush(m_BrushColor);
		break;

	case 2:
		m_Brush.CreateHatchBrush(HS_BDIAGONAL, m_BrushColor);
		break;

	case 3:
		m_Brush.CreateHatchBrush(HS_FDIAGONAL, m_BrushColor);
		break;

	case 4:
		m_Brush.CreateHatchBrush(HS_CROSS, m_BrushColor);
		break;

	case 5:
		m_Brush.CreateHatchBrush(HS_DIAGCROSS, m_BrushColor);
		break;

	case 6:
		m_Brush.CreateHatchBrush(HS_HORIZONTAL, m_BrushColor);
		break;

	case 7:
		m_Brush.CreateHatchBrush(HS_VERTICAL, m_BrushColor);
		break;

	case 9:
		m_Brush.CreateStockObject(LTGRAY_BRUSH);
		break;


	case 10:
		m_Brush.CreateStockObject(GRAY_BRUSH);
		break;

	case 11:
		m_Brush.CreateStockObject(DKGRAY_BRUSH);
		break;

	case 12:
		m_Brush.CreateStockObject(BLACK_BRUSH);
		break;

		//Создать кисть по умолчанию
	default:
		m_Brush.CreateStockObject(WHITE_BRUSH);
		break;
	}

	//Вызвать функцию зарисовки окна Preview
	PaintBrushPreview();
}


void CMFC_8Dlg::PaintBrushPreview()										// отображение в прямоугольнике стилей
{
	////-Ваш код начинается здесь-////

	CClientDC dc(this);
	dc.FillRect(&m_BrushPreviewSwatch, &m_Brush);

	////-Ваш код заканчивается здесь-////
}


void CMFC_8Dlg::OnClickedBrushcolor()								//цветной прямоугольник 2 для стилей
{
	// TODO: добавьте свой код обработчика уведомлений
	////-Ваш код начинается здесь-////

	//Создать объект диалогового окна выбор цвета
	CColorDialog dlg(m_BrushColor);

	/*Если была нажата кнопка ОК, то закрасить индикатор цвета*/
	if (dlg.DoModal() == IDOK)
	{
		m_BrushColor = dlg.GetColor();
		CClientDC dc(this);
		CBrush b(m_BrushColor);

		//Закрашивание индикатора цвета кисти
		dc.FillRect(&m_BrushColorSwatch, &b);
	}

	/*Запустить функцию создания кисти, выбранным цветом*/
	OnSelchangeBrushstyle();

	////-Ваш код заканчивается здесь-////
}


void CMFC_8Dlg::OnDestroy()																	//деконструктор
{
	CDialogEx::OnDestroy();

	// TODO: добавьте свой код обработчика сообщений

	CDialog::OnDestroy();
	////-Ваш код начинается здесь-////

	//Закрыть и удалить метафайл
	m_pMF->Close();
	delete m_pMF;

	////-Ваш код начинается здесь-////
}
