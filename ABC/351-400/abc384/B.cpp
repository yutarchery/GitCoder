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

int n, r, d[105], a[105];

int main() {
  cin >> n >> r;
  for (int i = 1; i <= n; i++) {
    cin >> d[i] >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    if (d[i] == 1) {
      if (1600 <= r && r <= 2799) {
        r += a[i];
      }
    } else {
      if (1200 <= r && r <= 2399) {
        r += a[i];
      }
    }
  }
  cout << r << endl;

  return 0;
}
