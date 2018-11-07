// Standart Libraries
#include <iostream>

// User Defined Libraries
#include "Transaction.h"

using namespace std;

// Constructor
Transaction::Transaction(void)
{
	createFile();
}

void Transaction::createFile(void)
{
	transaction_file.open("Transaction.txt", ios::out); // Creating new file
    if(!transaction_file) // Checking whether file exist
    {
        cout << "File creation failed";
    } else {
        cout << "New file created";
    }
}

// Destructor
Transaction::~Transaction(void)
{
	transaction_file.close(); // Closing file
}