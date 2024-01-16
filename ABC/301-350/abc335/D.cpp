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

int n, ans[50][50];
bool visited[50][50];
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

int main() {
  cin >> n;
  visited[(n + 1) / 2][(n + 1) / 2] = true;

  int cnt = 1, i = 1, j = 1, k = 0;
  while (cnt <= n * n - 1) {
    visited[i][j] = true;
    ans[i][j] = cnt;
    cnt++;

    if (1 <= i + di[k] && i + di[k] <= n && 1 <= j + dj[k] && j + dj[k] <= n &&
        !visited[i + di[k]][j + dj[k]]) {
      i += di[k];
      j += dj[k];
    } else {
      k = (k + 1) % 4;
      i += di[k];
      j += dj[k];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (ans[i][j] == 0) {
        cout << "T";
      } else {
        cout << ans[i][j];
      }

      if (j == n) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }

  return 0;
}
