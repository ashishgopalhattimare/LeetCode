#include <bits/stdc++.h>
using namespace std;

vector<int> algorithm(vector<int>& arr)
{
    vector<int>result(arr.size(), -1);
    
    stack<int>st;


}

int main()
{
    vector<int>arr = {5,1, 9,2, 5, 1, 7};
                //    2 2 -1 1 -1 -1 -1

                // {4, 8, 2, 1, 9, 5, 6, 3}
                //  2  5  5  5 -1  3 -1 -1

    vector<int>out = algorithm(arr);
    for(int i : out) cout <<i<< " ";
    printf("\n");

    return 0;
}