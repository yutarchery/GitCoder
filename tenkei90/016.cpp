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

ll N, A, B, C;
ll ans = 9999;

int main(){
  cin >> N >> A >> B >> C;
  for (ll i = 0; i <= 9999; i++){
    if (A * i > N) break;
    for (ll j = 0; i + j <= 9999; j++){
      if (A * i + B * j > N) break;
      if ((N - (A * i + B * j)) % C != 0) continue;

      ll k = (N - (A * i + B * j)) / C;
      ans = min(ans, i + j + k);
    }
  }
  cout << ans << endl;

  return 0;
}