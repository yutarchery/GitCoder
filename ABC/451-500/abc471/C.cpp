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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n;
ll a[int(3e5 + 5)];
set<ll> st;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  st.insert(-1e18);
  st.insert(1e18);

  ll now = 0, ans = 0, cnt = 0;
  while (cnt < n) {
    auto iter = st.lower_bound(now);
    ll r = *iter;

    iter--;
    ll l = *iter;

    if (now - l <= r - now) {
      ans += now - l;
      now = l;
      st.erase(l);
    } else {
      ans += r - now;
      now = r;
      st.erase(r);
    }
    cnt++;
  }
  cout << ans << '\n';

  return 0;
}
