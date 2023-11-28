#include "../include/date.h"
#include <stdexcept>
#include <iostream>

bool Date::CheckDate_(int day, int month, int year) const
{
	// Year Check
	if(year<=0 || year>2023){
		return false;
	}

	// Month check
	if(month<=0 || month>12){
		return false;
	}

	// Does day exist?
	if(day<= 0 || day>31){
		return false;
	}

	// Nov, Apr, Jun, Sep have 30 days max
	if(day>30 &&(month==11 || month==4 || month==6 || month==9)){
		return false;
	}

	// Feb can have up to 29 days
	if(day>29 && month==2){
		return false;
	}
	
	// Feb has 29 days only in leap years
	if(day==29 && month==2 && !((year%4==0 && year%100!=0) || year%400==0)){
		return false;
	}

	return true;
}

Date::Date()
{
	day_=1;
	month_=1;
	year_=0;
}

Date::Date(int day, int month, int year)
{
	if(CheckDate_(day, month, year)){
		day_ = day;
		month_ = month;
		year_ = year;
	} else {
		throw std::out_of_range("errore di data ");
	};
}

Date::Date(const Date& other)
{
	day_= other.day_;
	month_=other.month_;
	year_=other.year_;
}


void Date::SetDate(int day, int month, int year)
{
	if(CheckDate_(day, month, year)){
		day_ = day;
		month_ = month;
		year_ = year;
	} else {
		throw std::out_of_range("errore di data ");
	};
}

std::string Date::GetDate() const
{
	std::string a= "";
	a+=" "+ std::to_string(day_);
	a+="/"+ std::to_string(month_);
	a+="/"+ std::to_string(year_);
	return a;
}

// An year "a" is less than an year "b" if "a" comes before "b"
// Ex. 1300<2003
bool Date::operator<(const Date& other) const
{
 if(year_<other.year_){
  return true;
 }
 else if(year_==other.year_ && month_<other.month_ ){
  return true;
 }
 else if(year_==other.year_ && month_==other.month_ && day_<other.day_ ){
  return true;
 }

 return false;
}

bool Date::operator>(const Date& other) const
{
 if(year_>other.year_){
  return true;
 }
 else if(year_==other.year_ && month_>other.month_ ){
  return true;
 }
 else if(year_==other.year_ && month_==other.month_ && day_>other.day_ ){
  return true;
 }

 return false;
}

bool Date::operator==(const Date& other) const
{
	if(year_==other.year_ && month_==other.month_ && day_==other.day_ ){
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Date& other)
{
	return os << other.GetDate();
}