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

ll n, m, l[int(2e5 + 5)], r[int(2e5 + 5)];
vector<ll> v[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    v[l[i]].push_back(r[i]);
  }

  ll ans = 0, now_r = m + 1;
  for (ll i = m; i >= 1; i--) {
    if (!v[i].empty()) {
      sort(v[i].begin(), v[i].end());
      now_r = min(now_r, v[i][0]);
    }

    ans += now_r - i;
  }
  cout << ans << endl;

  return 0;
}
