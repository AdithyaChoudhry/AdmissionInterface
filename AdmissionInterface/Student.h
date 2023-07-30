#pragma once

struct Examcell
{
	int Regno;
	int GPA;
	int YearOfStudy;
};
struct Extracurricular
{
	CString Activities; 
	CString Achievement; 
};

class CStudent
{
public:
	CStudent(void);
	CStudent(CStudent& student);
	CStudent(CString name, CString Collage, CString department,
		int regno,int gpa, int yearOfStudy, CString Activies, CString Achievements);
	~CStudent(void);
	CStudent & operator = (CStudent& student);

	CString GetCollage();
	void SetCollage(CString Collage);

	CString GetDepartment();
	void SetDepartment(CString department);

	CString GetName();
	void SetName(CString name);

	Examcell GetExamcell();
	void SetExamcell(Examcell examcell);

	Extracurricular GetExtracurricular();
	void SetExtracurricular(Extracurricular extracurricular);

protected:
	CString m_Collage;
	CString m_Department;
	CString m_Name;
	Examcell m_Examcell;
	Extracurricular m_Extracurricular;
};


int Compare(CStudent key1, CStudent key2);
