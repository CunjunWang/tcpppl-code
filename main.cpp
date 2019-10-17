//
// Created by 王存俊 on 2019/10/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Base{
public:
	virtual void show() {
		cout << "In base \n";
	}
};

class Derived : public Base {
public:
	void show() override {
		cout << "In derived \n";
	}
};

class Employee {
public:
	virtual void raiseSalary() {
		cout << "raise employee salary" << endl;
	}

	virtual void promote() {
		cout << "promote employee" << endl;
	}
};

class Manager : public Employee {
public:
	void raiseSalary() override {
		cout << "raise manager salary" << endl;
	}

	void promote() override {
		cout << "promote manager" << endl;
	}
};


int main() {
	vector<Employee*> v = {new Employee, new Manager, new Employee};
	for (int i = 0; i < v.size(); i++) {
		v[i]->raiseSalary();
	}
	return 0;
}