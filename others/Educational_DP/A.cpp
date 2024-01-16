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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, h[int(1e5 + 5)], cost[int(1e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    cost[i] = 1e9;
  }

  cost[1] = 0;
  for (int i = 1; i <= n; i++) {
    if (i + 1 <= n) {
      cost[i + 1] = min(cost[i + 1], cost[i] + abs(h[i] - h[i + 1]));
    }
    if (i + 2 <= n) {
      cost[i + 2] = min(cost[i + 2], cost[i] + abs(h[i] - h[i + 2]));
    }
  }
  cout << cost[n] << endl;

  return 0;
}
