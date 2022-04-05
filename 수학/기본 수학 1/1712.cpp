#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long A, B, C;
  int x,y;
  cin >> A >> B >> C;

  if(B >= C){
    cout << "-1\n";
  }
  else{
    x = A/(C-B);
    cout << x+1 << "\n";
  }

  return 0;
}