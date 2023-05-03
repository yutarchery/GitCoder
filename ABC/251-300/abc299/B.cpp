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

int n, t, c[int(2e5 + 5)], r[int(2e5 + 5)];
int val = 0, ans = 0;

int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }

  for (int i = 1; i <= n; i++) {
    if (c[i] == t) {
      if (val < r[i]) {
        val = r[i];
        ans = i;
      }
    }
  }

  if (ans == 0) {
    for (int i = 1; i <= n; i++) {
      if (c[i] == c[1]) {
        if (val < r[i]) {
          val = r[i];
          ans = i;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}