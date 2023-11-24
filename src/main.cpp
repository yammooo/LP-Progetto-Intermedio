#include <iostream>
#include <string>
#include "../include/date.h"
#include "../include/book.h"
#include "../include/book_shelf.h"

int main()
{
	Book first("Carlo", "Futu", "Eseprioenza sahdiahgdf", "111-222-333-4");

	BookShelf shelf(10);

	shelf.push_back(first);

	shelf.pop_back();

	shelf[5] = first;

	for(int i=0; i<10; i++)
	{
		std::cout << "n. " << i << ":\n" << shelf[i] << "\n";
	}
}
