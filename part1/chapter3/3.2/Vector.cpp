//
// Created by 王存俊 on 2019/10/17.
//

#include <initializer_list>
#include <algorithm>

using namespace std;

template<typename T>
class Vector {
private:
	T *elem; // element points to an array
	int sz;

public:
	// constructor
	Vector(int s) {
		if (s < 0)
			throw Negative_size{"Vector consturctor"};

		elem = new T[s];
		sz = s;
	}

	// initialize with a list
	Vector(initializer_list<T> list)
			: elem{new T[list.size()]}, sz{(int) list.size()} {
		copy(list.begin(), list.end(), elem);
	}

	// add element
	void push_back(T d) {
		elem[sz] = d;
		sz++;
	}

	~Vector() {
		delete[] elem;
	}

	const T &operator[](int i) const {
		if (i < 0 || size() <= i)
			throw out_of_range{"Vector::operator[]"};
		return elem[i];
	}

	int size() const {
		return sz;
	}

	// copy constructor
	Vector(const Vector &a)
			: elem{new double[a.sz]}, sz{a.sz} {
		for (int i = 0; i < sz; i++) {
			elem[i] = a.elem[i];
		}
	}

	// copy assignment
	Vector &operator=(const Vector &a) {
		double *p = new double[a.sz];
		for (int i = 0; i < a.sz; i++) {
			p[i] = a.elem[i];
		}
		// free space, delete old elem
		delete[] elem;
		elem = p;
		sz = a.sz;
		return *this;
	}

	Vector operator+(const Vector &a, const Vector &b) {
		if (a.size() != b.size())
			throw Vector_size_mismatch{};

		Vector res(a.size());
		for (int i = 0; i < a.size(); i++) {
			res[i] = a[i] + b[i];
		}
		return res;
	}

	// pointer to the first element
	T* begin(Vector<T>& x) {
		return &x[0];
	}

	T* end(Vector<T>& x) {
		return x.begin() + x.size();
	}
};
