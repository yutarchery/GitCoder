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
ll s[int(1e5 + 5)], c[int(1e5 + 5)];
ll a[int(1e5 + 5)][105];

int max_idx = 0;
map<ll, int> idx;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> c[i];

    ll now = s[i];
    int cnt = 0;

    while (now % 2 == 0) {
      now /= 2;
      cnt++;
    }
    if (idx[now] == 0) {
      max_idx++;
      idx[now] = max_idx;
    }

    a[idx[now]][cnt] += c[i];
  }

  ll ans = 0;
  for (int i = 1; i <= max_idx; i++) {
    for (int j = 0; j <= 100; j++) {
      a[i][j + 1] += a[i][j] / 2;
      a[i][j] %= 2;
      ans += a[i][j];
    }
  }
  cout << ans << endl;

  return 0;
}
