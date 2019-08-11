#include <string>
#include <vector>
#include <list>

std::string sum_strings(std::string a, std::string b) {
  
  std::list<int>ll;
  int ia = a.length()-1, ib = b.length()-1;
  int carry = 0, aa, bb;
  while(carry || ia >= 0 || ib >= 0) {
     aa = (ia >= 0)? (a[ia]-'0') : 0;
     bb = (ib >= 0)? (b[ib]-'0') : 0;
     
     carry = carry + aa + bb;
     ll.push_front(carry%10);
     
     if(ia >= 0) ia--;
     if(ib >= 0) ib--;
     
     carry /= 10;
  }
  
  while(!ll.empty() && ll.front() == 0)
    ll.pop_front();
    
  if(ll.empty()) return "0";
  
  std::string result = "";
  while(!ll.empty()) {
    result.push_back(ll.front() + '0');
    ll.pop_front();
  }

  return result;
}
