#pragma once
#include <iostream>
#include "worker.h"
class workerManager {
public: 
	workerManager() ; 
	void showManu();
	void exitSystem(); 
	~workerManager() ; 

	//记录员工人数
	int m_EmpNum;
	// 职工数组的指针
	Worker** m_EmpArray;
	bool m_FileIsEmpty; 
	void save(); 
	int get_EmpNum(); 
	void Add_Emp();
	void init_Emp(); 
	void Show_Emp(); 
	int IsExist(int id); 
	void Del_Emp(); 
	void Mod_Emp(); 
	void Find_Emp(); 
	void Sort_Emp();
	void Clean_File(); 
};
