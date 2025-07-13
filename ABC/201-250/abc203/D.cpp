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

int n, k;
ll a[805][805];

ll now[805][805], sum[805][805];

bool solve(ll num) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] > num) {
        now[i][j] = 1;
      } else {
        now[i][j] = 0;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + now[i][j];
    }
  }

  for (int i = 1; i + k - 1 <= n; i++) {
    for (int j = 1; j + k - 1 <= n; j++) {
      if (sum[i + k - 1][j + k - 1] - sum[i - 1][j + k - 1] -
              sum[i + k - 1][j - 1] + sum[i - 1][j - 1] <
          (k * k) / 2 + 1) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  ll ng = -1, ok = 1e16;
  while (ok - ng > 1) {
    ll mid = (ng + ok) / 2;

    if (solve(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
