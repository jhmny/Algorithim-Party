#include <fstream>
#include <iostream>
#include <string>
#include "List.h"

template<class T>
List<T>::List(int inputSize, std::string name) {
	size = inputSize;
	std::ifstream fin;
	int count;
	count = 0;
	fin.open(name);
	if (fin.fail()) {
		std::cout << "No fin found: " << std::endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			fin >> array[i];	
		}
		fin.close();
	}
};

template<class T>
List<T>::~List()
{
	destory();
};

template<class T>
void List<T>::read(std::string name) {
	destory();
	T* array = new T[size];
	std::ifstream fin;
	int count = 0;
	count = 0;
	fin.open(name);
	if (fin.fail()) {
		std::cout << "No fin found: " << std::endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			fin >> array[i];
		}
		fin.close();
	}
};

template<class T>
void List<T>::write() {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << std::endl;
	}
};

template<class T>
void List<T>::destory() {
	delete[] array;
};