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

int n, m, q, num, a, b, point[55];
bool solved[int(1e5 + 5)][55];

int main() {
  cin >> n >> m >> q;
  fill(point + 1, point + m + 1, n);

  while (q--) {
    cin >> num;
    if (num == 1) {
      cin >> a;
      int ans = 0;
      for (int j = 1; j <= m; j++) {
        if (solved[a][j]) {
          ans += point[j];
        }
      }
      cout << ans << endl;
    } else {
      cin >> a >> b;
      point[b]--;
      solved[a][b] = true;
    }
  }

  return 0;
}
