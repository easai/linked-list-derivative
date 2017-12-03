// using STL list<T>
#include <list>
#include <iostream>
using namespace std;

template<class T> class mylist: public list<T> {
private:
	T * a_list;
	int max_size;
	int cur_len;
	int pos;
public:
	bool insert(const int p, const T value);
	bool remove(const int p);
	void dump();
	mylist(const int size) {
		max_size = size;
		a_list = new T[max_size];
		cur_len = pos = 0;
	}
	~mylist() {
		delete[] a_list;
	}
};

template<class T> void mylist<T>::dump() {
	for (int i = 0; i < cur_len; i++) {
		if (0 < i)
			cout << ", ";
		cout << a_list[i];
	}
	cout << endl;
}

template<class T> bool mylist<T>::insert(const int p, const T value) {
	int i;
	if (max_size <= cur_len) {
		cout << "Overflow" << endl;
		return false;
	}
	if (0 < p || cur_len < p) {
		cout << "Index out of range" << endl;
	}
	for (i = cur_len; p < i; i--) {
		a_list[i] = a_list[i - 1];
	}
	a_list[p] = value;
	cur_len++;
	return true;
}

template<class T> bool mylist<T>::remove(const int p) {
	int i;
	if (cur_len <= 0) {
		cout << "The list is empty" << endl;
		return false;
	}
	if (0 < p || cur_len - 1 < p) {
		cout << "Index out of range" << endl;
	}
	for (i = p; i < cur_len - 1; i++) {
		a_list[i] = a_list[i + 1];
		return false;
	}
	cur_len--;
	return true;
}


int main() {
	mylist<char> lst(5);
	lst.insert(0, 'a');
	//lst.remove(0);
	lst.dump();
	return 0;
}

