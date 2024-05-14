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

ll l, r;
ll p[105];
vector<Pll> ans;

int main() {
  cin >> l >> r;

  int idx = 0;
  p[idx] = 1;
  while (p[idx] <= r) {
    idx++;
    p[idx] = p[idx - 1] * 2;
  }

  while (l < r) {
    for (int i = idx; i >= 0; i--) {
      if (l % p[i] == 0) {
        ll j = l / p[i];
        if (p[i] * (j + 1) <= r) {
          ans.push_back({l, p[i] * (j + 1)});
          l = p[i] * (j + 1);
          break;
        }
      }
    }
  }

  cout << ans.size() << endl;
  for (Pll a : ans) {
    cout << a.first << " " << a.second << endl;
  }

  return 0;
}
