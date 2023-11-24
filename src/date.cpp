#include "date.h"
#include <stdexcept>


date::date(){

	day=1;
	month=1;
	year=0;
}


date::date(int d, int m, int y){

	if(y<0 || y>2023){
		throw std::out_of_range("errore di data ");
	}
	year=y;
	//finito controllo anno

	if(m<=0 || m>12){
		throw std::out_of_range("errore di data ");
	}
	month=m;
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

	day=d;

	//finito il controllo del giorno

}

date::date(const date& d){

	this->day= d.day;
	this->month=d.month;
	this->year=d.year;
}


void date::set_date(int d, int m, int y){ //uguale al costruttore

	if(y<0 || y>2023){
		throw std::out_of_range("errore di data ");
	}
	this->year=y;
	//finito controllo anno

	if(m<=0 || m>12){
		throw std::out_of_range("errore di data ");
	}
	this->month=m;
	//finito controllo mese

	if(d<= 0 || d>31){
		throw std::out_of_range("errore di data ");
	}

	if(d>30 &&(m==11 || m==4 || m==6 || m==9)){
		throw std::out_of_range("errore di data ");
	}

	if(d>28 && m==2){
		throw std::out_of_range("errore di data ");
	}

	this->day=d;
}

std::string date::get_date(){

	std::string a= "Data: ";
	a+=" "+ std::to_string(this->day);
	a+=" "+ std::to_string(this->month);
	a+=" "+ std::to_string(this->year);
	return a;
}

bool date::operator<(date d){

	if(this->year<d.year){
		return true;
	}
	else if(this->year==d.year && this->month<d.month ){
		return true;
	}
	else if(this->year==d.year && this->month==d.month && this->day<d.day ){
		return true;
	}

	return false;

}

bool date::operator>(date d){

	if(this->year>d.year){
		return true;
	}
	else if(this->year==d.year && this->month>d.month ){
		return true;
	}
	else if(this->year==d.year && this->month==d.month && this->day>d.day ){
		return true;
	}

	return false;

}


bool date::operator==(date d){

	
	if(this->year==d.year && this->month==d.month && this->day==d.day ){
		return true;
	}

	return false;

}



