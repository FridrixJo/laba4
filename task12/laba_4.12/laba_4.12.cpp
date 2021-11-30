#include <iostream>
using namespace std;

int CurrentInput() {
	int a;
	while (!(cin >> a) || a <= 0 || a > INT_MAX) {
		cin.clear();
		cin.ignore(numeric_limits < streamsize > ::max(), '\n');
		cout << "Incorrect input, try again:\n";
	}
	return a;
}

void starline() {
	cout << "\n\n******************************\n\n";
}

void ShowArray(int* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
}

void RemoveDuplicate(int* arr, int& size) {
	starline();
	int* newArray = new int[size];
	int* CopyArray = new int[size];
	for (int i = 0; i < size; i++) {
		newArray[i] = arr[i];
	}
	int k = 0;
	for (int i = 0; i < size; i++) {
		int duplicates = 0;
		for (int j = i + 1; j < size; j++) {
			if (newArray[i] == newArray[j]) {
				duplicates++;
			}
		}
		if(!duplicates){
		CopyArray[k] = newArray[i];
		k++;
		}
	}

	for (int i = 0; i < k; i++) {
		cout << CopyArray[i] << "\t";
	}
	delete[] newArray;
	delete[] CopyArray;
	newArray = nullptr;
	CopyArray = nullptr;

	starline();

}

int main()
{
	int size = CurrentInput();
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	RemoveDuplicate(arr, size);

	delete[] arr;
	arr = nullptr;
	system("pause");
	return 0;
} 
