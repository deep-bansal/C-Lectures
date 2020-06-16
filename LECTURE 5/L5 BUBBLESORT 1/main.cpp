#include <iostream>
using namespace std;
void bubblesort(int arr[10], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < (n - j - 1); i++)
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }


        for (int i = 0; i < 6; i++)
        {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[10] = {9, 7, 1, 3, 2, 6};
    bubblesort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << ", ";
    }
    return 0;
}
