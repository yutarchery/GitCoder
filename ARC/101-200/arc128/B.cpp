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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int t, a[3], ans;

void solve() {
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);

  if ((a[2] - a[0]) % 3 == 0) {
    ans = min(ans, a[2]);
  }
  if ((a[1] - a[0]) % 3 == 0) {
    ans = min(ans, a[1]);
  }
  if ((a[2] - a[1]) % 3 == 0) {
    ans = min(ans, a[2]);
  }

  if (ans == mod) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    ans = mod;
    solve();
  }

  return 0;
}