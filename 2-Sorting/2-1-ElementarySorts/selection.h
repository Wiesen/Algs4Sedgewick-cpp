#include <iostream>

template<class RandomAccessIterator>
void Selection(RandomAccessIterator first, RandomAccessIterator last) {
	 for (RandomAccessIterator i = first; i != last; ++i) {
		 RandomAccessIterator min = i;
		 for (RandomAccessIterator j = i + 1; j != last; ++j) {
			 if (*j < *min)
				 min = j;
		 }
		 //! Swap in the outper loop between the min and objective-position
		 std::swap(*i, *min);
	}
};