#ifndef DATE_H
#define DATE_H

#include <string>

class Date{

	private: 
		int day_;
		int month_;
		int year_;
		bool CheckDate_(int d, int m, int y) const;

	public:
		Date();
		Date(int day, int month, int year);
		Date(const Date& d);

		void SetDate(int day,int month, int year);
		std::string GetDate() const;

		bool operator<(const Date& d) const;
		bool operator>(const Date& d) const;
		bool operator==(const Date& d) const;
};

std::ostream& operator<<(std::ostream& os, const Date& other);

#endif //DATE_H