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

int n, x[int(3e5 + 5)];
ll m, a[int(3e5 + 5)], b[int(3e5 + 5)];

priority_queue<Pli> que;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> x[i];
    if (x[i] == 1) {
      if (b[i] >= 2) {
        que.push({a[i] * 2, i});
      } else {
        que.push({a[i], i});
      }
    } else {
      que.push({a[i], i});
      b[i]--;
    }
  }

  while (!que.empty()) {
    if (m == 0) {
      break;
    }

    Pli q = que.top();
    que.pop();

    if (x[q.second] == 1) {
      x[q.second] = 0;
      if (b[q.second] >= 2) {
        b[q.second] -= 2;
      } else {
        b[q.second]--;
      }

      m--;
      if (b[q.second] > 0) {
        que.push({a[q.second], q.second});
      }
    } else if (m >= b[q.second]) {
      m -= b[q.second];
      b[q.second] = 0;
    } else {
      b[q.second] -= m;
      break;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] * max(0ll, b[i]);
  }
  cout << ans << endl;

  return 0;
}
