#include "../include/date.h"
#include <stdexcept>

Date::Date() {
	day_=1;
	month_=1;
	year_=0;
}

Date::Date(int d, int m, int y){

	if(y<=0 || y>2023){
		throw std::out_of_range("errore di data ");
	}
	year_=y;
	//finito controllo anno

	if(m<=0 || m>12){
		throw std::out_of_range("errore di data ");
	}
	month_=m;
	//finito controllo mese

	if(d<= 0 || d>31){
		throw std::out_of_range("errore di data ");
	}

	if(d>30 &&(m==11 || m==4 || m==6 || m==9)){
		throw std::out_of_range("errore di data ");
	}

	if(d>29 && m==2){
		throw std::out_of_range("errore di data ");
	}
	
	if(d==29 && m==2 && y%4!=0){
		throw std::out_of_range("errore di data ");
	}

	day_=d;

	//finito il controllo del giorno

}

Date::Date(const Date& d){
	this->day_= d.day_;
	this->month_=d.month_;
	this->year_=d.year_;
}


void Date::SetDate(int d, int m, int y){ //uguale al costruttore

	if(y<=0 || y>2023){
		throw std::out_of_range("errore di data ");
	}
	this->year_=y;
	//finito controllo anno

	if(m<=0 || m>12){
		throw std::out_of_range("errore di data ");
	}
	this->month_=m;
	//finito controllo mese

	if(d<= 0 || d>31){
		throw std::out_of_range("errore di data ");
	}

	if(d>30 &&(m==11 || m==4 || m==6 || m==9)){
		throw std::out_of_range("errore di data ");
	}

	if(d>29 && m==2){
		throw std::out_of_range("errore di data ");
	}

	if(d==29 && m==2 && y%4!=0){
		throw std::out_of_range("errore di data ");
	}

	this->day_=d;
}

std::string Date::GetDate() const {

	std::string a= "Data: ";
	a+=" "+ std::to_string(this->day_);
	a+=" "+ std::to_string(this->month_);
	a+=" "+ std::to_string(this->year_);
	return a;
}

bool Date::operator<(Date d){

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

bool Date::operator>(Date d){

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


bool Date::operator==(Date d){
	
	if(this->year_==d.year_ && this->month_==d.month_ && this->day_==d.day_ ){
		return true;
	}

	return false;
}



