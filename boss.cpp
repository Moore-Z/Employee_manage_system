#include "boss.h"

Boss::Boss(int id, int d_id, string name)
{
	this->m_id = id;
	this->m_name = name;
	this->m_departid = d_id;
}

string Boss::getDeptName()
{
	return string("Boss");
}

void Boss::showInfo()
{
	cout << " Boss name: " << this->m_name
		<< " \tBoss ID: " << this->m_id
		<< "        \tBoss Department ID: " << this->m_departid
		<< "        \tAll required jobs.  " << endl;
}
