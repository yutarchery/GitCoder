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

int n, m, a[int(3e5 + 5)];
int now[int(1e5 + 5)], ans[int(3e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }

  now[0] = int(2e9);
  for (int i = 1; i <= m; i++) {
    if (a[i] <= now[n]) {
      ans[i] = -1;
      continue;
    }

    int ng = 0, ok = n;
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      if (now[mid] < a[i]) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    ans[i] = ok;
    now[ok] = a[i];
  }

  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
