#include <fstream>
#include <iostream>
#include "N_Puzzle.h"

using namespace std;
bool N_Puzzle::isSolvable()

{
	//inversion
	int size = 0;
	int inversion = 0;
	size = sqrt(initial.size());
	//vector<vector <int>> solvable;
	for(list<int>::iterator i = initial.begin(); i != initial.end(); ++i) { //iterator i does not break
		for (list<int>::iterator j = ++i; j != initial.end(); ++j) {
			if (*i < *j) {
				inversion++;
			}
		}
	}
	cout << inversion << endl;
	return 0;
}

void N_Puzzle::bestFirst()
{
}

void N_Puzzle::read(std::string inputfile)
{
	ifstream fin;
	fin.open(inputfile);
	if (fin.fail()) {
		cout << "No fin found: " << endl;
	}
	else {
		while (!fin.eof())
		{
			int x;
			fin >> x;
			if (x == -1)
				break;
			if (x == 0) {
				initial.push_back(NULL);
			}
			else
				initial.push_back(x);
		}
	}
	fin.close();
	goal = initial;
	goal.sort();
}

void N_Puzzle::writeInitial()
{
	for (std::list<int>::iterator i = initial.begin(); i != initial.end(); ++i) {
		cout << " " << *i;
	}
	cout << endl;
	int size = 0;
	size = sqrt(initial.size());
	auto p = initial.begin();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (p == initial.end())
				break;
			if (*p == 0)
				cout << " " << " ";
			else
				cout << *p << " ";
			advance(p, 1);
		}
		cout << endl;
	}
}

void N_Puzzle::writeTarget()
{
	for (std::list<int>::iterator i = goal.begin(); i != goal.end(); ++i) {
		cout << " " << *i;
	}
	cout << endl;
	int size = 0;
	size = sqrt(goal.size());
	auto p = goal.begin();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (p == goal.end())
				break;
			if (*p == 0)
				cout << " " << " ";
			else
				cout << *p << " ";
			advance(p, 1);
		}
		cout << endl;
	}
}

void N_Puzzle::solve()
{
	isSolvable();
}
