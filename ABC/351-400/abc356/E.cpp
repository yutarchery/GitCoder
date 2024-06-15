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

int n;
ll a[int(2e5 + 5)], cnt[int(1e6 + 5)];
ll ans = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= a[n]; i++) {
    cnt[i] += cnt[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      continue;
    }
    ll now = cnt[a[i]] - cnt[a[i] - 1];
    ans += now * (now - 1) / 2;
    ans += (cnt[min(a[n], a[i] * 2 - 1)] - cnt[a[i]]) * now;

    for (ll j = 2; j <= a[n]; j++) {
      ans +=
          (cnt[min(a[n], a[i] * (j + 1) - 1)] - cnt[min(a[n], a[i] * j - 1)]) *
          j * now;
      if (a[i] * (j + 1) - 1 > a[n]) {
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
