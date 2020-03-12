#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems//

class CombinationIterator {
private:
    list<string>ll;
    string str;
    int length;

    void dfs(int index, string combination) {
        
        if(length == combination.length()) {
            ll.push_back(combination);
            return;
        }

        for(int i = index; i < str.length(); i++) {
            dfs(i+1, combination + str[i]);
        }
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        
        str = characters;
        length = combinationLength;

        dfs(0, "");
    }
    string next() {
        string result = ll.front();
        ll.pop_front();

        return result;
    }
    bool hasNext() {
        return !(ll.empty());
    }
};

// 1299 Question
int main()
{
    string str = "abc";
    int len = 2;

    CombinationIterator *sol = new CombinationIterator(str, len);

    while(sol->hasNext()) {
        cout << sol->next() << endl;
    }
    
    return 0;
}