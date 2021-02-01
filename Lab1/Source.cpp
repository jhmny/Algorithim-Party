#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
#include <chrono>
#include <algorithm>
#include <random>
#include "List.h"
#include "List.cpp"
#include "Int_List.h"

using namespace std;

int main()
{
	vector<int> randNums;
	int N;
	N = 8000;
	cout << "====================================" << endl;
	cout << "Generating Random List of: " << N * 2 << endl;
	int NN = N * -1;
	for (int i = NN; i <= N; i++) {
		randNums.push_back(i);
	}
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(randNums.begin(), randNums.end(), default_random_engine(seed));
	
	ofstream file;
	file.open("generatedList.txt");

	for(int i = 0; i < randNums.size(); i++) {
		file << randNums.at(i) << endl;
	}

	cout << "generatedList Done" << endl;
	cout << "====================================" << endl;
	
	cout << "Demoing List" << endl;
	string fileName = "example.txt";
	List<int> demoList(fileName);
	demoList.write();
	cout << "====================================" << endl;

	cout << "Replacing int List" << endl;
	demoList.read("replace.txt");
	demoList.write();
	cout << "====================================" << endl;
	cout << "Creating A List of Strings" << endl;	
	string fileName2 = "example2.txt";
	List<string> demoListString(fileName2);
	demoListString.write();
	cout << "replacing List of Strings" << endl;
	demoListString.read("newStrings.txt");
	demoListString.write();

	cout << "====================================" << endl;
	cout << "Printing Inherited List Class" << endl;
	Int_List demoIntList("example.txt");
	demoIntList.write();
	cout << "Replacing Inherited List Class" << endl;
	demoIntList.read("replace.txt");
	demoIntList.write();

	cout << "====================================" << endl;
	cout << "Populating List with generatedList" << endl;
	demoIntList.read("generatedList.txt");

	cout << "Test of N = " << N * 2 << endl;

	cout << "Using Brute" << endl;
	demoIntList.sum3_brute_force();

	//cout << "Using BS" << endl;
	//demoIntList.sum3_bin_search();

	cout << "====================================" << endl;

	cin.get();
	return 0;
};
