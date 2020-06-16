#include <iostream>
using namespace std;
//optimization
void bubblesort(int arr[10], int n) {
    for (int j = 0; j <= n - 1; j++) {
        bool issorted = true;
        for (int i = 0; i <= n - j - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                issorted = false;
            }
        }
        if (issorted) {
            break;
        }
        for (int i = 0; i < 6; i++) {
            cout << arr[i] << ", ";

        }
        cout << endl;

    }



}

int main()
{
    int arr[10] = {5, 9, 1, 3, 2, 6};
    bubblesort(arr, 6);
    return 0;
}
