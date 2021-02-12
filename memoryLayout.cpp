#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void printPointer(int &i);

int main() {
	int intArray[10] = {0,1,2,3,4,5,6,7,8,9};
	auto arrayNew = new int[10];
	vector<int> intVec = {0,1,2,3,4,5,6,7,8,9};


	cout << "Print contents and memory location of variables allocated to the stack"<< endl;
	for(auto & i: intVec)
	{
		printPointer(i);
	}

	cout << endl << "Print contents and memory location of variables allocated in static data"<< endl;
	for (int & i : intArray)
	{
		printPointer(i);
	}


	cout << endl << "Print contents and memory location of variables allocated to the free store"<< endl;
	for (int i = 0; i < 10; i++)
	{
		arrayNew[i]= i;
		printPointer(arrayNew[i]);
	}

}

void printPointer(int &i) {
	int* iptr = &i;
	// the unary * operator dereferences the pointer
	cout << "i = " << *iptr << endl;
	cout << "&i = " << iptr << endl;
}