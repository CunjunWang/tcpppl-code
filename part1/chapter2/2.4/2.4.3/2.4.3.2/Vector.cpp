//
// Created by 王存俊 on 2019/10/13.
//

using namespace std;

class Vector {
public:
	// initialize list:
	// first initialize elem with a pointer to s elements of type double
	// then we initialize sz to s
	// construct a Vector
	Vector(int s) {
		if (s < 0)
			throw length_error{};
		elem = new double[s];
		sz = s;
	}

	// element access: subscripting
	double &operator[](int i) {
		if (i < 0 || size() <= i)
			throw out_of_range("Vector::operator[]");
		return elem[i];
	}

	int size() { return sz; }

private:
	double *elem; // pointer to the elements
	int sz; // the number of elements
};

double read_and_sum(int s) {
	Vector v(s); // make a vector of s elements
	for (int i = 0; i != v.size(); ++i) {
		cin >> v[i]; // read into elements
	}

	double sum = 0;
	for (int i = 0; i != v.size(); ++i) {
		sum += v[i]; // take the sum of the elements
	}

	return sum;
}

// test constructor
void test() {
	try {
		Vector v(-27);
	} catch (length_error) {
		// handle negative size
	} catch (bac_alloc) {
		// handle memory exhaustion
	}
};