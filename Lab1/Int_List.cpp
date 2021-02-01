#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>
#include "Int_List.h"

using namespace std;

Int_List::Int_List(string name) :List<int>(name)
{
};

Int_List::~Int_List()
{
};

void Int_List::sum3_brute_force()
{
	int counter;
	counter = 0;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) { //brute force search
				if (vect.at(i) + vect.at(j) + vect.at(k) == 0) {
					counter++;
				}
			}
		}
	}
	///*
	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double>elapsed = finish - start;
	cout << "Number of trips: " << counter << endl;
	cout << "Brute Force Elapsed Time : "<< elapsed.count() << "s\n";
};

void Int_List::sum3_bin_search()
{
	int counter;
	counter = 0;
	int lo;
	int mid;
	int hi;
	int test; //variable used to take 3 sum
	sort(vect.begin(), vect.end());
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < vect.size(); i++) { //i is first look
		for (int j = i + 1; j < size; j++) { //implement BS here //j is second look
			lo = j + 1;
			hi = size - 1;

			while (lo <= hi) {
				mid = (hi + lo) / 2; //calc mid point
				test = vect.at(mid) + vect.at(i) + vect.at(j); //is sum == 0?
				if (test == 0) {
					counter++;
					break;
				}
				if (test > 0) { //move left
					hi = mid - 1;
				}
				if (test < 0) { //move right
					lo = mid + 1;
				}
			}
		}
	}

	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double>elapsed = finish - start;
	cout << "BS Elapsed Time : " << elapsed.count() <<  "s\n";
	cout << "Number of trips: " << counter << endl;
};
