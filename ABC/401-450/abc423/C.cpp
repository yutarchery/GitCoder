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

int n, r, l[int(2e5 + 5)];

int main() {
  cin >> n >> r;

  int open_l = r + 1, open_r = r;
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
    if (l[i] == 0) {
      open_l = min(open_l, i);
      open_r = max(open_r, i);
      flag = true;
    }
  }

  if (!flag) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  for (int i = open_l; i <= open_r; i++) {
    if (l[i] == 1) {
      ans++;
    }
  }
  ans += open_r - open_l + 1;
  cout << ans << endl;

  return 0;
}
