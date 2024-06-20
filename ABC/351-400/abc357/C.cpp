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
char ans[1005][1005][10];
bool visited[1005][1005][10];

char solve(int i, int j, int level) {
  if (visited[i][j][level]) {
    return ans[i][j][level];
  }
  visited[i][j][level] = true;
  if (level == 0) {
    return ans[i][j][level] = '#';
  }

  int before = pow(3, level - 1);
  if (i / before == 1 && j / before == 1) {
    return ans[i][j][level] = '.';
  }

  char now = solve(i % before, j % before, level - 1);
  return ans[i][j][level] = now;
}

int main() {
  cin >> n;
  for (int i = 0; i < pow(3, n); i++) {
    for (int j = 0; j < pow(3, n); j++) {
      cout << solve(i, j, n);
    }
    cout << endl;
  }

  return 0;
}
