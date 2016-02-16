
// bmpReaderDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"
#include "MyFrameWnd.h"
#include "afxcmn.h"

// ���������� ���� CbmpReaderDlg
class CbmpReaderDlg : public CDialogEx
{
// ��������
public:
	CbmpReaderDlg(CWnd* pParent = NULL);	// ����������� �����������
	~CbmpReaderDlg()
	{
		
	}
// ������ ����������� ����
	enum { IDD = IDD_BMPREADER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMyFrameWnd m_pFrame;
	afx_msg void OnStnClickedMyframewnd();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonSave();
	Bitmap bmp;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl m_cSliderV;
	CSliderCtrl m_cSliderH;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButtonFlipY();
	afx_msg void OnBnClickedButtonFlipX();
	CEdit m_cEditAdds;
	afx_msg void OnBnClickedButtonInvertR();
	afx_msg void OnBnClickedButtonInvertG();
	afx_msg void OnBnClickedButtonInvertB();

};
