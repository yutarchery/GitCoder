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

int n, k, p[int(2e5 + 5)];

int ans[int(2e5 + 5)];
vector<vector<int>> stage;
set<Pii> st;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  if (k == 1) {
    for (int i = 1; i <= n; i++) {
      ans[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << endl;
    }
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    auto iter = st.lower_bound({p[i], -1});
    if (iter == st.end()) {
      vector<int> now;
      now.push_back(p[i]);
      stage.push_back(now);
      st.insert({p[i], stage.size() - 1});
    } else {
      Pii now = *iter;
      st.erase(now);

      stage[now.second].push_back(p[i]);
      if (stage[now.second].size() == k) {
        for (int j : stage[now.second]) {
          ans[j] = i;
        }
      } else {
        st.insert({p[i], now.second});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << (ans[i] == 0 ? -1 : ans[i]) << endl;
  }

  return 0;
}
