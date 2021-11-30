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
    int size = CurrentInput();
    int*** arr = new int** [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int* [size];
        for (int j = 0; j < size; j++) {
            arr[i][j] = new int[size];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int q = 0; q < size; q++) {
                arr[i][j][q] = rand() % 5;
                cout << arr[i][j][q] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }

    int d1 = 0, d2 = 0, d3 = 0, d4 = 0;

    for (int i = 0; i < size; i++) {
        d1 += arr[i][i][i];
        d2 += arr[size - 1 - i][size - 1 - i][i];
        d3 += arr[i][size - 1 - i][size - 1 - i];
        d4 += arr[i][size - 1 - i][i];

    }

    cout << d1 << "\t" << d2 << "\t" << d3 << "\t" << d4 << "\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            delete[] arr[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }

    delete[] arr;
    arr = NULL;

    system("pause");
    return 0;
}

