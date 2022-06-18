#include <iostream>
using namespace std;

int main() {
	//char** ca = { "abc", "de" };
	//char* ca[] = { {'a','b', 'c'} , {'d', 'e'} };
	//char* ca[] = { "abc" , "de" };
	//int** da = { {1,2,3}, {4,5} };
	//int* da[] = { {1,2,3}, {4,5} };
	int* da[] = { new int[] {1,2,3}, new int[] {4,5} }; //an array of pointer, ragged
	int** pda = da;  // da is adress of pointer
	cout << *(*(pda + 1) + 1) << endl;// output 5

	int da1[2][3] = { {1,2,3}, {4,5,6} }; //an array of array, square
	int(*pda1)[3] = da1;  //da1 is address of array [3]
	cout << *(*(pda1 + 1) + 1) << endl;// output 5

	char* ca[] = { new char[] {'a', 'b', 'c', '\0'}, new char[] {'d', '\0'} };
	const char* cca[] = { "abc", "de" };
}