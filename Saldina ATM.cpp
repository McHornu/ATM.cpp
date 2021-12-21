// defining Header files

#include	<iostream>
#include	<string>
#include	<fstream>
//#include	<cstdio>


// declaration of namespace

using namespace std;


// declaration of void functions

void showmenu();
void receipt(float balance, float deposit, float withdraw, float currentBalance);



int main(){
	
	// declaration of user input as option
	
	int option;
	
	// declaration and initializing of currentBalance, availableBalance, depositAmount, withdrawAmount
	
	float currentBalance = 1000.00f;
	float availableBalance;		
	float depositAmount;
	float withdrawAmount;
	
	
	// looping transaction
	
	do{
		showmenu();
		
		cout << "Select an option: ";
		cin  >> option; 
		
		system ("cls");
		
		switch (option){
			
			// prints currentBalance to console
			
			case 1: cout	<< "Your balance is Ghc "
							<< currentBalance << "\n"
							<< endl;
				break;
			
			// user input deposit amount, calculates currentBalance  and prints information to console
			
			case 2: cout	<< "Enter deposit amount: ";
	
					cin >> depositAmount;
					currentBalance += depositAmount;
					availableBalance = currentBalance - depositAmount;
					
					cout	<< "\nYou have deposited Ghc "
							<< depositAmount
							<< ".\nAvailable balance is Ghc "
							<< availableBalance
							<< ".\nCurrent balance is Ghc "
							<< currentBalance
							<< "\n\n" << endl;
				break;
			
			// user input withdraw amount, calculates currentBalance and prints information to console
			
			case 3: cout	<< "Enter withdrawal amount: ";
					
					cin >> withdrawAmount;
					
					// condition for withdrawing
					if(withdrawAmount > currentBalance)
					{
						cout	<< "Not enough cash !!!\n"
								<< endl;
					}
					else
					{
						// calculates currentBalance and prints information to console
						
						currentBalance -= withdrawAmount;
						availableBalance = currentBalance + withdrawAmount;
						cout	<< "\nYou have withdrawn Ghc "
								<< withdrawAmount
								<< ".\nAvailable balance is Ghc "
								<< availableBalance
								<< ".\nCurrent balance is Ghc "
								<< currentBalance
								<< "\n\n" << endl;
					}
				break;
				
			// condition for exiting application
			
			case 4:	cout	<< "Press 1 to confirm: ";
					char confirm;
					cin >> confirm;
					
					if (confirm == '1')
					{
						cout	<< "\nThanks for your transaction .....\n"
								<< endl;
								
						// calls receipt function
						
						receipt(availableBalance, depositAmount, withdrawAmount, currentBalance);
					}
				break;
			
			// prints Invalid option to the console
			
			default:	cout << "Invalid option !!!\n" << endl;
		}
	} while (option != 4);
	
	
	system("pause > 0");
}


// initializing of showmenu function

void showmenu(){
	cout	<< "======= MENU ======\n"
			<< "\n1. Check balance"
			<< "\n2. Deposit"
			<< "\n3. Withdraw"
			<< "\n4. Exit"
			<< "\n\n===================\n"
			<< endl;
}

// initializing of receipt function
void receipt(float balance, float deposit, float withdraw, float currentBalance)
{
	// declaration of reference (name of text file)
	
	string reference;
	
	cout	<< "Enter receipt reference: ";
	cin >> reference;
	
	
	// declaration and initializing of receiptName
	
	string receiptName;
	receiptName = reference + ".txt";
	
	
	// initializing and declaration of file pointer
	
	FILE* fp;
	fp = fopen(receiptName.c_str(), "w");
	
	
	// if condition for opening and writing to file
	
	if (fp != 0){
		system("cls");
		
		cout	<< "Preparing statement ...................\n";
		cout	<< "Open "
				<< receiptName
				<< " for transaction summary\n"
				<< endl;
		
		// text file writing format
		
		fprintf(fp, " Transaction Statement");
		fprintf(fp, "\n--------------------------------------------------------\n\n");
		fprintf(fp, " %-42s%s%8.2f\n", "Available balance", "Ghc ", balance);
		fprintf(fp, "\n--------------------------------------------------------\n\n");
		fprintf(fp, " %-24s%s%8.2f\n", "Deposit amount", "Ghc ", deposit);
		fprintf(fp, " %-42s%s%8.2f\n", "Withdrawal amount", "Ghc ", withdraw);
		fprintf(fp, "\n--------------------------------------------------------\n\n");
		fprintf(fp, " %-42s%s%8.2f", "Current balance", "Ghc ", currentBalance);
		fprintf(fp, " \n\n%56s", "==============");
	}
	else {
		// prints error message to console
		
		cerr << "Error creating file";
	}
	
	fclose(fp);
}
