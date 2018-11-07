// Standart Libraries
#include <iostream>

// User Defined Libraries
#include "Category.h"

using namespace std;

// Constructor
Category::Category(void)
{
	createFile();
}

void Category::createFile(void)
{
	// https://www.studytonight.com/cpp/file-streams-in-cpp.php
	category_file.open("Category.txt", ios::out); // Creating new file
    if(!category_file) // Checking whether file exist
    {
        cout << "File creation failed";
    } else {
        cout << "New file created";
    }
}

// Destructor
Category::~Category(void)
{
	category_file.close(); // Closing file
}