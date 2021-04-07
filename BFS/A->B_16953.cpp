#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int A, B, res = -1;

void BFS(int a){
  deque<pair<ll,ll>> dq;
  dq.push_back({a,1});

  while(!dq.empty()){
    ll x = dq.front().first, d = dq.front().second;
    dq.pop_front();
    if(x == B){
      res = d;
      return;
    }
    ll x1 = (x<<1), x2 = (x<<1) + (x<<3) + 1;
    if(x1 < B) dq.push_back({x1, d+1}); 
    else if(x1 == B){
      res = d+1;
      return;
    }   
    if(x2 < B) dq.push_back({x2, d+1});
    else if(x2 == B){
      res = d+1;
      return;
    }
  }
}

int main(void)
{
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> A >> B;
  BFS(A);
  cout << res << endl;
  return 0;
}