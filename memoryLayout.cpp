#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void printPointer(int &i);

int main() {
	static int intArray[5] = {0,1,2,3,4};
	vector<int> intVec = {0,1,2,3,4};
	int x = 0;
	int y = 12;
	int z = 21;

	cout << "Print contents and memory location of variables allocated in static data"<< endl;
	for (int & i : intArray)
	{
		printPointer(i);
	}

	cout << endl << "Print contents and memory location of variables allocated to the free store"<< endl;
	for(auto & i: intVec)
	{
		printPointer(i);
	}

	cout << endl <<  "Print contents and memory location of variables allocated to the stack"<< endl;
	printPointer(x);
	printPointer(y);
	printPointer(z);

}

void printPointer(int &i) {
	int* iptr = &i;
	// the unary * operator dereferences the pointer
	cout << "i = " << *iptr << endl;
	cout << "&i = " << iptr << endl;
}