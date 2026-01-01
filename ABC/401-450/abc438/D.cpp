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
ll a[int(3e5 + 5)], b[int(3e5 + 5)], c[int(3e5 + 5)];

ll sum_a[int(3e5 + 5)], sum_b[int(3e5 + 5)], sum_c[int(3e5 + 5)];
priority_queue<Pli> que_a, que_c;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sum_b[i] = sum_b[i - 1] + b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  for (int i = 1; i <= n; i++) {
    sum_a[i] = sum_a[i - 1] + (a[i] - b[i]);
  }

  for (int i = n; i >= 1; i--) {
    sum_c[i] = sum_c[i + 1] + (c[i] - b[i]);
    que_c.push({sum_c[i], i});
  }

  ll ans = 0;
  for (int i = 2; i <= n - 1; i++) {
    que_a.push({sum_a[i - 1], i - 1});
    while (!que_c.empty()) {
      Pli q = que_c.top();
      if (i + 1 <= q.second) {
        break;
      } else {
        que_c.pop();
      }
    }

    ans = max(ans, sum_b[n] + (que_a.top()).first + (que_c.top()).first);
  }

  cout << ans << endl;

  return 0;
}
