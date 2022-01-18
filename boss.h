#pragma once
#include <iostream>
#include "worker.h"
using namespace std; 

class Boss : public Worker 
{
public:
	Boss(int id, int d_id, string name);

	virtual string getDeptName();

	virtual void showInfo();
};