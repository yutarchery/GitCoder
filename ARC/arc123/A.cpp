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

int main(){
  ll a[3];
  for (int i = 0; i < 3; i++) cin >> a[i];

  ll ans = 1e16;

  ll ideal0 = 2 * a[1] - a[2];
  if (a[0] <= ideal0){
    ans = min(ans, ideal0 - a[0]);
  }

  ll ideal1 = (a[0] + a[2] + 1) / 2;
  if (a[1] <= ideal1){
    if ((a[0] + a[2]) % 2 == 0){
      ans = min(ans, ideal1 - a[1]);
    }else{
      ans = min(ans, ideal1 - a[1] + 1);
    }
  }

  ll ideal2 = 2 * a[1] - a[0];
  if (a[2] <= ideal2){
    ans = min(ans, ideal2 - a[2]);
  }

  cout << ans << endl;

  return 0;
}