#include <iostream>

void sortArray(int*,int);
int main() {
	int i = 0;
	int size = 0;
	std::cout << "Enternt size of Array \n";
	std::cin >> size;
	int* arr = new int[size];
	std::cout << "Enter elements of array \n"; 
	for(i; i < size; ++i) {
		std::cout << "array [ " << i << "] = ";
		std::cin >> arr[i];
	}
	sortArray(arr,size);
	return 0;
}

void sortArray(int* ar, int size) {
	int i = 0,j = 0,cur;
	for(i = 1; i < size; ++i) {
		cur = ar[i];
		j = i - 1;
		while(j >= 0 && cur < ar[j]) {
			ar[j + 1 ] = ar[j];
			--j;
		}
		ar[j + 1] = cur;
	}
	std::cout << "\nSorted Array\n";
	for(i = 0; i < size; ++i) {
		std::cout << "array[" << i << "] = " << ar[i] << std::endl;
	}
}
		
	
	
