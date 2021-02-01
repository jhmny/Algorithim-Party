#pragma once
#include <vector>
#include <string>

template <class T>
class List
{
protected:
	int size;
	std::vector<T> vect;
	void destory();
	
public:
	List() {}; //constructor
	List(std::string name); //constructor
	~List();
	void read(std::string name);
	void write();
};