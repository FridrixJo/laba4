#include <iostream>
using namespace std;

int CurrentInput() {
    int a;
    while (!(cin >> a) || a < INT_MIN || a > INT_MAX) {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Incorrect input, try again:\n";
    }
    return a;
}

int main()
{
    cout << "enter size of your matrix\n";
    int size = CurrentInput();
    int** arr = new int* [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = CurrentInput();
        }
        cout << "\n";
    }
    bool isTrue = true;
    for (int i = 0; i < size; i++) {
        int ordinarySum = 0;
        for (int j = 0; j < size; j++)
            ordinarySum += arr[i][j] * arr[i][j];
        if (ordinarySum != 1)
            isTrue = false;
        for (int q = i + 1; q < size; q++)
        {
            int sum = 0;
            for (int j = 0; j < size; j++)
                sum += arr[i][j] * arr[q][j];
            if (sum!=0)
                isTrue = false;
        }
    }
    if (isTrue) {
        cout << "it's true\n";
    }
    else {
        cout << "it's false\n";
    }


    /*
    3
    1 0 0
    0 1 0
    0 0 1
    */

    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
    system("pause");
}
