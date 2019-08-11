#include <bits/stdc++.h>

using namespace std;

vector<int> temp;

struct Fountain
{
    int data;
    int index;

    bool operator<(const Fountain& oth) const {
        int l1 = 0, l2 = 0, r1 = 0, r2 = 0;

        for(int i = index-1, k = 1; i >= 0 && k <= data; i--, k++) {
            if(temp[i] == -1) l1++;
        }
        for(int i = oth.index-1, k = 1; i >= 0 && k <= oth.data; i--, k++) {
            if(temp[i] == -1) l2++;
        }

        for(int i = index+1, k = 1; i < temp.size() && k <= data; i++, k++) {
            if(temp[i] == -1) r1++;
        }
        for(int i = oth.index+1, k = 1; i < temp.size() && k <= oth.data; i++, k++) {
            if(temp[i] == -1) r2++;
        }

        if ((l1+r1 + (temp[index] == -1)) == (l2+r2 + (temp[oth.index] == -1))) {
            return index > oth.index;
        }
        return (l1+r1 + (temp[index] == -1)) < (l2+r2 + (temp[oth.index] == -1));
    }
};

vector<int> algo(vector<int>& nums)
{
    temp = vector<int>(nums.size(), -1);

    priority_queue<Fountain>pq;
    for(int i = 0; i < nums.size(); i++) {
        pq.push({nums[i], i});
    }

    int remain = nums.size();
    while(!pq.empty() && remain) {
        Fountain curr = pq.top();
        pq.pop();

        printf("%d\n", curr.index);

        if(temp[curr.index] == -1) {
            remain--;
            temp[curr.index] = curr.index;
        }

        for(int i = curr.index-1, k = 1; i >= 0 && remain && k <= curr.data; i--, k++) {
            if(temp[i] == -1) {
                temp[i] = curr.index;
                remain--;
            }
        }

        for(int i = curr.index+1, k = 1; i < temp.size() && remain && k <= curr.data; i++, k++) {
            if(temp[i] == -1) {
                temp[i] = curr.index;
                remain--;
            }
        }

        // break;
    }

    for(int x : temp) cout << x << " ";
    printf("\n");

    return {};
}

int main()
{
    vector<int> fountain = {1,1,1,1,1,1,1,1,1,1};
                            // 1 1 1 2 2 2 3 3 3 4
    
    vector<int> result = algo(fountain);
}