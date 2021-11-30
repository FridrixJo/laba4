#include <iostream>
using namespace std;



void AddItem(int*& arr, int size,const int item) {
    int* newArray = new int[size+1];
    for (int i = 0; i < size; i++) {
        newArray[i+1] = arr[i];
    }
    newArray[0] = item;
    size++;
    delete[] arr;
    arr = newArray;
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
    int n, m = 0, p;
    cout << "enter n\n";
    n = CurrentInput();
    p = n;
    while ((n /= 10) > 0) m++;
    m++;
    cout << m << "\n\n\n";
    n = p;
    int* arr = new int[m];
    int size = 0;
    while (p != 0) {
        AddItem(arr, size, p % 10);
        size++;
        p /= 10;
    } 
    for (int i = 0; i < m; i++) {
        cout << *(arr + i) << " ";
    }
    cout << "\n\n\n";


    cout << "enter number from 0 to n\n\n";
    int q = CurrentInput();
    cout << "\n\n\n";

    if (q > m) {
        cout << "yours k value is wrong, it has been returned to default value (q = m)\n";
        q = m;
    }
    if (q < 0) {
        cout << "yours k value is wrong, it has been returned to default value (q = m)\n";
        q = m;
    }
      
    for (int i = 0; i < m; i++) {
        if (q == i) {
            cout << arr[i] << "\n\n";
            break;
        }
    }

    delete[] arr;
    arr = nullptr;
    system("pause");
    return 0;
}

