#pragma once
#include <iostream>
#include "worker.h"
using namespace std; 

class Employee:public Worker
{
public: 
	virtual void showInfo(); 

	Employee(int id, int d_id, string name); 
	
	virtual string getDeptName(); 
};