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

int n, q;
int l[int(2e5 + 5)], r[int(2e5 + 5)], x[int(2e5 + 5)];

int ans[int(2e5 + 5)];
vector<Pii> lr[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i] >> x[i];

    lr[x[i]].push_back({l[i], r[i]});
  }

  for (int i = 1; i <= q; i++) {
    if (lr[i].size() == 0) {
      continue;
    }

    sort(lr[i].begin(), lr[i].end());

    int now_l = 0, now_r = -1;
    for (int j = 0; j < lr[i].size(); j++) {
      if (now_r < lr[i][j].first) {
        ans[now_l]++;
        ans[now_r + 1]--;

        now_l = lr[i][j].first;
        now_r = lr[i][j].second;
      } else {
        now_r = max(now_r, lr[i][j].second);
      }

      if (j == lr[i].size() - 1) {
        ans[now_l]++;
        ans[now_r + 1]--;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
