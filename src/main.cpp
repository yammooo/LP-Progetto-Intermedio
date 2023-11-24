#include <iostream>
#include <string>
#include "../include/date.h"
#include "../include/book.h"

int main()
{
	Book first("Carlo", "Futu", "Eseprioenza sahdiahgdf", "111-222-333-4");

	Book second = first;

	std::cout << first << std::endl <<second;
}
