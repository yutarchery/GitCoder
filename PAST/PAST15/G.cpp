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

int n, m, k[105], a[105][20], b[105][20];
int x[20];

bool solve(int num) {
  for (int i = 1; i <= n; i++) {
    x[i] = num % 2;
    num /= 2;
  }

  for (int i = 1; i <= m; i++) {
    bool flag = false;
    for (int j = 1; j <= k[i]; j++) {
      if (x[a[i][j]] == b[i][j]) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> k[i];
    for (int j = 1; j <= k[i]; j++) {
      cin >> a[i][j] >> b[i][j];
    }
  }

  for (int i = 0; i < (1 << n); i++) {
    if (solve(i)) {
      Yes();
      return 0;
    }
  }
  No();

  return 0;
}
