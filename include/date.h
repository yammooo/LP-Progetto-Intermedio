#include <string>

class date{

	private: 
		int day;
		int month;
		int year;

	public:
		date();
		date(int day, int month, int year);
		date(const date& d);

		void set_date(int day,int month, int year);
		std::string get_date();

		bool operator<(date d);
		bool operator>(date d);
		bool operator==(date d);
};
