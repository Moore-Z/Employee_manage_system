#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std; 

void test01() {
	Worker* worker1 = NULL; 
	worker1 = new Employee(1, 1, "Ruijie"); 
	worker1->showInfo();
	delete worker1; 

	worker1 = NULL;
	worker1 = new Manager(2, 2, "Wei");
	worker1->showInfo();
	delete worker1;

	worker1 = NULL;
	worker1 = new Boss(3, 3, "Hong");
	worker1->showInfo();
	delete worker1;
}


int main() {
	test01(); 
}