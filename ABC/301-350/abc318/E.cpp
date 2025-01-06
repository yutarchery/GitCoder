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

int n, a[int(3e5 + 5)];
vector<int> loc[int(3e5 + 5)];
ll ans = 0, cnt[int(3e5 + 5)], dp[int(3e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;

    loc[a[i]].push_back(i);
    if (loc[a[i]].size() == 1) {
      continue;
    }

    int before_idx = loc[a[i]][loc[a[i]].size() - 2];
    dp[i] += dp[before_idx];
    dp[i] += ll((i - 1) - before_idx) * ll(loc[a[i]].size() - 1);
  }

  for (int i = 1; i <= n; i++) {
    ans += dp[i];
  }
  cout << ans << endl;

  return 0;
}
