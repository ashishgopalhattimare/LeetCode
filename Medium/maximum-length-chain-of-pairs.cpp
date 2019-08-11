// https://www.geeksforgeeks.org/maximum-length-chain-of-pairs-dp-20/
// Easy

#include <bits/stdc++.h>

using namespace std;

int longestChain(vector<vector<int>>& input)
{
    vector<int> longest(input.size(), 1);

    for(int i = 0; i < input.size(); i++) {
        for(int j = i+1; j < input.size(); j++) {

            if(input[i][1] < input[j][0]) {
                longest[j] = max(longest[j], longest[i]+1);
            }
        }
    }

    int maxLength = 1;
    for(int x : longest) maxLength = max(maxLength, x);

    return maxLength;
}

int main()
{
    vector<vector<int>> input = {{5,24},{15,25},{27,40},{50,90}};

    cout << "Length of maximum size chain is " << longestChain(input) << endl;

    return 0;
}