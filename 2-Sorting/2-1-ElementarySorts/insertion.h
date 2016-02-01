#include <iostream>

template<class RandomAcessIterator>
void Insertion(RandomAcessIterator first, RandomAcessIterator last){
	for (RandomAcessIterator i = first + 1; i != last; ++i){
		for (RandomAcessIterator j = i; j != first && *j < *(j - 1); --j){
			//! Swap in the inner loop between the neighbor gradually
			std::swap(*j, *(j - 1));
		}
	}
}