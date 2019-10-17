//
// Created by 王存俊 on 2019/10/17.
//

#include <string>
#include <iostream>

using namespace std;

namespace Chrono {
	enum class Month {
		jan = 1,
		feb,
		mar,
		apr,
		may,
		jun,
		jul,
		aug,
		sep,
		oct,
		nov,
		dec
	};

	class Date {
	public: // public interface
		class Bad_date {
		}; // exception class

		explicit Date(int dd = {}, Month mm = {}, int yy = {}); // pick a default

		// non-modifying functions for examining the Date:
		int day() const;

		Month month() const;

		int year() const;

		string string_rep() const; // string representation;
		void char_rep(char s[], int max) const; // c-style string

		// modifying functions for changing the date
		Date &add_year(int n);

		Date &add_month(int n);

		Date &add_day(int n);

	private:
		bool is_valid();

		int d, m, y;
	};

	bool is_date(int d, Month m, int y);

	bool is_leadyear(int y);

	bool operator==(const Date &a, const Date &b);

	bool operator!=(const Date &a, const Date &b);

	const Date &default_date();

	ostream &operator<<(ostream &os, const Date &d); // print d to os
	istream &operator>>(istream &is, Date &d); // read from is into d

	const Date& Chrono::default_date();
}

using namespace Chrono;

void f(Date& d) {
	Date lvb_day {16, Month::dec, d.year()};

	if (d.day() == 29 && d.month() == Month::feb) {

	}

	if (midnight())
		d.add_day(1);

	cout << "day after: " << d + 1 << '\n';

	Date dd;
	cin >> dd;
	if (dd == d)
		cout << "Hurray!\n";
}