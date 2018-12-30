/***********************************************

	Project: 		Budget Track
	Author: 		Hasan Eren KESKIN
	Student Number: 151220144053
	Date:			24.12.2018

	Version:		0.3.1

	- v0.1			Budgets created, added, sorted
	- v0.2			Transcations created, added, sorted
		- v0.2.1	Transactions and Budgets are related each other
		- v0.2.2	Transactions and Budget listed in a ".txt" file
	- v0.3			Simple user interface is ready
		-v0.3.1		Bugs are fixed on user interface

***********************************************/
#include "Transaction.h"
#include <sstream>
#include <iomanip>

using namespace std;

//Constructor
Transaction::Transaction(Category & categoryObjectReference)
			: categoryObject(categoryObjectReference)
{
	fstream Transaction;
	
	Transaction.open("Transactions.txt", ios::out | ios::trunc);

	// If file doesn't exist, create a new file
	if(Transaction.is_open() == false)
	{
		Transaction.open("Transactions.txt", ios::out | ios::trunc);
	}
	Transaction.close();
}

// Sort Budget data with Bubble Sort method
void Transaction::sortBudgetData(void)
{
	volatile int i = 0; 
	volatile int j = 0;
	volatile int temporary = 0;
	string temporaryBalance;
	string temporaryName;

	for(i = 0; i < categoryObject.getBudgetStructSize(); i++)
	{
		for(j = (categoryObject.getBudgetStructSize() - 1); j > i; j--)
		{
			if(categoryObject.budget[j - 1].categoryNumber > categoryObject.budget[j].categoryNumber)
			{
				temporary 									= categoryObject.budget[j - 1].categoryNumber;
				categoryObject.budget[j - 1].categoryNumber = categoryObject.budget[j].categoryNumber;
				categoryObject.budget[j].categoryNumber 	= temporary;
				
				temporaryBalance							= categoryObject.budget[j - 1].categoryBalance;
				categoryObject.budget[j - 1].categoryBalance= categoryObject.budget[j].categoryBalance;
				categoryObject.budget[j].categoryBalance 	= temporaryBalance;
				
				temporaryName								= categoryObject.budget[j - 1].categoryName;
				categoryObject.budget[j - 1].categoryName	= categoryObject.budget[j].categoryName;
				categoryObject.budget[j].categoryName		= temporaryName;
			}	
		}
	}
}

// Sort Transaction data with Bubble Sort method
void Transaction::sortTransactionData(void)
{
	volatile int i = 0; 
	volatile int j = 0;
	volatile int temporary = 0;
	string temporaryDate;
	string temporaryAmount;
	string temporaryDescription;

	for(i = 0; i < categoryObject.getTransactionStructSize(); i++)
	{
		for(j = (categoryObject.getTransactionStructSize() - 1); j > i; j--)
		{
			if(categoryObject.transactions[j - 1].categoryNumber > categoryObject.transactions[j].categoryNumber)
			{
				temporary 											= categoryObject.transactions[j - 1].categoryNumber;
				categoryObject.transactions[j - 1].categoryNumber	= categoryObject.transactions[j].categoryNumber;
				categoryObject.transactions[j].categoryNumber 		= temporary;
				
				temporaryDate										= categoryObject.transactions[j - 1].transactionDate;
				categoryObject.transactions[j - 1].transactionDate	= categoryObject.transactions[j].transactionDate;
				categoryObject.transactions[j].transactionDate		= temporaryDate;
				
				temporaryAmount											= categoryObject.transactions[j - 1].transactionAmount;
				categoryObject.transactions[j - 1].transactionAmount	= categoryObject.transactions[j].transactionAmount;
				categoryObject.transactions[j].transactionAmount		= temporaryAmount;
				
				temporaryDescription										= categoryObject.transactions[j - 1].transactionDescription;
				categoryObject.transactions[j - 1].transactionDescription	= categoryObject.transactions[j].transactionDescription;
				categoryObject.transactions[j].transactionDescription		= temporaryDescription;	
			}	
		}
	}
}

//
void Transaction::sampleReport(void)
{
	volatile int i 		= 0;
	volatile int j 		= 0;
	double total 		= 0.0;
	double temporary 	= 0.0;
	string temp1;
	string temp2;

	for(i = 0; i < categoryObject.getBudgetStructSize(); i++)
	{
		temp1 = categoryObject.budget[i].categoryBalance;
		istringstream(temp1) >> total ;

		cout << "--------------------------------------" << endl;
		cout << categoryObject.budget[i].categoryName<<endl;
		cout << "categoryNumber : " << categoryObject.budget[i].categoryNumber;
		cout << "\tCategoryBalance : " << categoryObject.budget[i].categoryBalance << endl << endl;

		for(j = 0; j < categoryObject.getTransactionStructSize(); j++)
		{
			if(categoryObject.transactions[j].categoryNumber == categoryObject.budget[i].categoryNumber)
			{
				temp2 = categoryObject.transactions[j].transactionAmount;
				cout << "\t";
				cout << categoryObject.transactions[j].transactionDate << "\t";
				cout << categoryObject.transactions[j].transactionAmount << "\t";
				cout << categoryObject.transactions[j].transactionDescription << endl;
				istringstream(temp2) >> temporary; 
				total = total + temporary;					
			}
		}

		cout << endl;
		cout << "categoryNumber : " << categoryObject.budget[i].categoryNumber;
		cout << "\tCategoryBalance : " << total << endl;
	}

	cout << "--------------------------------------" << endl;
}

// Menu for users
void Transaction::menu(void)
{	
	cout << endl << endl;
	cout << "-------------- Budget Track --------------";
	cout << endl << endl;

	cout << "1) Add Budget" 				<< endl;
	cout << "2) Add Transaction"			<< endl;	
	cout << "3) Show Budgets" 				<< endl;
	cout << "4) Show Transaction"			<< endl;
	cout << "5) Sample Report" 				<< endl;
	cout << "6) Remove All Budgets"			<< endl;
	cout << "7) Remove All Transactions"	<< endl;
	cout << "8) Exit" 						<< endl;

	int inputCondition = 0;

	cout << endl << "Select operation number from menu: ";
	cin >> inputCondition;
	
	switch(inputCondition)
	{
		case 1:
			system("CLS");
			categoryObject.writeBudgetFile();
			cout << endl;
			cout << "Budget is added.";
			cout << endl;
			menu();
		break;
		
		case 2:
			system("CLS");
			categoryObject.writeTransactionFile();
			cout << endl;
			cout << "Transaction is added.";
			cout << endl;
			menu();
		break;	
		
		case 3:
			system("CLS");
			categoryObject.readBudgetFile();
			sortBudgetData();
			categoryObject.showBudgets();
			cout << endl;
			cout << "All Budgets are listed";
			cout << endl;
			menu();
		break;

		case 4:
			system("CLS");
			categoryObject.readTransactionFile();
			sortTransactionData();
			categoryObject.showTransactions();
			cout << endl;
			cout << "All Transactions are listed";
			cout << endl;	
			menu();
		break;		
		
		case 5:
			categoryObject.readBudgetFile();
			sortBudgetData();
			categoryObject.readTransactionFile();
			sampleReport();
			cout << endl;
			cout << "Sample Report is shown.";
			menu();
		break;	
		
		case 6:
			remove("Budget.txt"); 
			cout << endl;
			cout << "All Budgets deleted.";
			menu();
		break;	
		
		case 7:
			remove("Transaction.txt"); 
			cout << endl;
			cout << "All Transactions deleted.";
			menu();
		break;
		
		case 8:
			
		break;	
	}
}

// Destructor
Transaction::~Transaction(void)
{

}
