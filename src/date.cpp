#include "../include/date.h"
#include <stdexcept>
#include <iostream>

bool Date::CheckDate_(int d, int m, int y) const
{	
	// Year Check
	if(y<=0 || y>2023){
		return false;
	}

	// Month check
	if(m<=0 || m>12){
		return false;
	}

	// Does day exist?
	if(d<= 0 || d>31){
		return false;
	}

	// Nov, Apr, Jun, Sep have 30 days max
	if(d>30 &&(m==11 || m==4 || m==6 || m==9)){
		return false;
	}

	// Feb can have up to 29 days
	if(d>29 && m==2){
		return false;
	}
	
	// Feb has 29 days only in leap years
	if(d==29 && m==2 && !((y%4==0 && y%100!=0) || y%400==0)){
		return false;
	}

	return true;
}

Date::Date() {
	day_=1;
	month_=1;
	year_=0;
}

Date::Date(int d, int m, int y){

	if(CheckDate_(d, m, y)){
		day_ = d;
		month_ = m;
		year_ = y;
	} else {
		throw std::out_of_range("errore di data ");
	};

}

Date::Date(const Date& d){
	this->day_= d.day_;
	this->month_=d.month_;
	this->year_=d.year_;
}


void Date::SetDate(int d, int m, int y){

	if(CheckDate_(d, m, y)){
		day_ = d;
		month_ = m;
		year_ = y;
	} else {
		throw std::out_of_range("errore di data ");
	};
}

std::string Date::GetDate() const {

	std::string a= "";
	a+=" "+ std::to_string(this->day_);
	a+="/"+ std::to_string(this->month_);
	a+="/"+ std::to_string(this->year_);
	return a;
}

// An year "a" is less than an year "b" if "a" comes before "b"
// Ex. 1300<2003
bool Date::operator<(const Date& d) const {

 if(this->year_<d.year_){
  return true;
 }
 else if(this->year_==d.year_ && this->month_<d.month_ ){
  return true;
 }
 else if(this->year_==d.year_ && this->month_==d.month_ && this->day_<d.day_ ){
  return true;
 }

 return false;

}

bool Date::operator>(const Date& d) const {

 if(this->year_>d.year_){
  return true;
 }
 else if(this->year_==d.year_ && this->month_>d.month_ ){
  return true;
 }
 else if(this->year_==d.year_ && this->month_==d.month_ && this->day_>d.day_ ){
  return true;
 }

 return false;

}

bool Date::operator==(const Date& d) const{
	
	if(this->year_==d.year_ && this->month_==d.month_ && this->day_==d.day_ ){
		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& os, const Date& other)
{
	return os << other.GetDate();
};