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
ll a[int(2e5 + 5)], sum[int(2e5 + 5)];

multiset<ll> st;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    st.insert(sum[i]);
  }
  st.insert(sum[n]);

  ll ans = 1, now_min = 0, now_max = 0;
  for (int i = 1; i <= n; i++) {
    auto iter = st.lower_bound(sum[i]);
    st.erase(iter);

    auto min_iter = st.begin(), max_iter = st.end();
    max_iter--;

    ll now = sum[i - 1] - a[i];
    ans = max(ans, max(now_max, (*max_iter - sum[i]) + now) -
                       min(now_min, (*min_iter - sum[i]) + now) + 1);

    now_max = max(now_max, sum[i]);
    now_min = min(now_min, sum[i]);
  }

  ans = max(ans, now_max - now_min + 1);
  cout << ans << '\n';

  return 0;
}
