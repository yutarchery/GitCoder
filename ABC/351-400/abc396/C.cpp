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
ll b[int(2e5 + 5)], w[int(2e5 + 5)];

ll sum_b[int(2e5 + 5)], sum_w[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + n + 1, greater<ll>());
  for (int i = 1; i <= n; i++) {
    sum_b[i] = sum_b[i - 1] + b[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> w[i];
  }
  sort(w + 1, w + m + 1, greater<ll>());
  for (int i = 1; i <= m; i++) {
    sum_w[i] = sum_w[i - 1] + w[i];
  }

  ll ans = 0;
  priority_queue<ll> que;
  que.push(0);
  for (int i = 1; i <= n; i++) {
    if (i <= m) {
      que.push(sum_w[i]);
    }
    ans = max(ans, que.top() + sum_b[i]);
  }
  cout << ans << endl;

  return 0;
}
