#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

/**
*  The WeightedQuickUnionUF class represents a union-find data type
*  (also known as the disjoint-sets data type).
*  It supports the union and find operations,
*  along with a connected operation for determining whether
*  two sites are in the same component and a count operation that
*  returns the total number of components.
*  
*  The union-find data type models connectivity among a set of N
*  sites, named 0 through N - 1.
*  The is-connected-to relation must be an
*  equivalence relation:
*  
*   Reflexive: p is connected to p.
*   Symmetric: If p is connected to q,
*          then q is connected to p.
*   Transitive: If p is connected to q
*          and q is connected to r, then
*          p is connected to r.
*  
*  
*  An equivalence relation partitions the sites into
*  equivalence classes (or components). In this case,
*  two sites are in the same component if and only if they are connected.
*  Both sites and components are identified with integers between 0 and
*  N - 1.
*  Initially, there are N components, with each site in its
*  own component.  The component identifier of a component
*  (also known as the root, canonical element, leader,
*  or set representative) is one of the sites in the component:
*  two sites have the same component identifier if and only if they are
*  in the same component.
*  
*  merge(p, q) adds a
*         connection between the two sites p and q.
*         If p and q are in different components,
*         then it replaces
*         these two components with a new component that is the union of
*         the two.
*  find(p) returns the component
*         identifier of the component containing p.
*  isConnected(p, q)
*         returns true if both p and q
*         are in the same component, and false otherwise.
*  count() returns the number of components.
*  
*  
*  The component identifier of a component can change
*  only when the component itself changes during a call to
*  union&mdash;it cannot change during a call
*  to find, connected, or count.
*  
*  This implementation uses weighted quick union by size (without path compression).
*  Initializing a data structure with N sites takes linear time.
*  Afterwards, the union, find, and connected
*  operations  take logarithmic time (in the worst case) and the
*  count operation takes constant time.
*/
class WeightedQuickUnionUF {
private:
	const int MAXSIZE;
	std::vector<int> id;
	std::vector<int> sz;
	int cnt;

public:
	/**
	* Initializes an empty union-find data structure with N sites
	* 0 through N-1. Each site is initially in its own component.
	*
	* @param  N the number of sites
	*/
	WeightedQuickUnionUF(int N): MAXSIZE(N), cnt(N) {
		id.resize(MAXSIZE);
		sz.resize(MAXSIZE);
		for (int i = 0; i != MAXSIZE; ++i) {
			id[i] = i;
			sz[i] = 1;
		}
	};

	/**
	* Merges the component containing site p with the
	* the component containing site q.
	*
	* @param  p the integer representing one site
	* @param  q the integer representing the other site
	*/
	void merge(int p, int q) {
		int i = find(p), j = find(q);
		if (i == j)return;
		if (sz[i] < sz[j]){
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
		--cnt;
	};

	/**
	* Returns the component identifier for the component containing site p.
	*
	* @param  p the integer representing one object
	* @return the component identifier for the component containing site p
	*/
	int find(int p) {
		return p == id[p] ? p : (id[p] = find(id[p]));
	};

	/**
	* Returns true if the the two sites are in the same component.
	*
	* @param  p the integer representing one site
	* @param  q the integer representing the other site
	* @return true if the two sites p and q are in the same component;
	*         false otherwise
	*/
	bool isConnenctd(int p, int q) {
		return find(p) == find(q);
	};

	/**
	* Returns the number of components.
	*
	* @return the number of components (between 1 and N)
	*/
	int count() {
		return cnt;
	};
};

/**
* Reads in a sequence of pairs of integers (between 0 and N-1) from standard input,
* where each integer represents some object;
* if the sites are in different components, merge the two components
* and print the pair to standard output.
*/
int main()
{
	int sz, a, b;
	//! Use scanf instread of cin to save io cost greatly
	scanf_s("%d", &sz);
	WeightedQuickUnionUF u(sz);
	while (scanf_s("%d%d", &a, &b) != EOF) {
		u.merge(a, b);
	}
	std::cout << u.count() << "components" << std::endl;
	return 0;
}