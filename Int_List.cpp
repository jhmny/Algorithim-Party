#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>
#include "Int_List.h"


Int_List::Int_List(int size, std::string name) :List<int>(size, name)
{
};

Int_List::~Int_List()
{
};

void Int_List::sum3_brute_force()
{
	int counter;
	counter = 0;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) { //brute force search
				if (array[i] + array[j] + array[k] == 0) {
					counter++;
				}
			}
		}
	}
	///*
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double>elapsed = finish - start;
	std::cout << "Number of trips: " << counter << std::endl;
	std::cout << "Brute Force Elapsed Time : "<< /*elapsed.count() << */ "s\n";
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (finish - start).count() << "ns" << std::endl;
	//std::cout << std::chrono::duration<double>(finish - start).count() << " s\n";
	//*/
};

void Int_List::sum3_bin_search()
{
	int counter;
	counter = 0;
	int lo;
	int mid;
	int hi;
	int test; //variable used to take 3 sum
	std::sort(array, array + size);
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < size; i++) { //i is first look
		for (int j = i + 1; j < size; j++) { //implement BS here //j is second look
			lo = j + 1;
			hi = size - 1;

			while (lo <= hi) {
				mid = (hi + lo) / 2; //calc mid point
				test = array[mid] + array[i] + array[j]; //is sum == 0?
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
	///*
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double>elapsed = finish - start;
	//std::cout << "Brute Force Elapsed Time : " << /*elapsed.count() << */ "s\n";
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (finish - start).count() << "ns" << std::endl;
	std::cout << "Number of trips: " << counter << std::endl;
	//*/
};
