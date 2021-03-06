
// mfcTask11View.h: интерфейс класса CmfcTask11View
//

#pragma once


class CmfcTask11View : public CFormView
{
protected: // создать только из сериализации
	CmfcTask11View();
	DECLARE_DYNCREATE(CmfcTask11View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCTASK11_FORM };
#endif

// Атрибуты
public:
	CmfcTask11Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CmfcTask11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnEnChangeEdit1();
    BOOL m_EnableTask1Check;
    BOOL m_EnableTask2Check;
    int m_Task1Edit;
    int m_Task2Edit;
};

#ifndef _DEBUG  // версия отладки в mfcTask11View.cpp
inline CmfcTask11Doc* CmfcTask11View::GetDocument() const
   { return reinterpret_cast<CmfcTask11Doc*>(m_pDocument); }
#endif

