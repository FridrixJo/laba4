#include <iostream>
using namespace std;

int CurrentInput() {
    int a;
    while (!(cin >> a) || a > INT_MAX) {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Incorrect input, try again:\n";
    }
    return a;
}

void starline() {
    cout << "\n\n******************************\n\n";
}

void ShowArray(int* const arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main(){
    srand(time(NULL));
    cout << "enter k\n";
    int k = CurrentInput();
    int* arr = new int[k];
    int max = INT_MIN, min = INT_MAX, p, q, sum = 0;

    for (int i = 0; i < k; i++) {
        arr[i] = CurrentInput();
        cout << arr[i] << " ";
    }
    for (int i = 0; i < k; i++) {
        if (arr[i] > max) {
            max = arr[i];
            p = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            q = i;
        }
    }
    starline();
    cout << max << "  " << min;
    starline();
   
    if (p > q) {
        for (int i = q + 1; i < p; i++) {
            arr[i] = 0;
            sum++;
        };
    }
    else {
        for (int i = p + 1; i < q; i++) {
            arr[i] = 0;
            sum++;
        };
    }

 
    ShowArray(arr, k);
    starline();
    //5 1 2 3 4 5
    if ((k - sum) < sum) {
        if (p - q > 0) {
            for (int i = 0; i <= sum; i++) {
                for (int j = q + 2; j <= p; j++) {
                    arr[j - 1] = arr[j];
                 }
                p--;
            }
            ShowArray(arr, k - sum);
        }
        else {
            for (int i = 0; i <= sum; i++) {
                for (int j = p + 2; j <= q; j++) {
                    arr[j - 1] = arr[j];
                }
                q--;
            }
            ShowArray(arr, k - sum);
        }
    }

    delete[] arr;
    arr = NULL;
    system("pause");
    return 0;
}

