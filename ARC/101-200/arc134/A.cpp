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
ll l, w, a[int(1e5 + 5)];

set<Pll> st;

int main() {
  cin >> n >> l >> w;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st.insert({a[i], a[i] + w});
  }
  st.insert({0, 0});
  st.insert({l, l});

  ll ans = 0, now_r = 0;
  auto iter = st.upper_bound({0, 0});
  while (iter != st.end()) {
    Pll p = *iter;

    if (now_r < p.first) {
      ans += (p.first - now_r - 1) / w + 1;
    }
    now_r = p.second;
    iter++;
  }
  cout << ans << endl;

  return 0;
}
