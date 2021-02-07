#include<iostream>
#include<vector>
#include <queue>
#include <fstream>
#include <chrono>
#include <random>
#include <list>
#include "N_Puzzle.h"
#include "Source.h"

using namespace std;
//Function Declarations
priority_queue<int> readIntoPQ(string s);
void printQueue(priority_queue<int> q);


int main() {
	std::vector<int> randNums;
	int N;
	N = 9;
	std::cout << "====================================" << std::endl;
	std::cout << "Generating Random List of: " << N << std::endl;
	for (int i = 0; i < N; i++) {
		randNums.push_back(i);
	}

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(randNums.begin(), randNums.end(), default_random_engine(seed));

	ofstream file;
	file.open("generatedList.txt");

	for (int i = 0; i < randNums.size(); i++) {
		file << randNums.at(i) << endl;
	}
	file << -1 << endl;
	cout << "generatedList Done" << endl;
	cout << "====================================" << endl;

	cout << "Testing Queue" << endl;
	priority_queue<int> testQueue = readIntoPQ("generatedList.txt");
	printQueue(testQueue);

	cout << "====================================" << endl;


	N_Puzzle testPuzzle;
	testPuzzle.read("generatedList.txt");
	testPuzzle.writeInitial();
	testPuzzle.writeTarget();
	testPuzzle.solve();

	
}

priority_queue<int> readIntoPQ(string s)
{
	priority_queue<int> returnPQ;
	ifstream fin;
	fin.open(s);
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
				returnPQ.push(NULL);
			}
			else
				returnPQ.push(x);
		}
	}
	fin.close();
	return returnPQ;
}

void printQueue(priority_queue<int> q) {
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
	std::cout << '\n';
}