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

ll n, a[int(2e5 + 5)], cnt[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ll now = a[i];
    for (int j = 2; j * j <= a[i]; j++) {
      while (now % (j * j) == 0) {
        now /= j * j;
      }
    }
    cnt[now]++;
  }

  ll ans = cnt[0] * (cnt[0] - 1) / 2 + cnt[0] * (n - cnt[0]);
  for (int i = 1; i <= int(2e5); i++) {
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}
