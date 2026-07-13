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

ll n, m, r[int(3e5 + 5)], c[int(3e5 + 5)];

set<ll> removed_r, removed_c;
set<Pll> rc, cr;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> r[i] >> c[i];
  }

  for (int i = 1; i <= m; i++) {
    removed_r.insert(r[i]);
    removed_c.insert(c[i]);

    auto iter = rc.lower_bound({r[i], 0});
    while (iter != rc.end() && (*iter).first == r[i]) {
      Pll now = *iter;
      iter++;

      rc.erase(now);
      cr.erase({now.second, now.first});
    }

    iter = cr.lower_bound({c[i], 0});
    while (iter != cr.end() && (*iter).first == c[i]) {
      Pll now = *iter;
      iter++;

      cr.erase(now);
      rc.erase({now.second, now.first});
    }

    rc.insert({r[i], c[i]});
    cr.insert({c[i], r[i]});
  }

  cout << rc.size() << '\n';

  return 0;
}
