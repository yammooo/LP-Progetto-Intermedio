#include <iostream>
#include <string>
using namespace std;
#include "date.h"

int main(){

	date giorno1(1,1,2003);

	giorno1.set_date(30, 6,2003);

	date giorno2(26, 3, 2003);

	cout<<giorno1.get_date()<<" \n"<<giorno2.get_date();
	giorno2 = giorno1;

	if(giorno1==giorno2){
		cout<<"gian ";
	}
	else {
		cout<<"io";
	}
	
}