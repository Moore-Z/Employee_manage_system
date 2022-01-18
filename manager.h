#pragma once
#include <iostream>
#include "worker.h"
using namespace std; 

class Manager : public Worker 
{
public: 
	Manager(int id, int d_id, string name);

	virtual string getDeptName(); 

	virtual void showInfo(); 
};