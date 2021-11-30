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

int main()
{
	srand(time(NULL));
	cout << "enter the value of rows " << "\n";
	int n = CurrentInput();
	cout << "enter the value of cols " << "\n";
	int m = CurrentInput();
	cout << "\n";

	int** mtrx = new int* [n];

	for (int i = 0; i < n; i++) {
		mtrx[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mtrx[i][j]= rand() % 100;
			cout << mtrx[i][j] << "\t";
		}
		cout << "\n";
	}
	int min = INT_MAX;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < m; j++) {
			if (mtrx[i][j] < min) {
				min = mtrx[i][j];
			}
		}
	}

	cout << "\n\n" << min << "\n\n";

	for (int i = 0; i < n; i++) {
		delete[] mtrx[i];
	}
	delete[] mtrx;
	mtrx = NULL;
	system("pause");
	return 0;
}
