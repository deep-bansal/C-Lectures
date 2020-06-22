#include <bits/stdc++.h>

using namespace std;
void printMaxinKSizeSubarray(int* arr,int n,int k)
{
    deque<int> dq(k);
    int i;
    ///for first k elements
    for(i=0;i<k;i++)
    {
        while(!dq.empty() && arr[i]>=arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);

    }
    ///for remaining elements
    for(i=k;i<n;i++)
    {
        cout<<arr[dq.front()]<<endl;///max element is printed
        while(!dq.empty() && dq.front()<i-k+1)///removing elements that are not part of current window
        {
            dq.pop_front();
        }
        /// remove all smaller elements of current window
		while( !dq.empty() && arr[i] >= arr[dq.back()]){

			dq.pop_back();
		}
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<endl;

}
int main()
{
    int arr[10] = {10,1,8,0,6,9,15};
    int n=7;
    int k=3;

    printMaxinKSizeSubarray(arr, n, k);

    return 0;
}
