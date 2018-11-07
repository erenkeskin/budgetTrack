// Standart Libraries
#include <iostream>
#include <string>
#include <iomanip>

// User Defined Libraries
#include "Category.h"

using namespace std;

//static
int Category::totalCategoryCount = 0;

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
        setCurrentCategoryBalance(0);
        setCategoryNumber(catNumber);
        addToFile();
    }
	
}

void Category::createFile(void)
{
	// https://www.studytonight.com/cpp/file-streams-in-cpp.php
    string filename = "budget.txt";

    category_file.open(filename, fstream::in | fstream::out | fstream::app);

    // If file does not exist, Create new file
    if (!category_file) 
    {
        cout << "Cannot open file, file does not exist. Creating new file..";
        category_file.open(filename, fstream::in | fstream::out | fstream::trunc);
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
void Category::setCurrentCategoryBalance(float balanceNumber)
{
    this->categoryList[totalCategoryCount].currentCategoryBalance = balanceNumber;
}

//
void Category::setCategoryName(string catName)
{
    this->categoryList[totalCategoryCount].categoryName = catName;
}

//
int Category::getCategoryNumber(void)
{
    return this->categoryList[totalCategoryCount].categoryNumber;
}

//
float Category::getCurrentCategoryBalance(void)
{
    return this->categoryList[totalCategoryCount].currentCategoryBalance;
}

//
string Category::getCategoryName(void)
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