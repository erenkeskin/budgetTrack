#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Category.h"

using namespace std;

class Transaction
{
	
	public:
		// Constructor
		Transaction(Category &categoryID, string, string, float);
		//
		void setAmount(float);
		//
		void setDate(string);
		//
		void setDescription(string);
		//
		float getAmount(void) const;
		//
		string getDate(void) const;
		//
		string getDescription(void) const;
		//
		void addToFile(int);
		// Destructor
		~Transaction(void);		

		//
	    static int totalTransactionCount;

	private:

		//
		Category categoryObject;

		struct transaction
	    {
	        float amount;
	        string date;
	        string description;
	    };
	    typedef transaction transactionLists;
	    
		//
		void createFile(void);

		//
		transactionLists transactionList[500];

};

#endif
// #TRANSACTION_H
