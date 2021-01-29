#pragma once
#include "List.h"
class Int_List : public List<int> {
public:	
	//Int_List();
	Int_List(int size, std::string name);
	~Int_List();
	void sum3_brute_force();
	void sum3_bin_search();
};


