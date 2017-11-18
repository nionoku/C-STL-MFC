
// MFC_8Dlg.h : файл заголовка
//

#pragma once
#include "atltypes.h"
#include "afxwin.h"


// диалоговое окно CMFC_8Dlg
class CMFC_8Dlg : public CDialogEx
{
// Создание
public:
	CMFC_8Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_8_DIALOG };
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
	CRect m_Canvas;			//рабочая область
	COLORREF m_PenColor;	//цвет кисти
	CRect m_PenColorSwatch;	//цветной прямоугольник - палитра
	CPen m_Pen;				//перо
	CPoint m_LineStart;		//нажатие на экран, клик
	CPoint m_LineEnd;		//нажатие на экран, клик
public:
	afx_msg void OnBnClickedClearbtn();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnStnClickedPencolor();

	
	int m_PenWidth;			//Кисть размер
	int m_PenStyle;
	afx_msg void OnBnClickedClearbtn2();
	afx_msg void OnCbnSelchangeShapes();
	int m_data;
	CComboBox m_ShapesCombo;
private:
	//bool DrawShape;
public:
	void DrawShape(bool stretch = false);
	bool m_IsDrawing;
private:
	CBrush m_Brush;				//объект кисти
	COLORREF m_BrushColor;		//Цвет заливки
	CRect m_BrushColorSwatch;	//Координаты индикатора цвета
	CRect m_BrushPreviewSwatch;	//Координаты просмотра
	int m_BrushStyle;			//Стиль закраски
public:
	CListBox m_BrushStyleList;
	afx_msg void OnSelchangeBrushstyle();
	void PaintBrushPreview();
	afx_msg void OnClickedBrushcolor();
	CMetaFileDC* m_pMF;
	afx_msg void OnDestroy();
};
