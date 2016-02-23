
// bmpReaderDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "bmpReader.h"
#include "bmpReaderDlg.h"
#include "afxdialogex.h"
#include <sstream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CbmpReaderDlg



CbmpReaderDlg::CbmpReaderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CbmpReaderDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbmpReaderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MyFrameWnd, m_pFrame);
	DDX_Control(pDX, IDC_SLIDER_V, m_cSliderV);
	DDX_Control(pDX, IDC_SLIDER_H, m_cSliderH);
	DDX_Control(pDX, IDC_EDIT_ADDS, m_cEditAdds);
}

BEGIN_MESSAGE_MAP(CbmpReaderDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_MyFrameWnd, &CbmpReaderDlg::OnStnClickedMyframewnd)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CbmpReaderDlg::OnBnClickedButtonLoad)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_FLIP_Y, &CbmpReaderDlg::OnBnClickedButtonFlipY)
	ON_BN_CLICKED(IDC_BUTTON_FLIP_X, &CbmpReaderDlg::OnBnClickedButtonFlipX)
	ON_BN_CLICKED(IDC_BUTTON_INVERT_R, &CbmpReaderDlg::OnBnClickedButtonInvertR)
	ON_BN_CLICKED(IDC_BUTTON_INVERT_G, &CbmpReaderDlg::OnBnClickedButtonInvertG)
	ON_BN_CLICKED(IDC_BUTTON_INVERT_B, &CbmpReaderDlg::OnBnClickedButtonInvertB)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CbmpReaderDlg::OnBnClickedButtonSave)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_H, &CbmpReaderDlg::OnNMCustomdrawSliderH)
END_MESSAGE_MAP()


// обработчики сообщений CbmpReaderDlg

BOOL CbmpReaderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	
	// TODO: добавьте дополнительную инициализацию
	m_cSliderH.SetRange(0, 100);
	m_cSliderH.SetPos(0);
	m_cSliderV.SetRange(0, 100);
	m_cSliderV.SetPos(0);
	frame_dimensions_update();

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CbmpReaderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CbmpReaderDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CbmpReaderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbmpReaderDlg::OnStnClickedMyframewnd()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CbmpReaderDlg::OnBnClickedButtonLoad()
{
	CFileDialog fileDlg(true, L"bmp", L"*.bmp",
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, L"Bmp Files (*.bmp)|*.bmp|All Files (*.*)|*.*||", this);

	if (fileDlg.DoModal() == IDOK)
	{
		CString strPathName = fileDlg.GetPathName();
		
		char str[500];
		wcstombs(str, (wchar_t*)strPathName.GetString(), sizeof(str));
		Err err = bmp.load(str);

		if (err != Err::ok)
		{
			MessageBox(Get_err_str(err), L"Err");
			strPathName = L"";
		}
		m_pFrame.update_image(bmp);
		m_cEditAdds.SetWindowTextW(strPathName);

		frame_pos_update();
		m_pFrame.Invalidate();
	}
}

void CbmpReaderDlg::OnBnClickedButtonSave()
{
	CFileDialog fileDlg(false, L"bmp", L"*.bmp",
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, L"Bmp Files (*.bmp)|*.bmp|All Files (*.*)|*.*||", this);

	if (fileDlg.DoModal() == IDOK)
	{
		CString strPathName = fileDlg.GetPathName();
		m_pFrame.clean_image();
		char str[500];
		wcstombs(str, (wchar_t*)strPathName.GetString(), sizeof(str));
		Err err = bmp.save(str);
		if (err == Err::ok)
		{
		}
		else
		{
			MessageBox(Get_err_str(err), L"Err");
		}
	}
}


void CbmpReaderDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar->m_hWnd == m_cSliderV.m_hWnd)
	{
		frame_pos_update();
		m_pFrame.Invalidate();
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CbmpReaderDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar->m_hWnd == m_cSliderH.m_hWnd)
	{
		frame_pos_update();
		m_pFrame.Invalidate();
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CbmpReaderDlg::OnBnClickedButtonFlipY()
{
	Image* im = m_pFrame.get_image();
	if (im != nullptr)
	{
		im->flip_y();
		m_pFrame.Invalidate();
	}
}


void CbmpReaderDlg::OnBnClickedButtonFlipX()
{
	Image* im = m_pFrame.get_image();
	if (im != nullptr)
	{
		im->flip_x();
		m_pFrame.Invalidate();
	}
}



void CbmpReaderDlg::OnBnClickedButtonInvertR()
{
	Image* im = m_pFrame.get_image();
	if (im != nullptr)
	{
		im->invert_red();
		m_pFrame.Invalidate();
	}
}


void CbmpReaderDlg::OnBnClickedButtonInvertG()
{
	Image* im = m_pFrame.get_image();
	if (im != nullptr)
	{
		im->invert_green();
		m_pFrame.Invalidate();
	}
}


void CbmpReaderDlg::OnBnClickedButtonInvertB()
{
	Image* im = m_pFrame.get_image();
	if (im != nullptr)
	{
		im->invert_blue();
		m_pFrame.Invalidate();
	}
}





void CbmpReaderDlg::OnNMCustomdrawSliderH(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void CbmpReaderDlg::frame_pos_update()
{
	Point buf = m_pFrame.get_dimensions_image();
	Point pos;
	pos.x = double(m_cSliderH.GetPos()) / 100 * (bmp.m_width - buf.x);
	pos.y = double(100 - m_cSliderV.GetPos()) / 100 * (bmp.m_height - buf.y);
	m_pFrame.update_pos_image(pos);
}
void CbmpReaderDlg::frame_dimensions_update()
{
	CRect rect;
	GetClientRect(&rect);
	Point d;
	d.x = rect.Width() - 35;
	d.y = rect.Height() - 55;
	m_pFrame.update_dimensions_image(d);
}