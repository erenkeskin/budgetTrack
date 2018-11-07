#ifndef CATEGORY_H
#define CATEGORY_H

// Standart Libraries
#include <string>
#include <fstream>

using namespace std;

class Category
{

	public:
		// Constructor
		Category(void);
		// Destructor
		~Category(void);
		//
		
		
	private:
		//
		void createFile(void);
		//
		ofstream category_file;

};

#endif
// #CATEGORY_H
