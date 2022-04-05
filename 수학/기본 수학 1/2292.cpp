#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 1 6 12 18 24...
  int x, lev = 1, n = 1;
  cin >> x;
  while(1){
    if(x == 1){
      cout << '1' << '\n';
      break;
    }
    else if(n >= x){
      cout << lev-1 << '\n';
      break;
    }
    else{
      n += 6 * (lev-1);
      lev++;
    }
  }

  return 0;
}