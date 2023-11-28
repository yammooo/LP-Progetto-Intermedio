#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include <string>

class Date{
	private: 
        int day_; // Day of the date
        int month_; // Month of the date
        int year_; // Year of the date

        bool CheckDate_(int d, int m, int y) const; // Checks if a date is valid

	public:
        Date(); // Default constructor
        Date(int day, int month, int year); // Constructor with day, month, and year
        Date(const Date& d); // Copy constructor

		void SetDate(int day,int month, int year);
		std::string GetDateString() const;

		bool operator<(const Date& d) const;
		bool operator>(const Date& d) const;
		bool operator==(const Date& d) const;
};

std::ostream& operator<<(std::ostream& os, const Date& other);

#endif //SRC_DATE_H_