#pragma once
#include <array>
#include <string>

template <class T>
class List
{
protected:
	int size;
	T* array = new T[size];
	void destory();
	
public:
	List() {}; //constructor
	List(int inputSize, std::string name); //constructor
	~List();
	void read(std::string name);
	void write();
};