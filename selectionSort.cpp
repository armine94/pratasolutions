#include <iostream>

void sortArray(int*,int);

int main() {
	int size = 0;
	int i = 0;
	std::cout << "Enter size of array \n";
	std::cin >> size;
	int* arr = new int[size];
	std::cout << "\nEnter elemnts of Array\n\n";
	for(i; i < size; ++i) {
		std::cout << "array [" << i << "] = "; 
		std::cin >> arr[i];
	}
	sortArray(arr,size);
	return 0;
}

void sortArray(int* arr,int size) {
	int i = 0, j = 0;
	int min,index;
	for(i; i < size - 1; i++) {
		index = i;
		for(j = i + 1; j < size; j++) {
			if(arr [ j] <  arr[index]) {
				index = j ;
			}
		}
		int tmp = arr [i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}
	std::cout << "\nSorted Array\n\n";
	for(i = 0; i < size; ++i) {
		std::cout << "array[" << i << "] = " << arr[i] << std::endl;
	}
}
		

