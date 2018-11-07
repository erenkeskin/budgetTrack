/*
	Eklenecekler:
	- currentCategoryBalance fonksiyonu işlevsel çalışacak.
	- Tarih formatı birden farklı şekilde bile girilse algılayıp gösterilmesi istenilen formata çevirilecek
	- Kategoriye bağlı atama yapılacak
	- Kategori Sıralaması yapılacak (by categoryNumber - ascending)
	- Harcamalar Sıralaması yapılacak (by date - ascending within sorted categoryNumber)
	- Özet fonksiyonu eklenecek, içerisinde ne yapılmış, ne harcanmış listelenecek
	- Son kullanıcı için menü sistemi eklenecek
	- Menü işlevsel hale getirilecek
*/

#include <iostream>
#include "Category.h"
#include "Transaction.h"

using namespace std;

int main(void)
{

	Category category1("catA", 10);

	cout << "Category Number: " << category1.getCategoryNumber() << endl;
	cout << "Category Name: " << category1.getCategoryName() << endl;

	Category category2("catB", 11);

	cout << "Category Number: " << category2.getCategoryNumber() << endl;
	cout << "Category Name: " << category2.getCategoryName() << endl;

	Category category3("catC", 12);

	cout << "Category Number: " << category3.getCategoryNumber() << endl;
	cout << "Category Name: " << category3.getCategoryName() << endl;

	Transaction transaction1("Market1", "2018/11/08", 50.0);

	cout << "Transaction Description: " << transaction1.getDescription() << endl;
	cout << "Transaction Date: " << transaction1.getDate() << endl;
	cout << "Transaction Amount: " << transaction1.getAmount() << endl;

	Transaction transaction2("Market2", "2019/11/08", 150.0);

	cout << "Transaction Description: " << transaction2.getDescription() << endl;
	cout << "Transaction Date: " << transaction2.getDate() << endl;
	cout << "Transaction Amount: " << transaction2.getAmount() << endl;

	Transaction transaction3("Market3", "2020/11/08", 250.0);

	cout << "Transaction Description: " << transaction3.getDescription() << endl;
	cout << "Transaction Date: " << transaction3.getDate() << endl;
	cout << "Transaction Amount: " << transaction3.getAmount() << endl;

	return 0;
}