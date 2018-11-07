#ifndef CATEGORY_H
#define CATEGORY_H

// Standart Libraries
#include <string>
#include <fstream>

using namespace std;

class Category
{

	public:
	    //
	    static int totalCategoryCount;

		// Constructor
		Category(string, int);
		//
		void setCategoryNumber(int);
		//
		void setCurrentCategoryBalance(float);
		//
		void setCategoryName(string);
		//
		int getCategoryNumber(void);
		//
		float getCurrentCategoryBalance(void);
		//
		string getCategoryName(void);
		//
		void addToFile(void);
		//
		void sortCategoryByNumber(void);
		// Destructor
		~Category(void);
		//
		
		
	private:

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
		fstream category_file;
		//
		categoryLists categoryList[50];
		
};

#endif
// #CATEGORY_H
