#include <vector>

template<class T>
void Merge(std::vector<T> &src, std::vector<T> &dest, int nHead, int nMid, int nEnd) {
	int nLeftIndex = nHead, nRightIndex = nMid;
	for (int i = nHead; i < nEnd; ++i){
		// Detail: Use range[nHead, nEnd)
		if (nLeftIndex >= nMid) dest[i] = src[nRightIndex++];
		else if (nRightIndex >= nEnd) dest[i] = src[nLeftIndex++];
		else if (src[nLeftIndex] < src[nRightIndex]) dest[i] = src[nLeftIndex++];
		else dest[i] = src[nRightIndex++];
	}
}

template<class T>
void MergeSort(std::vector<T> &src, std::vector<T> &dest, int nHead, int nEnd) {
	// Optimization 1: Use InsertSort when small scale
	if (nEnd - nHead <= 15) {
		InsertSort(dest, nHead, nEnd);
		return;
	}
	int nMid = (nHead + nEnd) / 2;
	// Optimization 2: Avoid copying to auxiliary array
	MergeSort(dest, src, nHead, nMid);
	MergeSort(dest, src, nMid, nEnd);
	// Optimization 3: If the sub-array is sorted then skip merge
	if (src[nMid - 1] <= src[nMid]){
		std::copy(src.begin() + nHead, src.begin() + nEnd, dest.begin() + nHead);
	}
	else Merge(src, dest, nHead, nMid, nEnd);
}

/* 
 * Merge Sort from button up
 */
template<class T>
void Merge(std::vector<T> &vec, int nHead, int nMid, int nEnd) {
	std::vector<T> tmp(vec);
	int nLeftIndex = nHead, nRightIndex = nMid;
	for (int i = nHead; i < nEnd; ++i){
		if (nLeftIndex >= nMid) vec[i] = tmp[nRightIndex++];
		else if (nRightIndex >= nEnd) vec[i] = tmp[nLeftIndex++];
		else if (tmp[nLeftIndex] < tmp[nRightIndex]) vec[i] = tmp[nLeftIndex++];
		else vec[i] = tmp[nRightIndex++];
	}
}

template<class T>
void MergeSortBU(std::vector<T> &vec, int nHead, int nEnd) {
	int nLength = nEnd - nHead;
	for (int sz = 1; sz < nLength; sz += sz){
		for (int i = nHead; i < nLength - sz; i = i + sz + sz){
			int nMin = nLength < i + sz + sz ? nLength : i + sz + sz;
			Merge(vec, i, i + sz, nMin);
		}
	}
}