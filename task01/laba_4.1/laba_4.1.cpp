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
    cout << "enter size of your array\n";
    int size = CurrentInput();
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        cout << *(arr + i) << "\t";
    }
    cout << "\n\n";
    int min = arr[0], max = arr[1];
    int m1 = 0, m2 = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            m1 = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            m2 = i;
        }
    }
    cout << min << "\t" << max << "\n\n";

    for (int i = m1 + 1; i < size; i++)
        arr[i - 1] = arr[i];

    for (int i = m2 + 1; i < size; i++)
        arr[i - 1] = arr[i];

    size -= 2;

    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << "\t";
    }

    //arr = realloc(arr, sizeof(int) * (size - 2));
    cout << "t";
    delete[] arr;
    arr = nullptr;

    system("pause");
    return 0;
}



