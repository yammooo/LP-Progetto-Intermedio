#include <iostream>
#include <string>
using namespace std;
#include "../include/date.h"

int main(){

 Date giornoio(1,1,1800);

 giornoio.SetDate(30, 6,2003);

 Date giornogian(26, 3, 2004);

 cout<<giornoio.GetDate()<<" \n"<<giornogian.GetDate();
 

 if(giornoio>giornogian){
  cout<<"io ";
 }
 else {
  cout<<"gian";
 }
 
}