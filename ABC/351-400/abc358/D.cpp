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

int n, m;
ll a[int(2e5 + 5)], b[int(2e5 + 5)];

ll ans = 0;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + m + 1);

  ll ans = 0;
  int now = 1;
  for (int i = 1; i <= m; i++) {
    bool flag = false;

    for (int j = now; j <= n; j++) {
      if (b[i] <= a[j]) {
        ans += a[j];
        now = j + 1;
        flag = true;
        break;
      }
    }

    if (!flag) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;

  return 0;
}
