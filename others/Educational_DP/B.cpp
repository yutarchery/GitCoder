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

int n, k, h[int(1e5 + 5)], cost[int(1e5 + 5)];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  fill(cost + 1, cost + n, 1e9);

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i + j < n) {
        cost[i + j] = min(cost[i + j], cost[i] + abs(h[i] - h[i + j]));
      }
    }
  }
  cout << cost[n - 1] << endl;

  return 0;
}