#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
#include <chrono>
#include "List.h"
#include "List.cpp"
#include "Int_List.h"
//yaya
//#include "Int_List.cpp"

using namespace std;

int main()
{
/*
	ofstream file;
	file.open("generatedList.txt");
	std::srand((unsigned)(0));
	int genData;	
	for (int i = 0; i < 100; i++)
	{
		genData = (std::rand() % 90) + 1;
		file << genData;
	}

	file.close();
*/
	
	cout << "Demoing List" << endl;
	int demoSize = 8;
	//string fileName = "generatedList.txt";
	string fileName = "example.txt";
	List<int> demoList(demoSize,fileName);
	demoList.write();

	//cout << "Replacing int List" << endl;
	//demoList.read("replace.txt");
	//demoList.write();
	//string fileName2 = "example2.txt";
	//List<string> demoListString(demoSize,fileName2);
	//demoListString.write();

	cout << "Printing Inherited Class" << endl;
	Int_List demoIntList(demoSize, fileName);
	demoIntList.write();

	cout << "Using Brute" << endl;
	demoIntList.sum3_brute_force();

	cout << "Using BS" << endl;
	demoIntList.sum3_bin_search();

	cin.get();
	return 0;
};
