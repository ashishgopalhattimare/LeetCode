// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/little-monk-and-williamson/
// Medium, Priority Queue, Heap, AVL-Tree, Map

#include <bits/stdc++.h>
using namespace std;

void remove(map<int,int>& mapi, int val)
{
    if(mapi[val] == 1) mapi.erase(val);
    else mapi[val]--;
}

int main()
{
    ifstream infile;
    infile.open("input.txt");

    int n, X;
    string OP;

    map<int,int>mapi;

    cin >> n;
    while(n--)
    {
        cin >> OP;
        if(OP == "CountHigh") {
            if(mapi.empty()) printf("-1\n");
            else {
                auto itr = mapi.rbegin();
                printf("%d\n", itr->second);
            }
        }
        else if(OP == "CountLow") {
            if(mapi.empty()) printf("-1\n");
            else {
                auto itr = mapi.begin();
                printf("%d\n", itr->second);
            }
        }
        else if(OP == "Diff") {
            if(mapi.empty()) printf("-1\n");

            else {
                
                auto large = mapi.rbegin(); // reverse iterator
                auto small = mapi.begin();  // default iterator

                // Difference
                cout << abs(small->first-large->first) << endl;

                if(small->first == large->first) { // if same, remove once from the mapi
                    remove(mapi, small->first);
                }
                else { // remove both once from the mapi
                    remove(mapi, small->first);
                    remove(mapi, large->first);
                }
            }
        }
        else { // Push
            cin >> X; mapi[X]++;
        }
    }

    return 0;
}