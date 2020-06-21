// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/exists/
// Easy, HashTable

#include<iostream>
#include<set>
#include<vector>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll test, num, val, q, query;

    cin >> test;
    while(test--)
    {
        set<ll>us;
        
        cin >> num;
        for(ll i = 0; i < num; i++){
            cin >> val;
            if(us.find(val) == us.end())
                us.insert(val);
        }
        
        cin >> q;
        for(ll j = 0; j < q; j++){
            cin >> query;
            if(us.find(query) != us.end()){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
}