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
    cout << "\n\n*****************\n\n";
}

int main()
{
    cout << "enter N\n";
    int N = CurrentInput();
    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        cout << "the value of " << i + 1 << " extension\n";
        cin >> arr[i];
    }

    int total = 0;
    for (int i = 0; i < N; i++) {
        total += arr[i];
    }
    
    total -= (N - 1);
    starline();
    cout << total;

    delete[] arr;
    arr = NULL;
    system("pause");
    return 0;
}

