#include <string>
#include <stdexcept>
#include "../include/book.h"

Book::Book() :
    first_name_{""},
    last_name_{""},
    title_{""},
    isbn_{""},
    copy_date_{Date()}
    {};

Book::Book(std::string first_name, std::string last_name, std::string title, std::string isbn, Date copy_date) :
    first_name_{first_name},
    last_name_{last_name},
    title_{title},
    isbn_{isbn},
    copy_date_{copy_date}
    {
        if(isbn.length() != 13){
            throw std::out_of_range("ISBN out of length");
        }
    };

Book::Book(std::string first_name, std::string last_name, std::string title, std::string isbn) :
    first_name_{first_name},
    last_name_{last_name},
    title_{title},
    isbn_{isbn}
    {
        if(isbn.length() != 13){
            throw std::out_of_range("ISBN out of length");
        }
    };

Book::Book(const Book& other) :
    first_name_{other.first_name_},
    last_name_{other.last_name_},
    title_{other.title_},
    isbn_{other.isbn_},
    copy_date_{other.copy_date_},
    availability_{other.availability_}
    {};

std::ostream& operator<<(std::ostream& os, const Book& other)
{
	return os << "Title: " << other.GetTitle() << std::endl << "Author: " << other.GetAuthorName() << std::endl << "ISBN: " << other.GetISBN();
}