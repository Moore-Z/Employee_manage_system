#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include <fstream>
constexpr auto FILENAME = "empFile.txt";
using namespace std; 

workerManager::workerManager() 
{
	ifstream ifs; 
	ifs.open(FILENAME, ios::out); 
	if (!ifs.is_open()) 
	{
		cout << " File and data are not exist. " << endl; 
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true; 
		this->m_EmpArray = NULL;
		ifs.close(); 
		return; 
	}
	//File Exist, data empty
	char a1; 
	ifs >> a1; 
	if (ifs.eof()) {
		cout << " File exist, NO data. " << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	
	int num = this->get_EmpNum(); 
	cout << " Number of Employee: " << num << endl;
	this->m_EmpNum = num; 

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	init_Emp(); 

	for (int i = 0; i < m_EmpNum; i++) {
		cout <<i<< "id : " << this->m_EmpArray[i]->m_id
			<< " \tName: " << this->m_EmpArray[i]->m_name
			<< " \tDepartment-id: " << this->m_EmpArray[i]->m_departid<< endl; 
	}

	
}

void workerManager::showManu()
{
	cout << "******************************************" << endl;
	cout << "* Welcom to Use Worker Management system！*" << endl;
	cout << "*************  0.Exit        *************" << endl;
	cout << "*************  1.Add         *************" << endl;
	cout << "*************  2.Show        *************" << endl;
	cout << "*************  3.Delete      *************" << endl;
	cout << "*************  4.Edit        *************" << endl;
	cout << "*************  5.Find        *************" << endl;
	cout << "*************  6.Re-Arrage   *************" << endl;
	cout << "*************  7.Clean       *************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void workerManager::exitSystem()
{
	cout << "Exit the system " << endl; 
	system("pause");
	exit(0);
}
;
workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete [] this->m_EmpArray;
	}
}
;
void workerManager::save()
{
	ofstream ofs; 
	ofs.open(FILENAME, ios::out); 

	for (int i = 0; i < this->m_EmpNum; i++) 
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_departid << endl; 
	}
	ofs.close(); 
}

int workerManager::get_EmpNum()
{
	ifstream ifs; 
	ifs.open(FILENAME, ios::in); 
	int e_id; 
	int e_did; 
	string e_name; 

	int num = 0; 
	while (ifs >> e_id && ifs >> e_name && ifs >> e_did) {
		num++; 
	}
	return num;
}

void workerManager::Add_Emp()
{
	cout << "Enter the number of added employee: " << endl; 
	int addnum = 0; 
	cin >> addnum; 
	if (addnum > 0) 
	{
		int newSize = this->m_EmpNum + addnum; 
		//new 相当于是在heap上面开辟了一篇区域， 大小是 Worker class 为单位，
		//newSize 为大小， 而左边是指向，heap上空间的指针
		Worker** newspace = new Worker * [newSize];

		if (this->m_EmpArray != NULL) 
		{
			for (int i = 0; i < this->m_EmpNum; i++) 
			{
				newspace[i] = this->m_EmpArray[i]; 
			}
		}
		for (int i = 0; i < addnum; i++)
		{
			int f_id;
			string f_name;
			int f_did;

			cout << "Enter the number " << i + 1 << " employee's name :" << endl;
			cin >> f_name;

			cout << "Enter the number " << i + 1 << " employee's id :" << endl;
			cin >> f_id;

			cout << "Enter the Employee's position: " << endl;
			cout << "1. Regular Worker " << endl;
			cout << "2. Manager " << endl;
			cout << "3. Boss " << endl;
			cin >> f_did;

			Worker* worker = NULL;

			switch (f_did)
			{
			case 1:
				worker = new Employee(f_id, f_did, f_name);
				break;
			case 2:
				worker = new Manager(f_id, f_did, f_name);
				break;
			case 3:
				worker = new Boss(f_id, f_did, f_name);
				break;
			default:
				break;
			}
			newspace[this->m_EmpNum + i] = worker;
		}
		// free the old array space, []
		delete[] this->m_EmpArray;

		// change the pointer to the new location 
		this->m_EmpArray = newspace;

		//Renew the number of element 
		this->m_EmpNum = newSize;
		
		this->m_FileIsEmpty = false; 

		cout << "successfully add " << addnum << " workers " << endl;
		
		this->save(); 
	}
	else
	{
		cout << " Invalide Input. " << endl;
	}

	//Press any key to clear the screem 
	system("pause"); 
	system("cls"); 
}

void workerManager::init_Emp()
{
	ifstream ifs; 
	ifs.open(FILENAME, ios::in);
	int i_id; 
	int i_did; 
	string i_name; 
	int index = 0; 

	while (ifs>>i_id && ifs>>i_name && ifs>>i_did)
	{
		Worker* worker = NULL; 
		 
		if (i_did == 1) {
			worker = new Employee(i_id, i_did, i_name); 
		}
		else if (i_did == 2){
			worker = new Manager(i_id, i_did, i_name);
		}
		else if (i_did == 3) {
			worker = new Boss(i_id, i_did, i_name); 
		}
		this->m_EmpArray[index] = worker; 
		index++; 
	}
	cout << "Index: " << index << endl; 
}

void workerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << " We cannot show info for empty file." << endl; 
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo(); 
		}
	}
	system("pause");
	system("cls"); 
}

int workerManager::IsExist(int id)
{
	int index = -1; 
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_id == id) {
			index = i; 
			break; 
		}
	}
	return index; 
}

void workerManager::Del_Emp()
{
	if (this->m_FileIsEmpty) 
	{
		cout << "The file cannot be empty. " << endl; 
	}
	else 
	{
		cout << "Please enter the ID of Employee to delete " << endl; 
		int del_n = -1; 
		cin >> del_n; 
		
		int index = IsExist(del_n); 
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--; 
			this->save(); 
			cout << "Delete success! " << endl; 
		}
		else
		{
			cout << "Employee with this ID not exist. " << endl; 
		}
		
	}
}

void workerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty) 
	{
		cout << "We cannot modify one empty file. " << endl; 
	}
	else
	{
		cout << "Enter the employ ID to modify. " << endl; 
		int input_id; 
		cin >> input_id; 

		int index = this->IsExist(input_id); 
		if (index != -1) 
		{
			//delete this->m_EmpArray[index]; 
			int m_id=0; 
			int m_did=0; 
			string m_name= " ";

			cout << "Find: number  " << index << " worker，please enter new ID： " << endl;
			cin >> m_id;

			cout << "New Name： " << endl;
			cin >> m_name;

			cout << "Position： " << endl;
			cout << "1. Worker" << endl;
			cout << "2. Manager" << endl;
			cout << "3. Boss" << endl;
			cin >> m_did;

			Worker* worker = NULL;
			switch (m_did)
			{
			case 1:
				worker = new Employee(m_id, m_did, m_name);
				
				break;
			case 2:
				worker = new Manager(m_id, m_did, m_name);
				break;
			case 3:
				worker = new Boss(m_id, m_did, m_name);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker; 
			cout << "modify success! " << endl; 
			this->save(); 
		}
		else 
		{
			cout << "Person not exist. " << endl; 
		}
	}

	system("pause");
	system("cls"); 
}

void workerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "File cannot be empty. " << endl;
	}
	else
	{
		cout << "Please enter your search methods" << endl;
		cout << "1. search by ID" << endl;
		cout << "2. search by name" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) 
		{
			int id;
			cout << "Enter the Search ID" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "Success, the ID is:" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "Search fialed, no exist" << endl;
			}
		}
		else if (select == 2) //按姓名查找
		{
			string name;
			cout << "Enter search name: " << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_name == name)
				{
					cout << "success, ID: "
						<< m_EmpArray[i]->m_id
						<< " The information: " << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "Fail! People not exist. " << endl;
			}
		}
		else
		{
			cout << "Input failed. " << endl;
		}
	}


	system("pause");
	system("cls");
}

void workerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "Empty file cannot be arranged. " << endl; 
		system("pause"); 
		system("cls"); 
	}
	else 
	{
		cout << "Enter 1 for ascending arrangement. " << endl; 
		cout << "Enter 2 for descending arrangement. " << endl;
		int selection; 
		cin >> selection; 

		for (int i = 0; i < this->m_EmpNum-1; i++) 
		{
			int MaxOrMin = i; 
			for (int j = i + 1; j < this->m_EmpNum; j++) 
			{
				if (selection == 1)
				{
					if (this->m_EmpArray[MaxOrMin]->m_id > this->m_EmpArray[j]->m_id)
					{
						MaxOrMin = j;
					}
				}
				else 
				{
					if (this->m_EmpArray[MaxOrMin]->m_id < this->m_EmpArray[j]->m_id)
					{
						MaxOrMin = j;
					}
				
				}
				
			}
			if (i != MaxOrMin) 
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MaxOrMin];
				this->m_EmpArray[MaxOrMin] = temp;
			}
			
		}
		cout << " Arrange success! result is: " << endl; 
		this->save(); 
		this->Show_Emp();
	}
}

void workerManager::Clean_File()
{
	cout << " Do you really want to clean the file? " << endl; 
	cout << " Enter 1 confirm. " << endl; 
	cout << " Enter 2 cancel. " << endl; 
	int selection; 
	cin >> selection; 
	if (selection == 1) 
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close(); 
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) 
			{
				delete this->m_EmpArray[i]; 
			}
			this->m_EmpNum = 0; 
			delete[] this->m_EmpArray; 
			this->m_FileIsEmpty = true; 
			this->m_EmpArray = NULL; 
		}
		cout << "Clean success! " << endl; 
	}
	system("pause"); 
	system("cls"); 
};


