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

int n, d[105], ans = 0;

void solve(int month, int day, int num) {
  while (month > 0) {
    if (month % 10 != num) {
      return;
    }
    month /= 10;
  }
  while (day > 0) {
    if (day % 10 != num) {
      return;
    }
    day /= 10;
  }
  ans++;
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    for (int j = 1; j <= d[i]; j++) {
      for (int k = 1; k <= 9; k++) {
        solve(i, j, k);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
