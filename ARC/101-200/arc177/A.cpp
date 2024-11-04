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
ll rest[6], x[15];
const ll coins[6] = {1, 5, 10, 50, 100, 500};

int main() {
  for (int i = 0; i < 6; i++) {
    cin >> rest[i];
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    for (int j = 5; j >= 0; j--) {
      ll now = min(x[i] / coins[j], rest[j]);
      x[i] -= now * coins[j];
      rest[j] -= now;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (x[i] > 0) {
      No();
      return 0;
    }
  }
  Yes();

  return 0;
}