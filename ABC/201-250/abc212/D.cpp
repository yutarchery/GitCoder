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

int q;
priority_queue<ll, vector<ll>, greater<ll> > que;
ll sum;

int main(){
  cin >> q;
  for (int i = 0; i < q; i++){
    int p; cin >> p;

    if (p == 1){
      ll x; cin >> x;
      que.push(x);
    }else if (p == 2){
      ll x; cin >> x;
      sum += x;
    }else if (p == 3){
      ll ans = que.top(); que.pop();
      cout << ans + sum << endl;
    }
  }

  return 0;
}