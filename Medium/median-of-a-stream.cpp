#include <bits/stdc++.h>

using namespace std;

struct Data1 { // MAX HEAP
    int data;
    bool operator<(const Data1 &oth) const {
        return data < oth.data;
    }
};

struct Data2 { // MIN HEAP
    int data;
    bool operator<(const Data2 &oth) const {
        return data > oth.data;
    }
};

int abs_value(int x, int y) {
    return abs(x-y);
}

void find_median(vector<int>& input)
{
    priority_queue<Data2>minHeap;
    priority_queue<Data1>maxHeap;

    for(int x : input) {
        minHeap.push({x});

        if(abs_value(maxHeap.size(), minHeap.size()) > 1) {
            if(maxHeap.size() >  minHeap.size()) {

                minHeap.push({maxHeap.top().data});
                maxHeap.pop();
            }
            else {

                maxHeap.push({minHeap.top().data});
                minHeap.pop();
            }
        }

        if(maxHeap.size() == minHeap.size()) {
            cout << "Median : " << (maxHeap.top().data + minHeap.top().data)/2.0 << endl;
        }
        else {
            if(maxHeap.size() > minHeap.size()) {
                cout << "Median : " << maxHeap.top().data << endl;
            }
            else {
                cout << "Median : " << minHeap.top().data << endl;
            }
        }
    }
}

int main()
{
    vector<int> stream = {5,3,8,7,6,4};
    find_median(stream);

    return 0;
}