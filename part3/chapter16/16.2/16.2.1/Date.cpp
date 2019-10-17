//
// Created by 王存俊 on 2019/10/17.
//

struct Date {
	int d, m, y;

	void init(int dd, int mm, int yy);
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);
};

void Date::init(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}