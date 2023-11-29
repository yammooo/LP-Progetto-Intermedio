#ifndef LP_INCLUDE_BOOK_H_
#define LP_INCLUDE_BOOK_H_

#include <string>
#include <ostream>
#include "date.h"

class Book{
	private:
        std::string first_name_; // Author's first name
        std::string last_name_; // Author's last name
        std::string title_; // Title of the book
        std::string isbn_; // ISBN of the book
        Date copy_date_; // Date of the copyright of the book
        bool availability_ = true; // Availability of the book
		
	public:
        Book(); // Default constructor
        Book(std::string first_name, std::string last_name, std::string title, std::string isbn, Date copy_date);
        Book(std::string first_name, std::string last_name, std::string title, std::string isbn);
        Book(const Book& other); // Copy constructor
		
		std::string GetISBN() const {return isbn_;}
		
		std::string GetTitle() const {return title_;}

		std::string GetAuthorFirstName() const {return first_name_;}

		std::string GetAuthorLastName() const {return last_name_;}
		
		std::string GetAuthorName() const {return first_name_ + " " + last_name_;}
		
		Date GetCopyDate() const {return copy_date_;}

		std::string GetCopyDateString() const {return copy_date_.GetDateString();}
		
		bool IsAvailable() const {return availability_;}

		void SetAvailability (bool availability) {availability_ = availability;}
		
		bool operator==(const Book& other) const {return isbn_ == other.isbn_;}
		
		bool operator!=(const Book& other) const{return isbn_ != other.isbn_;}

		// Copy assignment and move constructor/assignment are unecessary because of no pointers in book, therefore a shallow copy and deep copy are the same.
};


std::ostream& operator<<(std::ostream& os, const Book& other);

#endif // LP_INCLUDE_BOOK_H_