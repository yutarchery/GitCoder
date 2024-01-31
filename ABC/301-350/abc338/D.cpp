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

ll n, m, x[int(2e5 + 5)];
ll cost[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i];
  }

  ll ans = 0;
  for (int i = 1; i <= m - 1; i++) {
    bool swapped = false;
    if (x[i] > x[i + 1]) {
      swap(x[i], x[i + 1]);
      swapped = true;
    }

    ans += min(x[i + 1] - x[i], (x[i] + n) - x[i + 1]);
    ll now = abs((x[i + 1] - x[i]) - (x[i] + n - x[i + 1]));

    if (x[i + 1] - x[i] <= (x[i] + n) - x[i + 1]) {
      cost[x[i]] += now;
      cost[x[i + 1]] -= now;
    } else {
      cost[1] += now;
      cost[x[i]] -= now;
      cost[x[i + 1]] += now;
      cost[n + 1] -= now;
    }

    if (swapped) {
      swap(x[i], x[i + 1]);
    }
  }

  for (int i = 1; i <= n; i++) {
    cost[i] += cost[i - 1];
  }
  sort(cost + 1, cost + n + 1);
  cout << ans + cost[1] << endl;

  return 0;
}
