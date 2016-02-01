#include <iostream>
#include <vector>
#include <string>
#include "selection.h"
#include "insertion.h"
#include "shell.h"

template<class T>
bool isSorted(T t) {
	bool ret = true;
	for (auto i = t.begin(); i != t.end() - 1; ++i) {
		if (*i > *(i + 1)) {
			ret = false;
			break;
		}
	}
	return ret;
};

int main()
{
	// input
	std::vector<std::string> arr;
	std::string s;
	while (std::cin >> s){
		arr.push_back(s);
	}

	// sort
	//Selection(arr.begin(), arr.end());
	//Insertion(arr.begin(), arr.end());
	Shell(arr.begin(), arr.end());

	// print
	for (auto i: arr)
		std::cout << i << ' ';
	if (isSorted(arr))std::cout << "\nThe array is sorted\n";
	else std::cout << "\nThe array is unsorted\n";
	return 0;
}