#include <iostream>
#include <string>
#include "../include/date.h"
#include "../include/book.h"
#include "../include/book_shelf.h"

int main()
{
	Book first("Carlo", "Futu", "Eseprioenza sahdiahgdf", "111-222-333-4");

	Date second_date(1, 12, 2003);
	Book second("Gianni", "Carnu", "asfdfadsgfg", "453-222-333-4", second_date);

	BookShelf shelf(3);

	shelf.PushBack(first);

	shelf.PopBack();

	shelf[0] = first;
	shelf[1] = second;

	for(int i=0; i<shelf.Size(); i++)
	{
		std::cout << "n. " << i << ":\n" << shelf[i] << "\n";
	}
}
