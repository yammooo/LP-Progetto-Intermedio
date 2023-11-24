#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ostream>
#include "date.h"

class Book{
	private:
		std::string first_name_;
		std::string last_name_;
		std::string title_;
		std::string isbn_;
		Date copy_date_;
		bool availability_ = true;
		
	public:
		Book(std::string first_name, std::string last_name, std::string title, std::string isbn, Date copy_date);
		Book(std::string first_name, std::string last_name, std::string title, std::string isbn);
		Book(const Book& other);
		
		std::string GetISBN() const {return isbn_;}
		
		std::string GetTitle() const {return title_;}

		std::string GetAuthorFirstName() const {return first_name_;}

		std::string GetAuthorLastName() const {return last_name_;}
		
		std::string GetAuthorName() const {return first_name_ + " " + last_name_;}
		
		Date GetCopyDate() const {return copy_date_;}

		std::string GetCopyDateString() const {return copy_date_.GetDate();}
		
		bool IsAvailable() const {return availability_;}

		void SetAvailability (bool availability) {availability_ = availability;}
		
		bool operator==(const Book& other) const {return isbn_ == other.isbn_;}
		
		bool operator!=(const Book& other) const{return isbn_ != other.isbn_;}
};


std::ostream& operator<<(std::ostream& os, const Book& other);

#endif //BOOK_H
