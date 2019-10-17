//
// Created by 王存俊 on 2019/10/17.
//

class Date {
	int d, m, y;
public:
	explicit Date(int dd = 0, int mm = 0, int yy = 0);
};

Date d1{15}; // OK, considered explicit
Date d2 = Date{15}; // OK, explicit
// Date d3 = {15}; // error, = initialization does not do implicit conversions.
// Date d4 = 15; // error;

void my_fct(Date d);

void f() {
	// my_fct(15); // error
	// my_fct({15}); // error
	my_fct(Date{15}); // ok;
}