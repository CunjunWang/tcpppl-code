//
// Created by 王存俊 on 2019/10/17.
//
#include <string>

using namespace std;

struct cache {
	bool valid;
	string rep;
};

class Date {
	int d, m, y;

	cache *c;

	void compute_cache_value() const;

	static Date default_date;

public:
	Date(int dd = 0, int mm = 0, int yy = 0);

	static void set_default(int dd, int mm, int yy);

	string string_rep() const;

	int day() const { return d; }

	int month() const { return m; }

	int year() const;

	Date &add_year(int n);

	Date &add_month(int n);

	Date &add_day(int n);
};

Date::Date(int dd, int mm, int yy) {
	d = dd ? dd : default_date.d;
	m = mm ? mm : default_date.m;
	y = yy ? yy : default_date.y;
}

void Date::set_default(int dd, int mm, int yy) {
	default_date = {dd, mm, yy};
}

Date &Date::add_year(int n) {
	if (d == 29 && m == 2 && !leapyear(y + n)) {
		d = 1;
		m = 3;
	}
	y += n;
	return *this;
}

string Date::string_rep() const {
	if (!c->valid) {
		compute_cache_value();
		c->valid = true;
	}
	return c->rep;
}

void f(Date d, const Date cd) {
	string s1 = d.string_rep();
	string s2 = cd.string_rep();
}

// error
//int Date::year() const {
//	return ++y;
//}

// error
//int Date::year() {
//	return y;
//}

void f(Date &d, const Date &cd) {
	int i = d.year(); // OK
	d.add_year(1); // OK

	int j = cd.year(); // OK
	// cd.add_year(1); //error

	Date::set_default(4, 5, 1945);
}