#include<iostream>
#include<vector>
#include <queue>
#include <fstream>
#include <chrono>
#include <random>
#include <list>
#include "N_Puzzle.h"

using namespace std;
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
	cout << "generatedList Done" << endl;
	cout << "====================================" << endl;

	N_Puzzle testPuzzle;
	testPuzzle.read("generatedList.txt");
	testPuzzle.writeInitial();


	
}