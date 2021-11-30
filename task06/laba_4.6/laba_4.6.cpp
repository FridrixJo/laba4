#include <iostream>
using namespace std;

void starline() {
    cout << "\n\n*****************\n\n";
}

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
    int** arr = new int* [n+1];
    for (int i = 0; i < n + 1; i++) {
        arr[i] = new int[m+1];
    }
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            arr[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            arr[i][0] = 0;
            arr[0][j] = 0;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    starline();
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            int newArray[3] = { arr[i][j - 1],arr[i - 1][j - 1],arr[i - 1][j] };
            int max = 0;
            for (int i = 0; i < 3; i++) {
                if (newArray[i] > max) {
                    max = newArray[i];
                }
            }
            if (arr[i][j] < max) {
                arr[i][j] = max;
            }
        }
    }
    cout << "\n";
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = NULL;
    system("pause");
    return 0;
}

