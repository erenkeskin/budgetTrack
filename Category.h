#ifndef CATEGORY_H
#define CATEGORY_H

// Standart Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Category
{

	public:

		// Constructor
		Category(string, int);
		//
		void setCategoryNumber(int);
		//
		void setCategoryBalance(float);
		//
		void setCategoryName(string);
		//
		void setCurrentCategoryBalance(float);
		//
		int getCategoryNumber(void) const;
		//
		float getCurrentCategoryBalance(void) const;
		//
		string getCategoryName(void) const;
		//
		void addToFile(void);
		//
		void sortCategoryByNumber(void);
		// Destructor
		~Category(void);

	    //
	    static int totalCategoryCount;
	    //
		static float balanceValue;
		
		
	private:

		//
		struct category
	    {
	        int categoryNumber;
	        float currentCategoryBalance;
	        string categoryName;
	    };
	    typedef category categoryLists;
	    
		//
		void createFile(void);
		//
		categoryLists categoryList[50];
		
};

#endif
// #CATEGORY_H
