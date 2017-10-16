
// MFC_1Dlg.h : header file
//

#pragma once


// CMFC_1Dlg dialog
class CMFC_1Dlg : public CDialogEx
{
// Construction
public:
	CMFC_1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSayhelloButton();
	afx_msg void OnExitButton();
	afx_msg void OnClickedExitButton();
	afx_msg void OnBnClickedBeepButton();
};
