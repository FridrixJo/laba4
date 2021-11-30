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
    int rows = CurrentInput();
    cout << "enter the value of cols " << "\n";
    int cols = CurrentInput();
    cout << "\n";
    double** arr = new double* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    arr[0][0] = (arr[0][1] + arr[1][0] + arr[1][1]) / 3;
    arr[rows - 1][0] = (arr[rows - 1][1] + arr[rows - 2][0] + arr[rows - 2][1]) / 3;
    arr[0][cols-1] = (arr[0][cols-2] + arr[1][cols-2] + arr[1][cols-1]) / 3;
    arr[rows - 1][cols - 1] = (arr[rows-1][cols-2] + arr[rows-2][cols-2] + arr[rows-2][cols-1]) / 3;


    for (int i = 1; i < rows-1; i++) {
         arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i][1] + arr[i + 1][1] + arr[i + 1][0]) / 5;
         arr[i][cols - 1] = (arr[i - 1][cols - 1] + arr[i - 1][cols - 2] + arr[i][cols - 2] + arr[i + 1][cols - 2] + arr[i + 1][cols - 1])/5;
    }


    for (int j = 1; j < cols-1; j++) {
         arr[0][j] = (arr[0][j - 1] + arr[1][j - 1] + arr[1][j] + arr[1][j + 1] + arr[0][j + 1]) / 5;
         arr[rows - 1][j] = (arr[rows - 1][j - 1] + arr[rows - 2][j - 1] + arr[rows - 2][j] + arr[rows - 2][j + 1] + arr[rows - 1][j + 1]) / 5;
    }


    for (int i = 1; i < rows-1; i++) {
        for (int j = 1; j < cols-1; j++) {
            arr[i][j] = (arr[i][j - 1] + arr[i][j + 1] + arr[i - 1][j] + arr[i + 1][j] + arr[i - 1][j - 1] + arr[i - 1][j + 1] + arr[i + 1][j - 1] + arr[i + 1][j + 1]) / 8;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = NULL;
    system("pause");
    return 0;
}

