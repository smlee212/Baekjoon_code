#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, B, V, buf;
  cin >> A >> B >> V;
  buf = (V-B)%(A-B);

  if(buf == 0){
    buf = (V-B)/(A-B);
  }
  else{
    buf = (V-B)/(A-B) + 1;
  }
  cout << buf << '\n';

  return 0;
}