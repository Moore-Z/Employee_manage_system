#pragma once
#include <iostream>

using namespace std; 

class Worker {

public: 

	virtual void showInfo() = 0; 
	virtual string getDeptName() = 0; 
	
	string m_name; 
	int m_id; 
	int m_departid; 

};
