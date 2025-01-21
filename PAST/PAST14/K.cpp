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

int n, t, p;
ll a[105];

double ans[105];

int main() {
  cin >> n >> t >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n; i >= 1; i--) {
    ll now = a[i] - (a[i] * t / 100);
    ans[i] = ans[i + 1] + double(now);

    double e = (ans[i + 1] + a[i]) * (double)(100 - p) / (double)100 +
               (ans[i + 2] + now) * (double)p / (double)100;

    ans[i] = max(ans[i], e);
  }

  cout << fixed << setprecision(10) << ans[1] << endl;

  return 0;
}
