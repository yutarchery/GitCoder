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

int n, m;
ll a[int(2e5 + 5)], b[int(2e5 + 5)], c[int(2e5 + 5)], x[int(2e5 + 5)];

set<pair<Pll, ll>> st;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    st.insert({{a[i], b[i]}, c[i]});
    st.insert({{b[i], a[i]}, c[i]});
  }
  st.insert({{ll(1e16), ll(1e16)}, ll(2e16)});

  for (int i = 1; i <= m; i++) {
    cin >> x[i];
  }

  ll ans = x[1];
  for (int i = 2; i <= m; i++) {
    auto iter = st.lower_bound({{ans, x[i]}, 0});
    pair<Pll, ll> now = *iter;
    if (now.first.first == ans && now.first.second == x[i]) {
      ans = now.second;
    } else {
      ans = ans + x[i];
    }
  }
  cout << ans << endl;

  return 0;
}
