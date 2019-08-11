#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string a, string b) {
  // Your code here
  
  vector<int>result;
  int starti = 0, k;
  int carry;
  
  for(int i = b.size()-1; i >= 0; i--) {
    carry = 0; k = starti;
    for(int j = a.size()-1; j >= 0; j--) {
      carry = carry + (b[i]-'0')*(a[j]-'0');
      if(k == result.size()) {
        result.push_back(carry%10);
      }
      else {
        carry = carry + result[k];
        result[k] = carry%10;
      }
      carry /= 10;
      k++;
    }
    
    while(carry) {
      if(k == result.size()) result.push_back(carry%10);
      else {
        carry = carry + result[k];
        result[k] = carry % 10;
      }
      carry /= 10;
    }
    starti++;
  }
  
  string answer = "";
  starti = result.size()-1;
  while(result[starti] == 0) starti--;
  
  if(starti < 0) return "0";
  
  for(int i = starti; i >= 0; i--) {
    answer.push_back(result[i]+'0');
  }
  
  return answer;
}
