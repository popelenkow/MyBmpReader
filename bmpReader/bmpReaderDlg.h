
// bmpReaderDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"
#include "MyFrameWnd.h"
#include "afxcmn.h"

// диалоговое окно CbmpReaderDlg
class CbmpReaderDlg : public CDialogEx
{
// Создание
public:
	CbmpReaderDlg(CWnd* pParent = NULL);	// стандартный конструктор
	~CbmpReaderDlg()
	{
		
	}
// Данные диалогового окна
	enum { IDD = IDD_BMPREADER_DIALOG };

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

	void frame_pos_update()
	{
		int pos_x = double(m_cSliderH.GetPos()) / 100 * (bmp.m_width - m_pFrame.get_width());
		int pos_y = double(100 - m_cSliderV.GetPos()) / 100 * (bmp.m_height - m_pFrame.get_height());
		m_pFrame.pos_update(pos_x, pos_y);
	}
public:
	CMyFrameWnd m_pFrame;
	afx_msg void OnStnClickedMyframewnd();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonSave();
	Bitmap bmp;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl m_cSliderV;
	CSliderCtrl m_cSliderH;
	CEdit m_cEditAdds;
	afx_msg void OnBnClickedButtonFlipY();
	afx_msg void OnBnClickedButtonFlipX();

	afx_msg void OnBnClickedButtonInvertR();
	afx_msg void OnBnClickedButtonInvertG();
	afx_msg void OnBnClickedButtonInvertB();
	

};
