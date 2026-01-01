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

ll n, m;
ll a[int(3e5 + 5)], b[int(3e5 + 5)];

ll sum_b[int(3e5 + 5)];

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
  for (int i = 1; i <= m; i++) {
    sum_b[i] = sum_b[i - 1] + b[i];
  }

  ll now_b = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    while (now_b < m) {
      if (a[i] > b[now_b + 1]) {
        now_b++;
      } else {
        break;
      }
    }

    ans += abs(sum_b[now_b] - a[i] * now_b) +
           abs(sum_b[m] - sum_b[now_b] - a[i] * (m - now_b));
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
