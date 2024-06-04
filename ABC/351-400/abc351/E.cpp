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
ll x[int(2e5 + 5)], y[int(2e5 + 5)];

ll ans = 0;
vector<ll> sum[2], diff[2];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    sum[(x[i] + y[i]) % 2].push_back(x[i] + y[i]);
    diff[(x[i] + y[i]) % 2].push_back(x[i] - y[i]);
  }
  for (int i = 0; i < 2; i++) {
    sort(sum[i].begin(), sum[i].end());
    sort(diff[i].begin(), diff[i].end());
  }

  for (int i = 0; i < 2; i++) {
    ll m = sum[i].size();
    for (ll j = 0; j < m; j++) {
      ans += (sum[i][j] + diff[i][j]) * (2 * j - m + 1);
    }
  }
  cout << ans / 2 << endl;

  return 0;
}
