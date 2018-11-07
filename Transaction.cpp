// Standart Libraries
#include <iostream>
#include <string>
#include <iomanip>

// User Defined Libraries
#include "Transaction.h"

using namespace std;

//static
int Transaction::totalTransactionCount = 0;

// Constructor
Transaction::Transaction(string Description, string Date, float Amount = 0.0)
{
	if(++(this->totalTransactionCount) == 500)
    {
        cout << "You can add only 500 transaction. You reached this limit." << endl;
    } else {
        cout << "Total Transaction Count: " << this->totalTransactionCount << endl;
        createFile();
        setAmount(Amount);
        setDate(Date);
        setDescription(Description);
        addToFile();
    }
}

void Transaction::createFile(void)
{
    string filename = "transaction.txt";

    transaction_file.open(filename, fstream::in | fstream::out | fstream::app);

    // If file does not exist, Create new file
    if (!transaction_file) 
    {
        cout << "Cannot open file, file does not exist. Creating new file..";
        transaction_file.open(filename, fstream::in | fstream::out | fstream::trunc);
        transaction_file.close();
    } else {    // use existing file 
        //cout << "Success " << filename << " found." << endl;
    }
}

//
void Transaction::setAmount(float Amount)
{
	this->transactionList[totalTransactionCount].amount = Amount;
}

//
void Transaction::setDate(string Date)
{
	this->transactionList[totalTransactionCount].date = Date;
}

//
void Transaction::setDescription(string Description)
{
	this->transactionList[totalTransactionCount].description = Description;
}

//
float Transaction::getAmount(void)
{
	return this->transactionList[totalTransactionCount].amount;
}

//
string Transaction::getDate(void)
{
	return this->transactionList[totalTransactionCount].date;
}

//
string Transaction::getDescription(void)
{
	return this->transactionList[totalTransactionCount].description;
}

//
void Transaction::addToFile(void)
{
	transaction_file << left << setw(3) << "101" << " ";
	transaction_file << left << setw(10) << this->getDate() << " ";
    transaction_file << right << setw(9) << this->getAmount() << "  ";
    transaction_file << left << setw(55) << this->getDescription() << endl;
}


// Destructor
Transaction::~Transaction(void)
{
	transaction_file.close(); // Closing file
}