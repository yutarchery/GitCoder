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

int n, q, p[int(2e5 + 5)], a;

set<Pii> st;
vector<Pii> ans;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    st.insert({p[i], i});
  }
  for (int i = 1; i <= q; i++) {
    cin >> a;
    auto iter = st.lower_bound({a, 0});
    st.erase(*iter);
    st.insert({a, n + i});
  }

  for (Pii p : st) {
    ans.push_back({p.second, p.first});
  }
  sort(ans.begin(), ans.end());

  for (int i = 0; i < n; i++) {
    cout << ans[i].second << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}
