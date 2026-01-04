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

int n, q, l[int(2e5 + 5)], r[int(2e5 + 5)];
set<Pii> white;

int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];
    r[i]++;
  }

  int ans = n;
  white.insert({1, n + 1});

  for (int i = 1; i <= q; i++) {
    if (white.empty()) {
      cout << 0 << endl;
      continue;
    }

    auto iter = white.lower_bound({r[i], r[i]});
    iter--;

    while (l[i] < r[i]) {
      Pii now = *iter;
      iter--;

      if (r[i] <= now.first || now.second <= l[i]) {
        break;
      }

      white.erase(now);
      if (l[i] <= now.first && now.second <= r[i]) {
        ans -= now.second - now.first;
      } else if (l[i] <= now.first && r[i] <= now.second) {
        ans -= r[i] - now.first;
        white.insert({r[i], now.second});
      } else if (now.second <= r[i]) {
        ans -= now.second - l[i];
        white.insert({now.first, l[i]});
      } else {
        white.insert({now.first, l[i]});
        white.insert({r[i], now.second});
        ans -= r[i] - l[i];
      }

      r[i] = now.first;
    }
    cout << ans << endl;
  }

  return 0;
}
