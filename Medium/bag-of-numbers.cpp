// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/bag-of-numbers/
// Easy

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ifstream infile; infile.open("input.txt");
    
    // Code Here
    queue<string>qq;
    string input;

    cin >> input;
    while(cin >> input) qq.push(input);

    if(qq.size() < 3) cout << "output";
    else cout << "output:";

    while(!qq.empty()) { 
        cout << " " << qq.front();
        qq.pop();
    }

    return 0;
}