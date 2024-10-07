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

int n, x, a[105];

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n);

  int sum = 0;
  for (int i = 2; i <= n - 2; i++) {
    sum += a[i];
  }

  for (int i = 0; i <= 100; i++) {
    int now[3] = {a[1], a[n - 1], i};
    sort(now, now + 3);

    if (sum + now[1] >= x) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
