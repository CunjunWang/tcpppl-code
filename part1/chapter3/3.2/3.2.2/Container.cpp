//
// Created by 王存俊 on 2019/10/17.
//

#include "../Vector.cpp"

// interface class
class Container {
public:
	// pure virtual function
	// a class derived from Container must define the function
	// it is not possible to define an object that is just a container.
	// a container can only serve as the interface to a class
	// a class with a pure virtual function is called an abstract class
	virtual double &operator[](int) = 0;

	virtual int size() const = 0;

	virtual ~Container() {};
};

// a real class
class Vector_container : public Container {
	Vector v;

public:
	Vector_container(int s) : v(s) {} // vector of s elements
	~Vector_container() {};

	double& operator[](int i) {
		return v[i];
	}

	int size() const {
		return v.size();
	}
};