#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

struct Element {
  int data, index;
  bool operator<(const Element& other) const {
    if(data == other.data) {
      return index > other.index;
    }
    return (data > other.data);
  }
};

int min(int x, int y) {
  return (x < y)? x : y;
}

std::vector<int> firstNSmallest(const std::vector<int> arr, int n){
  //your code here
  
  if (n == 0) return {};
  
  priority_queue<Element>pq;
  for(int i = 0; i < arr.size(); i++) {
    pq.push({arr[i], i});
  }
  
  vector<pair<int,int>>temp(min(n, pq.size()));
  int pushed = 0;
  while(!pq.empty() && pushed < temp.size()) {
    Element c = pq.top();
    pq.pop();
    temp[pushed] = {c.data, c.index};
    pushed++;
  }
  
  std::sort(temp.begin(), temp.end(), [](pair<int,int>& a, pair<int,int>& b) {
    return a.second < b.second;
  });
  
  std::vector<int>result(temp.size());
  for(int i = 0; i < temp.size(); i++) {
    result[i] = temp[i].first;
  }
  
  return result;
}
