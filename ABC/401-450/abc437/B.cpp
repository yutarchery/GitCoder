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

int h, w, n, a[5][10], b[100];
int ans[5];

int main() {
  cin >> h >> w >> n;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }
  for (int k = 1; k <= n; k++) {
    cin >> b[k];

    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (a[i][j] == b[k]) {
          ans[i]++;
        }
      }
    }
  }

  sort(ans, ans + h + 1);
  cout << ans[h] << endl;

  return 0;
}
