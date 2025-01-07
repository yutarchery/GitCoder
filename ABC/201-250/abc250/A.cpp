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

int h, w, r, c, ans = 0;
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int main() {
  cin >> h >> w;
  cin >> r >> c;

  for (int k = 0; k < 4; k++) {
    int i = r + di[k], j = c + dj[k];
    if (1 <= i && i <= h && 1 <= j && j <= w) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
