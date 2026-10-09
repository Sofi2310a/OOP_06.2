#include <iostream>
using namespace std;

class Data
{
	int day;
	int month;
	int year;

public:
	Data() {}

	Data(int d, int m, int y)
	{
		this->day = d;
		this->month = m;
		this->year = y;
	}

	bool isLeapYear(int y) const
	{
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
			return true;
		}
		else {
			return false;
		}
	}

	int getDay()
	{
		return this->day;
	}
	int getMonth()
	{
		return this->month;
	}
	int getYear()
	{
		return this->year;
	}
	void setDay(int d)
	{
		this->day = d;
	}
	void setMonth(int m)
	{
		this->month = m;
	}
	void setYear(int y)
	{
		this->year = y;
	}

	void PrintInfo()
	{
		cout << "Day: " << day << ", Month: " << month << ", Year: " << year << endl;
	}

	Data& operator++()
	{
		day++;
		return *this;
	}

	Data operator++(int)
	{
		Data temp = *this;
		day++;
		return temp;
	}

	Data& operator--()
	{
		day--;
		return *this;
	}

	Data operator--(int)
	{
		Data temp = *this;
		day--;
		return temp;
	}

	Data operator+(int days)
	{
		return Data(day + days, month, year);
	}

	Data operator-(int days)
	{
		return Data(day - days, month, year);
	}

	int operator-(Data& obj)
	{
		return (year - obj.year) * 360 + (month - obj.month) * 30 + (day - obj.day);
	}

	Data& operator+=(int days)
	{
		day += days;
		return *this;
	}

	Data& operator-=(int days)
	{
		day -= days;
		return *this;
	}

	bool operator==(Data& obj)
	{
		if (year == obj.year && month == obj.month && day == obj.day) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!=(Data& obj)
	{
		if (year != obj.year || month != obj.month || day != obj.day) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator<(Data& obj)
	{
		if (year < obj.year) {
			return true;
		}
		else if (year > obj.year) {
			return false;
		}

		if (month < obj.month) {
			return true;
		}
		else if (month > obj.month) {
			return false;
		}

		if (day < obj.day) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator>(Data& obj)
	{
		if (year > obj.year) {
			return true;
		}
		else if (year < obj.year) {
			return false;
		}

		if (month > obj.month) {
			return true;
		}
		else if (month < obj.month) {
			return false;
		}

		if (day > obj.day) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator<=(Data& obj)
	{
		if (*this > obj) {
			return false;
		}
		else {
			return true;
		}
	}

	bool operator>=(Data& obj)
	{
		if (*this < obj) {
			return false;
		}
		else {
			return true;
		}
	}
};

int main()
{
	Data day1(7, 10, 2009);
	Data day2(17, 6, 2000);
	Data day3(5, 2, 2024);
	day1.PrintInfo();
	day2.PrintInfo();
	day3.PrintInfo();
	++day1;
	day1.PrintInfo();
	day1++;
	day1.PrintInfo();
	--day1;
	day1.PrintInfo();
	day1--;
	day1.PrintInfo();
	Data res1 = day1 + 5;
	res1.PrintInfo();
	Data res2 = day1 - 2;
	res2.PrintInfo();
	cout << day1 - day2 << endl;
	day1 += 10;
	day1.PrintInfo();
	day1 -= 5;
	day1.PrintInfo();
	cout << (day1 == day2) << endl;
	cout << (day1 != day2) << endl;
	cout << (day1 < day2) << endl;
	cout << (day1 > day2) << endl;
	cout << (day1 <= day2) << endl;
	cout << (day1 >= day2) << endl;

	return 0;
}