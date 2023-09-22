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

int n, a[int(2e5 + 5)];
string s, t = "MEX";

ll ans, x[int(2e5 + 5)][3], e[int(2e5 + 5)][3][3];

int score(int i, int j, int k) {
  int a[3] = {i, j, k};
  sort(a, a + 3);

  for (int l = 0; l <= 3; l++) {
    bool flag = true;
    for (int now : a) {
      if (l == now) {
        flag = false;
      }
    }

    if (flag) {
      return l;
    }
  }

  return 0;
}

void solve(int idx) {
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 3; k++) {
      ans += e[idx][j][k] * score(a[idx], j, k);
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> s;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      x[i][j] = x[i + 1][j];
      for (int k = 0; k < 3; k++) {
        e[i][j][k] = e[i + 1][j][k];
      }
    }

    if (s[i] == 'M') {
      solve(i);
    } else if (s[i] == 'E') {
      for (int k = 0; k < 3; k++) {
        e[i][a[i]][k] += x[i][k];
      }
    } else if (s[i] == 'X') {
      x[i][a[i]]++;
    }
  }

  cout << ans << endl;

  return 0;
}