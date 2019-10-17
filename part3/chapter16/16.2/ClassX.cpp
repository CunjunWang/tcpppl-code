//
// Created by 王存俊 on 2019/10/17.
//

class X {
private:
	int m;

public:
	X(int i = 0) : m{i} {}

	int mf(int i) {
		int old = m;
		m = i;
		return old;
	}
};

int user(X var, X* ptr) {
	int x = var.mf(7);
	int y = ptr->mf(9);
	// int z = var.m; // error, cannot access private member.
	return 0;
}

int main() {
	X var = {7};
}
