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

ll h, w, color_cnt, q;
int t[int(3e5 + 5)], n[int(3e5 + 5)], c[int(3e5 + 5)];

map<ll, bool> used_1, used_2;
set<ll> st_1, st_2;
ll ans[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w >> color_cnt >> q;
  for (int i = 1; i <= q; i++) {
    cin >> t[i] >> n[i] >> c[i];
  }

  for (int i = q; i >= 1; i--) {
    if (t[i] == 1) {
      if (used_1[n[i]]) {
        continue;
      }

      used_1[n[i]] = true;
      ans[c[i]] += w - st_2.size();
      st_1.insert(n[i]);
    } else {
      if (used_2[n[i]]) {
        continue;
      }

      used_2[n[i]] = true;
      ans[c[i]] += h - st_1.size();
      st_2.insert(n[i]);
    }
  }

  for (int i = 1; i <= color_cnt; i++) {
    cout << ans[i] << (i == color_cnt ? '\n' : ' ');
  }

  return 0;
}
