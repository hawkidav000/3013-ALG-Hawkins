#include <iostream> 
#include <iterator> 
#include <vector>
#include <map> 
  
using namespace std; 

#define endl "\n"
  
int main() 
{ 
  map<int, int> map1;

  int n;
  vector<int> nums;
  map<int, int>::iterator itr;

  while (cin >> n){
    if ( map1.find(n) == map1.end() ) 
    {
      map1.insert(pair<int, int>(n, 1));
      nums.push_back(n);
    } 
    else 
    {
      map1[n] = map1[n] + 1;
    }
  }

  for (int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " " <<map1[nums[i]] << endl;
  } 

  return 0;
}
