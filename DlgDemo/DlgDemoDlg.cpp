
// DlgDemoDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "DlgDemo.h"
#include "DlgDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CDlgDemoDlg



CDlgDemoDlg::CDlgDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLGDEMO_DIALOG, pParent)
	, m_Red(FALSE)
	, m_Green(FALSE)
	, m_Blue(FALSE)
	, m_Intensity(INT_LIGHT)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_RED, m_Red);
	DDX_Check(pDX, IDC_GREEN, m_Green);
	DDX_Check(pDX, IDC_BLUE, m_Blue);
	DDX_Radio(pDX, IDC_DARK, m_Intensity);
}

BEGIN_MESSAGE_MAP(CDlgDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RED, &CDlgDemoDlg::OnBnClickedRed)
	ON_BN_CLICKED(IDC_GREEN, &CDlgDemoDlg::OnBnClickedGreen)
	ON_BN_CLICKED(IDC_BLUE, &CDlgDemoDlg::OnBnClickedBlue)
	ON_BN_CLICKED(IDC_DARK, &CDlgDemoDlg::OnBnClickedDark)
	ON_BN_CLICKED(IDC_LIGHT, &CDlgDemoDlg::OnBnClickedLight)
END_MESSAGE_MAP()


// Обработчики сообщений CDlgDemoDlg

BOOL CDlgDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	GetDlgItem(IDC_SAMPLE)->GetWindowRect(&m_RectSample);
	ScreenToClient(&m_RectSample);
	int Border = (m_RectSample.right - m_RectSample.left) / 8;
	m_RectSample.InflateRect(-Border, -Border);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CDlgDemoDlg::OnPaint()
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
		// вызов CDialog::OnPaint() был удален
		COLORREF Color = RGB
		(m_Red ? (m_Intensity == INT_DARK ? 128 : 255) : 0,
			m_Green ? (m_Intensity == INT_DARK ? 128 : 255) : 0,
			m_Blue ? (m_Intensity == INT_DARK ? 128 : 255) : 0);
		CBrush Brush(Color);
		CPaintDC dc(this);
		dc.FillRect(&m_RectSample, &Brush);

	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CDlgDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDlgDemoDlg::OnBnClickedRed()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_Red = IsDlgButtonChecked(IDC_RED);
	InvalidateRect(&m_RectSample);
	UpdateWindow();

}


void CDlgDemoDlg::OnBnClickedGreen()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_Green = IsDlgButtonChecked(IDC_GREEN);
	InvalidateRect(&m_RectSample);
	UpdateWindow();
}


void CDlgDemoDlg::OnBnClickedBlue()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_Blue = IsDlgButtonChecked(IDC_BLUE);
	InvalidateRect(&m_RectSample);
	UpdateWindow();
}


void CDlgDemoDlg::OnBnClickedDark()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (IsDlgButtonChecked(IDC_DARK))
	{
		m_Intensity = INT_DARK;
		InvalidateRect(&m_RectSample);
		UpdateWindow();
	}

}


void CDlgDemoDlg::OnBnClickedLight()
{
	// TODO: добавьте свой код обработчика уведомлений
	if (IsDlgButtonChecked(IDC_LIGHT))
	{
		m_Intensity = INT_LIGHT;
		InvalidateRect(&m_RectSample);
		UpdateWindow();
	}

}
