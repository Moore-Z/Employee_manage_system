#include "manager.h"

Manager::Manager(int id, int d_id, string name)
{
	this->m_id = id;
	this->m_name = name;
	this->m_departid = d_id;
}

string Manager::getDeptName()
{
	return string("Manager");
}

void Manager::showInfo()
{
	cout << " Manager name: " << this->m_name
		<< " \tManager ID:   " << this->m_id
		<< " \tManager Department ID: " << this->m_departid
		<< " \tDistribute jobs to employees" << endl;
}
