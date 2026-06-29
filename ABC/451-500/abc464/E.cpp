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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int h, w, q, r[int(2e5 + 5)], c[int(2e5 + 5)];
char x[int(2e5 + 5)];

vector<char> ans[int(1e6 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w >> q;
  for (int i = 1; i <= q; i++) {
    cin >> r[i] >> c[i] >> x[i];
  }

  for (int i = 1; i <= h; i++) {
    ans[i].resize(w + 2);
  }

  for (int k = q; k >= 1; k--) {
    for (int i = r[k]; i >= 1; i--) {
      if ('A' <= ans[i][c[k]] && ans[i][c[k]] <= 'Z') {
        break;
      }
      for (int j = c[k]; j >= 1; j--) {
        if ('A' <= ans[i][j] && ans[i][j] <= 'Z') {
          break;
        }
        ans[i][j] = x[k];
      }
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (!('A' <= ans[i][j] && ans[i][j] <= 'Z')) {
        ans[i][j] = 'A';
      }

      cout << ans[i][j];
    }
    cout << '\n';
  }

  return 0;
}
