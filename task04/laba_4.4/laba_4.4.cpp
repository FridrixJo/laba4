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
    bool p1, p2, p3, p4, p5, p6, p7, p8;
    cout << "enter the value of rows " << "\n";
    int rows = CurrentInput();
    cout << "enter the value of cols " << "\n";
    int cols = CurrentInput();
    cout << "\n";
    int** arr = new int* [rows + 2];
    for (int i = 0; i < rows + 2; i++) {
        arr[i] = new int[cols + 2];
    }

    for (int i = 1; i < rows+1; i++) {
        for (int j = 1; j < cols + 1; j++) {
            arr[i][j] = rand() % 100;
        }
    }
    
    for (int i = 0; i < rows + 2; i++) {
        for (int j = 0; j < cols + 2; j++) {
            arr[i][0] = INT_MAX;
            arr[i][cols + 1] = INT_MAX;
            arr[0][j] = INT_MAX;
            arr[rows + 1][j] = INT_MAX;
        }
    }

    for (int i = 0; i < rows + 2; i++) {
        for (int j = 0; j < cols + 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    int counter = 0;
    
    for (int i = 1; i < rows + 1; i++) {
        for (int j = 1; j < cols + 1; j++) {
            p1 = arr[i][j] < arr[i][j + 1];
            p2 = arr[i][j] < arr[i][j - 1];
            p3 = arr[i][j] < arr[i + 1][j];
            p4 = arr[i][j] < arr[i - 1][j];
            p5 = arr[i][j] < arr[i + 1][j + 1];
            p6 = arr[i][j] < arr[i - 1][j - 1];
            p7 = arr[i][j] < arr[i + 1][j - 1];
            p8 = arr[i][j] < arr[i - 1][j + 1];
            if (p1 && p2 && p3 && p4 && p5 && p6 && p7 && p8) {
                counter++;
            }
        }
    }

    cout << "\n\n" << counter << "\n";

    for (int i = 0; i < rows + 2; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    system("pause");
    return 0;
}