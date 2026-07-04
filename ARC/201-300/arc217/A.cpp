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

const int c[4] = {0, 1, 3, 2};

void solve() {
  int n;
  cin >> n;

  vector<int> ans;
  int now = 0;
  while (now * 4 <= n) {
    for (int ci : c) {
      if (1 <= now * 4 + ci && now * 4 + ci <= n) {
        ans.emplace_back(now * 4 + ci);
      }
    }
    now++;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
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
