#include <iostream>

template <class RandomAccessIterator>
void Shell(RandomAccessIterator first, RandomAccessIterator last) {
	int nLength = last - first, h = 0;
	//! Incremental sequence skip list
	while (h < nLength / 3)h = 3 * h + 1;
	while (h >= 1){
		//! the comparasion time is determined by i(h)
		for (RandomAccessIterator i = first + h; i != last; ++i){
			//! j - frist >= h, avoid skipping result from j -= h
			for (RandomAccessIterator j = i; (j - first) >= h && *j < *(j - h); j -= h){
				std::swap(*j, *(j - h));
			}
		}
		h = h / 3;
	}
}