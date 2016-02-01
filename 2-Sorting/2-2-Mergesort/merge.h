#include <iostream>
#include <vector>
#include <string>

/* 
 * Attention:
 * The code is consistent with the  ttandard iterator ranges [begin, end) instead of [begin, end], 
 * the following is reason (by Dijkstra himself):
 * 1. You want the size of the range to be a simple difference end − begin;
 * 2. Including the lower bound is more "natural" when sequences degenerate to empty ones, 
 *    and also because the alternative(excluding the lower bound) would require 
 *    the existence of a "one-before-the-beginning" sentinel value.
 */
void merge(std::vector<std::string> &arr, const int nHead, const int nMid, const int nEnd) {
	std::vector<std::string> tmp = arr;
	int nLeftIndex = nHead, nRightIndex = nMid;
	//! the beginning position is nHead
	for (int i = nHead; i != nEnd; ++i){
		if (nLeftIndex >= nMid)arr[i] = tmp[nRightIndex++];
		else if (nRightIndex >= nEnd)arr[i] = tmp[nLeftIndex++];
		else if (tmp[nLeftIndex] < tmp[nRightIndex])arr[i] = tmp[nLeftIndex++];
		else arr[i] = tmp[nRightIndex++];
	}
}

void MergeSort(std::vector<std::string> &arr, const int nHead, const int nEnd) {
	if (nEnd - nHead <= 1)return;
	int nMid = (nHead + nEnd) / 2;
	MergeSort(arr, nHead, nMid);
	MergeSort(arr, nMid, nEnd);
	merge(arr, nHead, nMid, nEnd);
}