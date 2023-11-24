#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ostream>

class Book{
	private:
		std::string _ISBN;
		std::string _title;
		std::string _firstName;
		std::string _lastName;
		// Date _copyDate;
		bool _isAvailable = true;
		
	public:
		Book(std::string firstName, std::string lastName, std::string title, std::string ISBN);
		
		std::string getISBN() const {return _ISBN;}
		
		std::string getTitle() const {return _title;}
		
		std::string getAuthorName() const {return _firstName + " " + _lastName;}
		
		// Date getCopyDate() const {return _copyDate;}
		
		bool isAvailable() const {return _isAvailable;}
		
		bool operator==(const Book& other) const
		{
			return _ISBN == other._ISBN;
		}
		
		bool operator!=(const Book& other) const
		{
			return _ISBN != other._ISBN;
		}
};

std::ostream& operator<<(std::ostream& os, const Book& other)
{
	return os << "Title: " << other.getTitle() << std::endl << "Author: " << other.getAuthorName() << std::endl << "ISBN: " << other.getISBN();
}

#endif //BOOK_H
