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

int n, q, op[int(3e5 + 5)], x[int(3e5 + 5)];
char c[int(3e5 + 5)];

bool is_tiled[int(3e5 + 5)];
vector<Pii> non_tiled[int(3e5 + 5)];
vector<pair<int, char>> colors;

char ans[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;

  colors.push_back({0, 'a'});
  for (int i = 1; i <= n; i++) {
    non_tiled[i].push_back({0, 0});
  }

  for (int i = 1; i <= q; i++) {
    cin >> op[i];
    if (op[i] == 1) {
      cin >> x[i];
      is_tiled[x[i]] = !is_tiled[x[i]];

      if (is_tiled[x[i]]) {
        non_tiled[x[i]][(non_tiled[x[i]].size() - 1)].second = i - 1;
      } else {
        non_tiled[x[i]].push_back({i, i});
      }
    } else {
      cin >> c[i];
      colors.push_back({i, c[i]});
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!is_tiled[i]) {
      non_tiled[i][(non_tiled[i].size() - 1)].second = q;
    }

    for (int j = non_tiled[i].size() - 1; j >= 0; j--) {
      int ok = 0, ng = colors.size();

      while (ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if (colors[mid].first <= non_tiled[i][j].second) {
          ok = mid;
        } else {
          ng = mid;
        }
      }

      if (non_tiled[i][j].first <= colors[ok].first) {
        ans[i] = colors[ok].second;
        break;
      }
    }

    cout << ans[i];
  }
  cout << '\n';

  return 0;
}
