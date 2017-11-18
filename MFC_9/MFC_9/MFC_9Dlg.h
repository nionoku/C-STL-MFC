
// MFC_9Dlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CMFC_9Dlg
class CMFC_9Dlg : public CDialogEx
{
// Создание
public:
	CMFC_9Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_9_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	
	HICON  m_Club;
	HICON  m_Diamond;		
	HICON  m_Spade;
	HICON  m_Heart;

	CStatic m_Card3;		//Переменные с картами иконок
	CStatic m_Card4;		
	CStatic m_Card1;		
	CStatic m_Card2;

	CStatic m_Amt_Left;       //Вывод суммы выигрыша
	double m_Amt_Remaining;		// переменная хранит в себе сумму выигрыша
public:
	afx_msg void OnBnClickedDealcards();
	
private:
	int m_Cards [5];			//Хранит в себе кол-во одинаковых кат каждой масти
public:
	void DealCards();
	void CalculateWinnings();
	HICON& PickRandomCard();
	afx_msg void OnBnClickedCancel();
};
