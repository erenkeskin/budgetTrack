// User Defined Libraries
#include "Transaction.h"
#include "Category.h"

using namespace std;

// static
int Transaction::totalTransactionCount = 0;

//
const string filename = "transaction.txt";
const string temporaryFilename = "transactionTemporary.txt";

//
fstream transaction_file;

// Constructor
Transaction::Transaction(Category &categoryID, string Description, string Date, float Amount = 0.0)
	: categoryObject(categoryID)
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
        categoryObject.setCurrentCategoryBalance(this->getAmount());
        categoryObject.addToFile();
        addToFile(categoryObject.getCategoryNumber());
        transaction_file.close();
    }
}

//
void Transaction::createFile(void)
{
    transaction_file.open(filename, fstream::in | fstream::out | fstream::app);

    // If file does not exist, Create new file
    if (!transaction_file) 
    {
        cout << "Cannot open transaction file, file does not exist. Creating new file.." << endl;
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
float Transaction::getAmount(void) const
{
	return this->transactionList[totalTransactionCount].amount;
}

//
string Transaction::getDate(void) const
{
	return this->transactionList[totalTransactionCount].date;
}

//
string Transaction::getDescription(void) const
{
	return this->transactionList[totalTransactionCount].description;
}

//
void Transaction::addToFile(int categoryNumber)
{
	transaction_file << left << setw(3) << categoryNumber << " ";
	transaction_file << left << setw(10) << this->getDate() << " ";
    transaction_file << right << setw(9) << this->getAmount() << "  ";
    transaction_file << left << setw(55) << this->getDescription() << endl;
}

// Destructor
Transaction::~Transaction(void)
{
	transaction_file.close(); // Closing file
}