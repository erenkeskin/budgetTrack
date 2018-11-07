#ifndef TRANSACTION_H
#define TRANSACTION_H

// Standart Libraries
#include <string>
#include <fstream>

using namespace std;

class Transaction
{
	
	public:
		//
	    static int totalTransactionCount;

		// Constructor
		Transaction(string, string, float);
		//
		void setAmount(float);
		//
		void setDate(string);
		//
		void setDescription(string);
		//
		float getAmount(void);
		//
		string getDate(void);
		//
		string getDescription(void);
		//
		void addToFile(void);
		// Destructor
		~Transaction(void);		
		
	private:
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
		fstream transaction_file;
		//
		transactionLists transactionList[500];

};

#endif
// #TRANSACTION_H
