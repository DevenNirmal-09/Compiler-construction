#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>
using namespace std;
int main()
{
    int x;
    cin >> x;
    vector<int> arr(x);
    for(int i=0; i<x; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<x; i++)
    {
        int sum=0;
        int j=i+1;
        int l=arr.size()-1;
        while(j>=0)
        {
            sum += arr[l];
            l--;
            j--;
        }
        if(sum%2==0)
        {
            cout << "0 " << endl;
            return 0;
        }
        else{
            cout << sum << " " << endl;
            return 0;
        }
    }
}