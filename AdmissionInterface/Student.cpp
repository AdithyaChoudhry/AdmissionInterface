#include "stdafx.h"
#include "Student.h"


CStudent::CStudent(void)
{
	m_Collage = _T("");
	m_Department = _T("");
	m_Name = _T("");

	m_Examcell.Regno = 0;
	m_Examcell.GPA = 0;
	m_Examcell.YearOfStudy = 0;

	m_Extracurricular.Activities = _T("");
	m_Extracurricular.Achievement = _T("");
}

CStudent::CStudent(CString name, CString collage, CString department, int regno,int gpa, int yearOfStudy, CString Activies, CString Achievements)
{
	m_Collage = collage;
	m_Department = department;
	m_Name = name;

	m_Examcell.Regno = regno;
	m_Examcell.GPA = gpa;
	m_Examcell.YearOfStudy = yearOfStudy;

	m_Extracurricular.Activities = Activies;
	m_Extracurricular.Achievement = Achievements;

}

CStudent::CStudent(CStudent& student)
{
//	CStudent::CStudent(student.m_Name, student.m_Collage, student.m_Department
//		, student.m_Examcell.Regno,student.m_Examcell.GPA, student.m_Examcell.YearOfStudy, student.m_Extracurricular.Activies, student.m_Extracurricular.Achievement);

	m_Collage = student.m_Collage;
	m_Department = student.m_Department;
	m_Name = student.m_Name;

	m_Examcell.Regno = student.m_Examcell.Regno;
	m_Examcell.GPA = student.m_Examcell.GPA;
	m_Examcell.YearOfStudy = student.m_Examcell.YearOfStudy;

	m_Extracurricular.Activities = student.m_Extracurricular.Activities;
	m_Extracurricular.Achievement = student.m_Extracurricular.Achievement;
}

CStudent& CStudent::operator=(CStudent& student)
{
	m_Collage = student.m_Collage;
	m_Department = student.m_Department;
	m_Name = student.m_Name;

	m_Examcell.Regno = student.m_Examcell.Regno;
	m_Examcell.GPA = student.m_Examcell.GPA;
	m_Examcell.YearOfStudy = student.m_Examcell.YearOfStudy;

	m_Extracurricular.Activities = student.m_Extracurricular.Activities;
	m_Extracurricular.Achievement = student.m_Extracurricular.Achievement;
	return *this;
}

CStudent::~CStudent(void)
{
}

CString CStudent::GetCollage()
{
	return m_Collage;
}

void CStudent::SetCollage(CString Collage)
{
	m_Collage = Collage;
}

CString CStudent::GetDepartment()
{
	return m_Department;
}

void CStudent::SetDepartment(CString department)
{
	m_Department = department;
}

CString CStudent::GetName()
{
	return m_Name;
}

void CStudent::SetName(CString name)
{
	m_Name = name;
}

Examcell CStudent::GetExamcell()
{
	return m_Examcell;
}

void CStudent::SetExamcell(Examcell examcell)
{
	m_Examcell = examcell;
}

Extracurricular CStudent::GetExtracurricular()
{
	return m_Extracurricular;
}

void CStudent::SetExtracurricular(Extracurricular extracurricular)
{
	m_Extracurricular = extracurricular;
}

int Compare(CStudent key1, CStudent key2)
{
	//		return key1.Compare(key2);
	return key1.GetName().Compare(key2.GetName());
}
