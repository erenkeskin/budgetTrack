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
#include <iomanip>
#include "Category.h"

using namespace std;

// Static size counter variables
int Category::budgetStructSize 		= 0;
int Category::transactionStructSize = 0;

// Get Budget Structure Size
int Category::getBudgetStructSize(void)
{
	return budgetStructSize;
}

// Get Transactions Structure Size
int Category::getTransactionStructSize(void)
{
	return transactionStructSize;
}

// Reading data from Budget.txt
ostream &operator<<(ostream &output, const Budget &budgetStructure )
{
	output << budgetStructure.categoryNumber;
	output << budgetStructure.categoryBalance;
	output << budgetStructure.categoryName;

	return output;
}

// Reading data from Transactions.txt
ostream &operator<<(ostream &output, const Transactions &transactionStructure)
{
	output << transactionStructure.categoryNumber;
	output << transactionStructure.transactionDate;
	output << transactionStructure.transactionAmount;
	output << transactionStructure.transactionDescription;

	return output;
}

// Writing data to Budget.txt
istream &operator>>(istream &input, Budget &budgetStructure)
{
	
	input.ignore();
	input >> setw(3)	>> budgetStructure.categoryNumber;
	input.ignore();
	input >> setw(15) 	>> budgetStructure.categoryBalance;
	input.ignore();
	input >> setw(66) 	>> budgetStructure.categoryName;
	
	return input;
}

// Writing data to Transactions.txt
istream &operator>>(istream &input, Transactions &transactionStructure)
{
	input.ignore();	
	input >> setw(3) 	>> transactionStructure.categoryNumber;
	input.ignore();
	input >> setw(10) 	>> transactionStructure.transactionDate;
	input.ignore();
	input >> setw(20) 	>> transactionStructure.transactionAmount;
	input.ignore();
	input >> setw(55) 	>> transactionStructure.transactionDescription;
	
	return input;
}

// Constructor
Category::Category(void)
{		
	fstream Budget;
	
	Budget.open("Budget.txt", ios::out | ios::trunc);

	// If file doesn't exist, create a new file
	if(Budget.is_open() == false)
	{
		Budget.open("Budget.txt", ios::out | ios::trunc);
	}
	Budget.close();
}

// Write data to Budget.txt
void Category::writeBudgetFile(void)
{
	int numberOfCategory = 0;
	string balanceOfCategory;
	string nameOfCategory;

	// Control, if structure size is maximum
	if(getBudgetStructSize() < 51)
	{
		// Get data from user
		cout << "Category Number : ";
		cin >> numberOfCategory;
		cout << "Category Balance : ";
		cin >> balanceOfCategory;
		cout << "Category Name : ";
		cin >> nameOfCategory;	
		
		// File operations
		fstream Budget;
		
		Budget.open("Budget.txt", ios::in | ios::out | ios::trunc);
	
		if(Budget.is_open() == true)
		{
			Budget << endl << numberOfCategory << " " << balanceOfCategory << " " << nameOfCategory;		
		} else {
			cout << "File is not found." << endl;
		}
		Budget.close();
	} else {
		cout << "You can't add any category. Allowed number exceeded.";	
	}		
}

// Write datas to Transactions.txt
void Category::writeTransactionFile(void)
{
	int numberOfTransaction = 0;
	string dateOfTransaction;
	string amountOfTransaction;
	string descriptionOfTransaction;

	// Control, if structure size is maximum
	if(getTransactionStructSize() < 501)
	{
		// Get data from user
		cout << "Transaction Number : ";
		cin >> numberOfTransaction;

		cout << "Transaction Date (AA/AA/AAAA) : ";
		cin >> dateOfTransaction;

		cout << "Transaction Amount : ";
		cin >> amountOfTransaction;

		cout << "Transaction Description: ";
		cin.ignore();
		getline(cin, descriptionOfTransaction);
		
		// File Operations
		fstream Transaction;
	
		Transaction.open("Transactions.txt", ios::in | ios::out | ios::ate);
	
		if(Transaction.is_open() == true)
		{
			Transaction << endl << numberOfTransaction << " " << dateOfTransaction << " " << amountOfTransaction << " " << descriptionOfTransaction;		
		} else {
			cout << "File is not found." << endl;
		}
		
		Transaction.close();	
	} else {
		cout << "You can't add any transaction. Allowed number exceeded." << endl;		
	}
}

// Read all data from Budget.txt
void Category::readBudgetFile(void)
{
	fstream Budget;

	volatile int i = 0;
	budgetStructSize = 0;
	Budget.open("Budget.txt", ios::in);
	
	if(Budget.is_open())
	{
		// Until End of the File (EOF)
		while(Budget >> budget[i].categoryNumber >> budget[i].categoryBalance >> budget[i].categoryName)
		{
			i++;
			budgetStructSize++;			
		}				
	}		
	Budget.close();	
}

// Read all data from Transactions.txt
void Category::readTransactionFile(void)
{
	volatile int i = 0;
	transactionStructSize = 0;

	fstream Transaction;
	Transaction.open("Transactions.txt", ios::in);
	
	if(Transaction.is_open())
	{
		// Until End of the File (EOF)
		while(Transaction >> transactions[i].categoryNumber >> transactions[i].transactionDate >> transactions[i].transactionAmount >> transactions[i].transactionDescription)
		{		
			i++;
			transactionStructSize++;
		}	
	
	} else {
		cout << "File can't open" << endl;	
	}	
	Transaction.close();	
}

// Show all budgets from reading with readBudgetFile 
void Category::showBudgets(void)
{
	volatile int i = 0;

	cout << "Number of Budget : " << getBudgetStructSize() << endl << endl << endl;
	cout << "Number/\t" << "Balance/ " << "Name" << endl << endl;

	for(i = 0; i < getBudgetStructSize(); i++)
	{
		cout << left << setw(4) << budget[i].categoryNumber << "\t\t";
		cout << right << setw(8) << budget[i].categoryBalance;
		cout << left << "\t " << setw(2) << budget[i].categoryName << endl;
	}
}

// Show all budgets from reading with readTransactionstFile 
void Category::showTransactions(void)
{	
	volatile int i = 0;

	cout << "Number of Transaction : " << getTransactionStructSize() << endl << endl << endl;
	cout << "Number  " << "Date  " << "Amount  " << "Description" << endl << endl;
	
	for(i = 0; i < getTransactionStructSize(); i++)
	{
		cout << left 	<< setw(4) 	<< transactions[i].categoryNumber << "\t\t";
		cout << right 	<< setw(8) 	<< transactions[i].transactionDate;
		cout << left 	<< "\t "	<< setw(20) << transactions[i].transactionAmount << "\t ";
		cout << setw(60) << transactions[i].transactionDescription << endl;	
	}	
}

// Destructor
Category::~Category(void)
{

}
