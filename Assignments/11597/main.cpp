#include <iostream>

using namespace std;

#define endl "\n"

int main() {
  int n;
  int i = 1;
  cin >> n;
  while (n != 0)
  {
    cout << "Case " << i << ": " << n/2 << endl;
    cin >> n;
    i++;
  }

  return 0;
}
