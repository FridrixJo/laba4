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
    cout << "enter n\n";
    int n = CurrentInput();
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
            arr[0][0] = 1;
        }
    }

    cout << "\n\n";

    for (int i = 0; i < n; i++) {
        arr[i][0] = (i + 1) * (i + 1);
        arr[0][i] = i * i + 1;

        for (int j = 1; j < i; j++) {
            arr[i][j] = arr[i][j - 1] - 1;

        }

        for (int j = 1; j <= i; j++) {
            arr[j][i] = arr[j - 1][i] + 1;

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }  
        cout << "\n\n";
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    system("pause");
    return 0;
}

