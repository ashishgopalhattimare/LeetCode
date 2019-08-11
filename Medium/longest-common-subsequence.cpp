#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

string lcs(const string& xx, const string& yy)
{
  string x = xx;
  string y = yy;
  
  vector<vector<int>>DP(y.length()+1, vector<int>(x.length()+1, 0));
  vector<vector<char>>D(y.length()+1, vector<char>(x.length()+1,'*'));
  
  for(int i = 1; i <= y.length(); i++) {
    for(int j = 1; j <= x.length(); j++) {
      
      if(x[j-1] == y[i-1]) {
        DP[i][j] = DP[i-1][j-1] + 1;
        D[i][j] = 'D';
      }
      else {
        if(DP[i-1][j] > DP[i][j-1]) {
          D[i][j] = 'U';
        }
        else D[i][j] = 'L';
        DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
      }
    }
  }  
  
  int i = y.length(), j = x.length();
  std::list<char>ll;
  
  while(i && j) {
    if(D[i][j] == 'D') {
      ll.push_front(y[i-1]);
      i--; j--;
    }
    else if(D[i][j] == 'L') j--;
    else i--;
  }
  
  std::string result = "";
  while(!ll.empty()) {
    result.push_back(ll.front());
    ll.pop_front();
  }
  
  return result;
}
