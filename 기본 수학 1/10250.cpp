#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T, w, h, n, i;
  int x, y;
  cin >> T;
  for(i=0;i<T;i++){
    cin >> h >> w >> n;
    x = n / h + 1;
    y = n % h;
    if(y==0){
      x -= 1;
      y = h;
    }
    if(x<10){
      cout << y << "0" << x << "\n";
    }
    else{      
      cout << y << x << "\n";
    }
  }
  return 0;
}