//
// Created by 王存俊 on 2019/10/13.
//

struct Vector {
	int sz; // number of elements
	double *elem; // pointer to elements
};

// construct a Vector
void vector_init(Vector &v, int s) {
	v.elem = new double[s]; // allocate an array of s doubles
	v.sz = s;
}

// read s integers from cin and return their sum;
// s is assumed to be positive
double read_and_sum(int s) {
	Vector v;
	vector_init(v, s); // allocate s elements for V
	for (int i = 0; i != s; ++i)
		cin >> v.elem[i]; // read into elements

	double sum = 0;
	for (int i = 0; i != s; ++i)
		sum += v.elem[i]; //take the sum of elements

	return sum;
}