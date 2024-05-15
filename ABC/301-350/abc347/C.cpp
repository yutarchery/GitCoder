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
ll a, b, d[int(2e5 + 5)];

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    d[i] %= a + b;
  }
  sort(d + 1, d + n + 1);

  if (d[n] - d[1] < a) {
    Yes();
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    if ((d[i - 1] + (a + b) - d[i]) < a) {
      Yes();
      return 0;
    }
  }
  No();

  return 0;
}
