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
    cout << "\n\n**************\n\n";
}

int main()
{
    srand(time(NULL));
    cout << "enter n\n";
    int n = CurrentInput();
    int** A = new int*[n];
    int** B = new int*[n];
    int** AB = new int*[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        AB[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            AB[i][j] = 0;
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int q = 0; q < n; q++) {
                AB[i][j] += (A[i][q] * B[q][j]);
            }
        }
    }

    starline();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << AB[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] AB[i];
    }
    A = NULL;
    B = NULL;
    AB = NULL;
    system("pause");
    return 0;
}

