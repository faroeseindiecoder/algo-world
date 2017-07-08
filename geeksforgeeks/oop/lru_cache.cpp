#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<list>
using namespace std;

list<int> q;
map<int, int> m;
int maxSize;

class LRUCache {
	
	public:
		LRUCache(int );
		int get(int );
		void set(int , int );
		void printCache();
	};

	/*Inititalize an LRU cache with size N */
	LRUCache::LRUCache(int N) {
		maxSize = N;
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) {
	if (m.find(x) != m.end()) {
		m[x] = y;
		q.remove(x);
		q.push_back(x);
	} else {
		if (q.size() >= maxSize) {
			//delete first element from queue and hash map and add new one to the queue and in hash map
			int removedElem = q.front();
			q.pop_front();
			m.erase(removedElem);
			cout << "Deleting first element " << maxSize << " " << removedElem << endl;
		}	
		q.push_back(x);
		m[x] = y;
	}
}

/*Returns the value of the key x if present else returns -1 */
int LRUCache::get(int x) {
	map<int, int>::iterator it = m.find(x);
	if (it != m.end()) return it->second;
	return -1;
}

void LRUCache::printCache() {
	cout << "Elements in cache: " << endl;
	for (auto &x: m) {
		cout << "Key: " << x.first << " Value: " << x.second << endl;
	}
}

int main() {
	ifstream in("lru_cache_input.txt");
	string line;
	int nrTests;
	in >> nrTests;
	for (int i = 0; i < nrTests; i++) {
		cout << "Test number: " << i << endl;

		int cacheCapacity;
		in >> cacheCapacity;
		LRUCache lru = LRUCache(cacheCapacity);

		int nrQueries;
		in >> nrQueries;

		while (in) {
			string operation;
			in >> operation;
			int x, y;
			if (operation == "SET") {
				in >> x;
				in >> y;
				cout << "Query: " << operation << " " << x << " " << y << endl;
				lru.set(x, y);
				lru.printCache();
			} else if (operation == "GET") {
				in >> x;
				cout << "Query: " << operation << " " << x << endl;
				cout << "Value corresponding to " << x << " : " << lru.get(x) << endl;
			}
		}
	}
}
