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

int n, a[105];
char s[105];

int solve(int start_l, int start_r) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'L') {
      res += abs(start_l - a[i]);
      start_l = a[i];
    } else {
      res += abs(start_r - a[i]);
      start_r = a[i];
    }
  }
  return res;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> s[i];
  }

  int ans = 1e9;
  for (int l = 0; l <= 100; l++) {
    for (int r = 0; r <= 100; r++) {
      ans = min(ans, solve(l, r));
    }
  }
  cout << ans << endl;

  return 0;
}
