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

int q, t;
string s;

set<int> rest;
set<Pll> prefixes;
set<pair<Pll, int>> st[int(5e5 + 5)];

Pll v[int(5e5 + 5)];

int main() {
  cin >> q;

  for (int idx = 1; idx <= q; idx++) {
    cin >> t >> s;

    if (t == 1) {
      ll h1 = 0, h2 = 0;
      for (int i = 0; i < s.length(); i++) {
        h1 = ((h1 * MOD3) + s[i]) % MOD;
        h2 = ((h2 * MOD3) + s[i]) % MOD2;
      }
      prefixes.insert({h1, h2});

      auto iter = st[s.length()].lower_bound({{h1, h2}, 0});
      while (iter != st[s.length()].end()) {
        pair<Pll, int> p = *iter;
        if (p.first != make_pair(h1, h2)) {
          break;
        }

        rest.erase(p.second);
        iter++;
        st[s.length()].erase(p);
      }
    } else {
      v[0] = {0, 0};
      bool flag = true;
      for (int i = 0; i < s.length(); i++) {
        v[i + 1].first = ((v[i].first * MOD3) + s[i]) % MOD;
        v[i + 1].second = ((v[i].second * MOD3) + s[i]) % MOD2;

        auto iter = prefixes.find(v[i + 1]);
        if (iter != prefixes.end()) {
          flag = false;
          break;
        }
      }

      if (flag) {
        rest.insert(idx);
        for (int i = 1; i <= s.length(); i++) {
          st[i].insert({v[i], idx});
        }
      }
    }

    cout << rest.size() << endl;
  }

  return 0;
}
