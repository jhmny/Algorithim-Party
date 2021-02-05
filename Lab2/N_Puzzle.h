#pragma once
#include <vector>
#include <list>
#include <string>
#include<queue>
class N_Puzzle
{
private:
	std::list<int> initial;
	std::list<int> goal;
	std::list<int> solution;
	void isSolvable();
	void bestFirst();
public:
	N_Puzzle() {}; //constructor
	~N_Puzzle(){};
	void read(std::string inputfile);
	void writeInitial();
	void writeTarget();
	void solve();
};