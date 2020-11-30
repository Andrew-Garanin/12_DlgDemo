
// DlgDemoDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CDlgDemoDlg
class CDlgDemoDlg : public CDialogEx
{
public:
	CRect m_RectSample;
	enum { INT_DARK, INT_LIGHT };

// Создание
public:
	CDlgDemoDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_Red;
	BOOL m_Green;
	BOOL m_Blue;
	int m_Intensity;
	afx_msg void OnBnClickedRed();
	afx_msg void OnBnClickedGreen();
	afx_msg void OnBnClickedBlue();
	afx_msg void OnBnClickedDark();
	afx_msg void OnBnClickedLight();
};
