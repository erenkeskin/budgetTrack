// User Defined Libraries
#include "Category.h"

using namespace std;

// static
int Category::totalCategoryCount = 0; 
float Category::balanceValue = 0;

//
const string filename = "budget.txt";
const string temporaryFilename = "budgetTemporary.txt";
//
ofstream category_file;
ifstream category_file_read;

// Constructor
Category::Category(string catName, int catNumber = 0)
{
    if(++(this->totalCategoryCount) == 50)
    {
        cout << "You can add only 50 category. You reached this limit." << endl;
    } else {
        cout << "Total Category Count: " << this->totalCategoryCount << endl;
        createFile();
        setCategoryName(catName);
        setCategoryBalance(0.0);
        setCategoryNumber(catNumber);
        addToFile();
        category_file.close();
    }
	
}

//
void Category::createFile(void)
{
	// https://www.studytonight.com/cpp/file-streams-in-cpp.php
    category_file.open(filename, ios::out | ios::app);

    // If file does not exist, Create new file
    if (!category_file) 
    {
        cout << "Cannot open budget file, file does not exist. Creating new file.." << endl;
        category_file.open(filename, ios::out | ios::app);
        category_file.close();
    } else {    // use existing file 
        //cout << "Success " << filename << " found." << endl;
    }
}

//
void Category::setCategoryNumber(int catNumber)
{
    this->categoryList[totalCategoryCount].categoryNumber = catNumber;
}

//
void Category::setCategoryBalance(float balanceNumber)
{
    balanceValue = 0;
    this->categoryList[totalCategoryCount].currentCategoryBalance = balanceNumber;
}

//
void Category::setCategoryName(string catName)
{
    this->categoryList[totalCategoryCount].categoryName = catName;
}

//
void Category::setCurrentCategoryBalance(float balanceNumber)
{
    balanceValue += balanceNumber;
    //this->categoryList[totalCategoryCount].currentCategoryBalance = balanceValue;
    //cout << "Cat Balance: " << this->categoryList[totalCategoryCount].currentCategoryBalance << endl;
}

//
int Category::getCategoryNumber(void) const
{
    return this->categoryList[totalCategoryCount].categoryNumber;
}

//
float Category::getCurrentCategoryBalance(void) const
{
    return this->balanceValue;
}

//
string Category::getCategoryName(void) const
{
    return this->categoryList[totalCategoryCount].categoryName;
}

//
void Category::addToFile(void)
{
    category_file << left << setw(3) << this->getCategoryNumber() << " ";
    category_file << left << setw(9) << this->getCurrentCategoryBalance() << "  ";
    category_file << left << setw(66) << this->getCategoryName() << endl;
}

//
void Category::sortCategoryByNumber(void)
{
    
}

// Destructor
Category::~Category(void)
{
	category_file.close(); // Closing file
}