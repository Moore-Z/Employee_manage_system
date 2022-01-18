#include "employee.h"

void Employee::showInfo()
{
	cout <<" Employee name: " << this->m_name
		<< " \tEmployee ID:   " << this->m_id
		<< " \tEmployee Department ID: " << this->m_departid
		<< " \tDuty finished Manager assigned jobs" << endl; 
}

Employee::Employee(int id, int d_id, string name)
{
	this->m_id = id; 
	this->m_name = name; 
	this->m_departid = d_id; 
}

string Employee::getDeptName()
{
	return string("Employee ");
}
