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
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Category.h"

using namespace std;

// Transaction Class
class Transaction
{
	public:
		// Constructor
		Transaction(Category & categoryObjectReference);
			
		//	Menu for users
		void menu(void);
		// Sort all budget data depended category number
		void sortBudgetData(void);
		// Sort all transaction data depended category number
		void sortTransactionData(void);
		// Show sample report
		void sampleReport(void);
		// Destructor
		~Transaction(void);

	private:
		Category categoryObject;

};

#endif
