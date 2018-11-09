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
#include "Transaction.h"

using namespace std;

int main(void)
{

	Category category1("catA", 301);
	Transaction transaction1(category1, "Market1", "2018/11/08", 50.0);
	cout << "Main Cat Balance: " <<  category1.getCurrentCategoryBalance() << endl << endl;
	Transaction transaction4(category1, "Market4", "2018/11/08", 50.0);
	cout << "Main Cat Balance: " <<  category1.getCurrentCategoryBalance() << endl << endl;
	Transaction transaction5(category1, "Market5", "2018/11/08", 50.0);
	cout << "Main Cat Balance: " <<  category1.getCurrentCategoryBalance() << endl << endl;
	Transaction transaction6(category1, "Market6", "2018/11/08", 50.0);
	cout << "Main Cat Balance: " <<  category1.getCurrentCategoryBalance() << endl << endl;
	Category category2("catB", 113);
	Transaction transaction2(category2, "Market2", "2019/11/08", 150.0);
	Category category3("catC", 254);
	Transaction transaction3(category3, "Market3", "2020/11/08", 250.0);

	string haystack("some string with words in it");

    string::size_type pos = haystack.find("words");
    if(pos != string::npos)
    {
        cout << "found \"words\" at position " << pos << endl;
    }
    else
    {
        cout << "\"words\" not found" << endl;
    }

	return 0;
}