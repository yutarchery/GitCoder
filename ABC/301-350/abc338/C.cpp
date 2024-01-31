#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
ll q[15], a[15], b[15];

ll solve(ll a_cnt) {
  ll b_cnt = 1e9;
  for (int i = 1; i <= n; i++) {
    ll rest = q[i] - a[i] * a_cnt;
    if (b[i] == 0) {
      continue;
    }
    b_cnt = min(b_cnt, rest / b[i]);
  }
  return a_cnt + b_cnt;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  ll a_max = 1e9;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      continue;
    }
    a_max = min(a_max, q[i] / a[i]);
  }

  ll ans = 0;
  for (ll i = 0; i <= a_max; i++) {
    ans = max(ans, solve(i));
  }
  cout << ans << endl;

  return 0;
}
