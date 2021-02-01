#include <fstream>
#include <iostream>
#include <string>
#include "List.h"

using namespace std;
template<class T>
List<T>::List(string name) {
	string n = name;
	read(n);
};

template<class T>
List<T>::~List()
{
	destory();
};

template<class T>
void List<T>::read(string name) {
	destory();
	ifstream fin;
	int count = 0;
	count = 0;
	fin.open(name);
	if (fin.fail()) {
		cout << "No fin found: " << endl;
	}
	else {
		
		while (!fin.eof())
		{
			T x;
			fin >> x;
			vect.push_back(x);
		}
	}
	size = vect.size();
	fin.close();
};

template<class T>
void List<T>::write() {
	for (int i = 0; i < size; i++) {
		cout << vect.at(i) << endl;
	}
};

template<class T>
void List<T>::destory() {
	vect.clear();
	vect.shrink_to_fit();
};