//
// Created by 王存俊 on 2019/10/17.
//

#include <string>
#include <list>

using namespace std;

struct Employee {
	string first_name, family_name;
	char middle_initial;
	short department;
};

struct Manager : public Employee {
	Employee emp; // manager's employee record
	list<Employee *> group; // people managed
	short level;
};

void f(Manager m1, Employee e1) {
	list<Employee *> elist(&e1, &m1);
}
