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
#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// All Budget store in this structure
struct Budget
{
	int categoryNumber;
	string categoryBalance;
	string categoryName;
};

// All Transactions store in this structure
struct Transactions
{
	int categoryNumber;
	string transactionDate;
	string transactionAmount;
	string transactionDescription;
};

// Category Object
class Category
{
	// Write and Read data from Budget.txt easily with friend functions
	friend ostream &operator<<(ostream &, const Budget &);
	friend istream &operator>>(istream &, Budget &);
	
	// Write and Read data from Transactions.txt easily with friend functions
	friend ostream &operator<<(ostream &, const Transactions &);
	friend istream &operator>>(istream &, Transactions &);
	
	public:
		// Constructor
		Category(void);
		// Read data from Budget.txt
		void readBudgetFile(void);
		// Read data from Transactions.txt
		void readTransactionFile(void);
		// Write data to Budget.txt
		void writeBudgetFile(void);
		// Write data to Transactions.txt
		void writeTransactionFile(void);
		// List all budgets
		void showBudgets(void);
		// List all Transactions
		void showTransactions(void);
		// Get Budget Structure Size
		static int getBudgetStructSize();
		// Get Transactions Structure Size
		static int getTransactionStructSize();

		// Maximum Budget size 50
		Budget budget[50];
		// Maximum Transactions size 500
		Transactions transactions[500];
		
		// Destructor
		~Category(void);
	
	private :
		//
		static int budgetStructSize;
		static int transactionStructSize;	

};

#endif
