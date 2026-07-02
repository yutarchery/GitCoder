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

int n, m, l[int(2e5 + 5)], r[int(2e5 + 5)];
Pii lr[int(2e5 + 5)];

int ans[int(2e5 + 5)];

void solve() {
  cin >> n >> m;
  fill(ans + 1, ans + n + 1, 0);

  int max_val = 0;
  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i];
    lr[i] = {l[i], r[i]};
    max_val = max(max_val, r[i] - l[i] + 1);
  }
  sort(lr + 1, lr + m + 1);

  set<int> st;
  for (int i = 1; i <= max_val; i++) {
    st.insert(i);
  }

  int now_l = 1, now_r = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = now_l; j < lr[i].first; j++) {
      if (ans[j] > 0) {
        st.insert(ans[j]);
      }
    }

    now_l = lr[i].first;
    for (int j = max(lr[i].first, now_r); j <= lr[i].second; j++) {
      if (ans[j] == 0) {
        ans[j] = *(st.begin());
        st.erase(ans[j]);
      }
    }
    now_r = max(now_r, lr[i].second);
  }

  for (int i = 1; i <= n; i++) {
    cout << (ans[i] > 0 ? ans[i] : 1) << (i == n ? '\n' : ' ');
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
