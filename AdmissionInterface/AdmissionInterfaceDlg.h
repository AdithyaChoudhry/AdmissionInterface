
// AdmissionInterfaceDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CAdmissionInterfaceDlg dialog
class CAdmissionInterfaceDlg : public CDialogEx
{
// Construction
public:
	CAdmissionInterfaceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ADMISSIONINTERFACE_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();

protected:

	void ChangeCtrlEnable();
	void SearchStudent(CStudent student);
	void InsertStudent(CStudent student);
	void DeleteStudent(CStudent student);
	void UpdateStudent(CStudent student);
	void LoadMySQL();
	void SaveMySQL();
	void SaveMySQL(sql::PreparedStatement *prep_stmt, BinaryNode* leaf);

	//	
	enum DBCtrlState{ Search = 0,Insert, Update, Delete};
	DBCtrlState m_Flag;
	CString m_strStudentName;
	int m_nRegno;
	int m_nGPA;
	int m_nYearOfStudy;
	CString m_strActivities;
	CString m_strAchievements;
	CString m_strCollage;
	CString m_strDepartment;
	CString m_strResult;
};
