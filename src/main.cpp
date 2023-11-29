#include <iostream>
#include <string>
#include "../include/date.h"
#include "../include/book.h"
#include "../include/book_shelf.h"

int main()
{
	// Test Book and Date constructors
	Book first("Antoine", "de Saint-Exupery", "Le Petit Prince", "207-065-286-6");
	Date second_date(31, 3, 2009);
	Book second("Dan", "Brown", "The Da Vinci Code", "030-747-427-5", second_date);

	// Test BookShelf constructor
	BookShelf shelf(3);

	// Test PushBack
	shelf.PushBack(first);

	// Test PopBack
	shelf.PopBack();

	// Test operator[]
	shelf[0] = first;
	shelf[1] = second;
	
	// Test Size and operator[]
	for(int i=0; i<shelf.Size(); i++)
	{
		std::cout << "n. " << i << ":" << std::endl << shelf[i] << std::endl << std::endl;
	}

	// Test At
	try {
		Book& book = shelf.At(0);
		std::cout << "At 0: " << std::endl << book << std::endl << std::endl;
	} catch (const std::out_of_range& e) {
		std::cerr << "Out of range error: " << e.what() << std::endl << std::endl;
	}

	return 0;
}