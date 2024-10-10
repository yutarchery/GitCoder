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

ll t, n[2], v[2][int(1e5 + 5)], l[2][int(1e5 + 5)];

ll ans = 0, now = 1;
int idx0 = 1, idx1 = 1;

int main() {
  cin >> t >> n[0] >> n[1];
  for (int j = 1; j <= n[0]; j++) {
    cin >> v[0][j] >> l[0][j];
    l[0][j] += l[0][j - 1];
  }
  for (int j = 1; j <= n[1]; j++) {
    cin >> v[1][j] >> l[1][j];
    l[1][j] += l[1][j - 1];
  }

  while (now <= t) {
    if (l[0][idx0] == l[1][idx1]) {
      if (v[0][idx0] == v[1][idx1]) {
        ans += l[0][idx0] - now + 1;
      }
      now = l[0][idx0] + 1;
      idx0++;
      idx1++;
    } else if (l[0][idx0] < l[1][idx1]) {
      if (v[0][idx0] == v[1][idx1]) {
        ans += l[0][idx0] - now + 1;
      }
      now = l[0][idx0] + 1;
      idx0++;
    } else {
      if (v[0][idx0] == v[1][idx1]) {
        ans += l[1][idx1] - now + 1;
      }
      now = l[1][idx1] + 1;
      idx1++;
    }
  }
  cout << ans << endl;

  return 0;
}
