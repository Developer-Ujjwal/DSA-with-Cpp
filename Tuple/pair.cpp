#include <iostream>
#include <utility>
using namespace std;
int main() {
    std::pair<int, char> myPair(100, 'A');
    std::cout << "First: " << myPair.first << ", Second: " << myPair.second << std::endl;
  
	pair<int, char> PAIR1;

	// first part of the pair
	PAIR1.first = 100;
	// second part of the pair
	PAIR1.second = 'G';

	cout << PAIR1.first << " ";
	cout << PAIR1.second << endl;

    // Initializing a pair using make_pair
    auto anotherPair = std::make_pair(200, 'B');
    std::cout << "First: " << anotherPair.first << ", Second: " << anotherPair.second << std::endl;

    return 0;
}
