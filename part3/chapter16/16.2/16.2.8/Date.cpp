//
// Created by 王存俊 on 2019/10/17.
//

class Date {
public:
	void add_month(int n);

private:
	int d, m, y;
};

inline void Date::add_month(int n) {
	m += n;
}