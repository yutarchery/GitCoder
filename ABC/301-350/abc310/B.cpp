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

int n, m, p[105], c, f;
bool q[105][105];

bool judge(int i, int j) {
  if (p[i] < p[j]) {
    return false;
  }

  int cnt = 0;
  for (int k = 1; k <= m; k++) {
    if (q[i][k] && !q[j][k]) {
      return false;
    }
    if (!q[i][k] && q[j][k]) {
      cnt++;
    }
  }

  if (p[i] == p[j]) {
    return cnt > 0;
  } else {
    return true;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> c;
    for (int j = 0; j < c; j++) {
      cin >> f;
      q[i][f] = true;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }

      if (judge(i, j)) {
        Yes();
        return 0;
      }
    }
  }
  No();

  return 0;
}
