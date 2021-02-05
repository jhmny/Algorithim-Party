#pragma once
#include <vector>
#include <string>
#include <list>

template <class T>
class pq
{
private:
	std::vector<T> initial;
	std::vector<T> goal;
	std::list<T> solution;
	void is_solvable();
	void best_first();
public:
	pq() {}; //constructor
	void read(std::string inputfile);
	~pq();
	void write_initial();
	void write_target();
	void solve();
};