#include <fstream>
#include <iostream>
#include "N_Puzzle.h"

using namespace std;
void N_Puzzle::isSolvable()
{	//inversion
	vector<vector <int>> solvable;

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
			if (x == 0) {
				initial.push_back(NULL);
			}
			else
				initial.push_back(x);
		}
	}
	fin.close();
}

void N_Puzzle::writeInitial()
{
	for (std::list<int>::iterator i = initial.begin(); i != initial.end(); ++i) {
		cout << " " << *i;
	}
	cout << endl;
}

void N_Puzzle::writeTarget()
{
}

void N_Puzzle::solve()
{
}
