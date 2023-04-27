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

int n, m, k, t[int(1e5 + 5)];
ll q, p[int(1e5 + 5)];
int idx_a = 0, idx_b = 0;
ll a[int(1e5 + 5)], b[int(1e5 + 5)];
ll sum_a[int(1e5 + 5)], sum_b[int(1e5 + 5)];

int main() {
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> t[i];
    if (t[i] == 0) {
      idx_a++;
      a[idx_a] = p[i];
    } else {
      idx_b++;
      b[idx_b] = p[i];
    }
  }
  sort(a, a + idx_a + 1);
  sort(b, b + idx_b + 1);

  for (int i = 1; i <= idx_a; i++) {
    sum_a[i] = sum_a[i - 1] + a[i];
  }
  for (int i = 1; i <= idx_b; i++) {
    sum_b[i] = sum_b[i - 1] + b[i];
  }

  ll ans = 1e18;
  for (int i = 0; i <= m; i++) {
    int j = m - i;

    if (0 <= i && i <= idx_a && 0 <= j && j <= idx_b) {
      if (j == 0) {
        ans = min(ans, sum_a[i]);
      } else {
        ans = min(ans, sum_a[i] + sum_b[j] + q * ((j - 1) / k + 1));
      }
    }
  }
  cout << ans << endl;

  return 0;
}