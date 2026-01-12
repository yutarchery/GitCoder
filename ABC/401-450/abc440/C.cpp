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

int n, w;
ll c[int(2e5 + 5)];
ll cnt[int(4e5 + 5)], sum[int(8e5 + 5)];

ll solve() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    cnt[i % (2 * w)] += c[i];
  }

  for (int i = 1; i <= 4 * w; i++) {
    sum[i] = sum[i - 1] + cnt[i % (2 * w)];
  }
  ll ans = 1e18;
  for (int i = w; i <= 4 * w; i++) {
    ans = min(ans, sum[i] - sum[i - w]);
  }

  return ans;
}

void reset() {
  fill(c + 1, c + n + 1, 0);
  fill(cnt, cnt + 2 * w + 1, 0);
  fill(sum, sum + 4 * w + 1, 0);
  return;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cout << solve() << endl;
    reset();
  }

  return 0;
}
