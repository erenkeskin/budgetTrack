#ifndef TRANSACTION_H
#define TRANSACTION_H

// Standart Libraries
#include <string>
#include <fstream>

using namespace std;

class Transaction
{
	
	public:
		// Constructor
		Transaction(void);
		// Destructor
		~Transaction(void);
		//
		
		
	private:
		//
		void createFile(void);
		//
		ofstream transaction_file;

};

#endif
// #TRANSACTION_H
