#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

queue <int> que;
priority_queue<int, vector<int>, greater<int> > pque;

int main(){
  int q; cin >> q;
  for (int i = 0; i < q; i++){
    int query; cin >> query;

    if (query == 1){
      int x; cin >> x;
      que.push(x);
    }else if (query == 2){
      if (!pque.empty()){
        cout << pque.top() << endl;
        pque.pop();
      }else{
        cout << que.front() << endl;
        que.pop();
      }
    }else{
      while (!que.empty()){
        int f = que.front(); que.pop();
        pque.push(f);
      }
    }
  }

  return 0;
}