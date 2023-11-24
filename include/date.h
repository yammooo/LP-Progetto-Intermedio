#ifndef DATE_H
#define DATE_H

#include <string>

class Date{

	private: 
		int day_;
		int month_;
		int year_;

	public:
		Date();
		Date(int day, int month, int year);
		Date(const Date& d);

		void SetDate(int day,int month, int year);
		std::string GetDate() const;

		bool operator<(Date d);
		bool operator>(Date d);
		bool operator==(Date d);
};

#endif //DATE_H