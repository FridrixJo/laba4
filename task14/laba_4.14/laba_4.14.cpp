#include <iostream>
using namespace std;

int CorrentInput() {
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
    int rows, cols;
    cout << "enter the value of rows\n";
    rows = CorrentInput();
    cout << "enter the value of cols\n";
    cols = CorrentInput();
    int arr[102][102];
    for (int i = 0; i <= rows + 1; i++) {
        for (int j = 0; j <= cols + 1; j++) {
            arr[i][j] = 0;
        }
    }

    starline();

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            arr[i][j] = rand() % 2;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    starline();

    int field[102][102];
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
            int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
            int temp = 0;
            for (int k = 0; k < 8; k++)
                temp += arr[i + dy[k]][j + dx[k]];
            field[i][j] = temp;
        }
    }

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (arr[i][j] == 1) {
                cout << "*";
            }
            else {
                cout << field[i][j];
            }
        }
        cout << "\n";
    }

    system("pause");
    return 0;
}
