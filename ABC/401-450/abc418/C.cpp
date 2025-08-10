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

int n, q;
ll a[int(3e5 + 5)], b[int(3e5 + 5)];

ll m, cnt[int(1e6 + 5)], sum[int(1e6 + 5)];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m = max(a[i], m);
    cnt[a[i]]++;
  }
  for (int i = m; i >= 1; i--) {
    cnt[i] += cnt[i + 1];
  }
  for (int i = 1; i <= m; i++) {
    sum[i] = sum[i - 1] + cnt[i];
  }

  for (int i = 1; i <= q; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= q; i++) {
    if (b[i] > m) {
      cout << -1 << endl;
    } else {
      cout << sum[b[i]] - cnt[b[i]] + 1 << endl;
    }
  }

  return 0;
}
