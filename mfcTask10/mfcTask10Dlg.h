
// mfcTask10Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CmfcTask10Dlg
class CmfcTask10Dlg : public CDialog
{
// Создание
public:
	CmfcTask10Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTASK10_DIALOG };
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
    afx_msg void OnFileExit();
    BITMAP bm;
    HBITMAP hbm;
    afx_msg void OnFileOpen32771();
};
