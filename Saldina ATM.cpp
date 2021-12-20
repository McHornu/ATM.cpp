#include <iostream>
using namespace std;

void showmenu(){
	cout << " -======MENU======" << endl;
	cout << " 1-Check balance" << endl;
	cout << " 2-Deposite " << endl;
	cout << " 3-Withdraw " << endl;
	cout << " 4-Exit " << endl;
	cout << " ==================" << endl;
}

int main(){
	// Check balance, deposit, withdraw, show menu
	int option;
	double balance = 800; 
	
	do{
	showmenu();
	cout << "Select an option: ";
	cin  >> option; 
	system ("cls");
	
	switch (option){
		case 1: cout << "Your balance is - " << balance << " GHC" << endl; break;
		case 2: cout << "Enter the amount ";
			double enterAmount;
			cin >> enterAmount;
			balance += enterAmount;
			break;
		case 3: cout << "Withdraw amount ";
			double withdrawAmount;
			cin >> withdrawAmount;
			if(withdrawAmount<balance);
			else 
			cout << "Not enough Funds " << endl;
			balance += enterAmount;
			break;
	}
	} while (option!=4);
	
		system("pause>0");
}