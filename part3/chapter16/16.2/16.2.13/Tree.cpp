//
// Created by 王存俊 on 2019/10/17.
//

template<typename T>
class Tree {
	using value_type = T;
	enum Policy {
		rb, splay, treeps
	};

	class Node {
		Node *right;
		Node *left;
		value_type value;
	public:
		void f(Tree *);
	};
	Node *top;
public:
	void g(const T &);
};

template<typename T>
void Tree::Node::f(Tree* p) {
	top = right;
	p->top = right;
	value_type v = left->value
}