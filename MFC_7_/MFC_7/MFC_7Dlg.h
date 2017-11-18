
// MFC_7Dlg.h : файл заголовка
//

#pragma once
#include "SetDlg.h"


// диалоговое окно CMFC_7Dlg
class CMFC_7Dlg : public CDialogEx
{
// Создание
public:
	CMFC_7Dlg(CWnd* pParent = NULL);	// стандартный конструктор

	CSetDlg m_dlg;
	int m_Radius;
	int m_Direction;


// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_7_DIALOG };
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
public:
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnClickedDrawgraphicsButton();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
