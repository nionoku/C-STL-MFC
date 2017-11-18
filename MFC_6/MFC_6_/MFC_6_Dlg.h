
// MFC_6_Dlg.h : файл заголовка
//

#pragma once


// диалоговое окно CMFC_6_Dlg
class CMFC_6_Dlg : public CDialogEx
{
// Создание
public:
	CMFC_6_Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_6__DIALOG };
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
	CString m_ResultsEdit;
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnClickedOkcancelButton();
	afx_msg void OnChangeResultsEdit();
	afx_msg void OnClickedRetrycancelButton();
	afx_msg void OnClickedYesnoButton();
	afx_msg void OnClickedYesnocancelButton();
};
