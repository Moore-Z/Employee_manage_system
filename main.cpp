#include <iostream>
#include "workerManager.h"
using namespace std; 


int main() {
	workerManager w1; 
	
	int  selection = 0; 
	while (true) {
		w1.showManu();
		cout << "Enter your choise. " << endl; 
		cin >> selection; 
		switch (selection)
		{
		case 0: //exit 
			w1.exitSystem(); 
			break; 
		case 1: //add 
			w1.Add_Emp();
			break;
		case 2: //show 
			w1.Show_Emp(); 
			break;
		case 3: //delete 
			w1.Del_Emp(); 
			break;
		case 4: //edit 
			w1.Mod_Emp();
			break;
		case 5: //find 
			w1.Find_Emp(); 
			break;
		case 6: //arrage 
			w1.Sort_Emp(); 
			break;
		case 7: //clean 
			
			w1.Clean_File(); 
			break;
		default: 
			system("cls");
			break; 
		}
	
	}
	system("pause");
	return 0; 
}