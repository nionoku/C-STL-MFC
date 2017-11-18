
// MFC_3_Dlg.h : файл заголовка
//

#pragma once


// диалоговое окно CMFC_3_Dlg
class CMFC_3_Dlg : public CDialogEx
{
// Создание
public:
	CMFC_3_Dlg(CWnd* pParent = NULL);	// стандартный конструктор


	int m_PrevX;
	int m_PrevY;

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_3__DIALOG };
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
	afx_msg void OnClickedExitButton();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
