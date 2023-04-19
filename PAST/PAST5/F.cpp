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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, m, med[400][3];
int ans = 0;

bool used[15], non_used[15];

void make_used(int num) {
  for (int i = 1; i <= n; i++) {
    non_used[i] = false;
    if (num % 2 == 1) {
      used[i] = true;
    } else {
      used[i] = false;
    }
    num /= 2;
  }
  return;
}

void solve(int idx) {
  make_used(idx);
  for (int i = 0; i < m; i++) {
    int cnt = 0, next = 0;
    for (int j = 0; j < 3; j++) {
      if (used[med[i][j]]) {
        cnt++;
      } else {
        next = med[i][j];
      }
    }
    if (cnt == 2) {
      non_used[next] = true;
    } else if (cnt == 3) {
      return;
    }
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (non_used[i]) {
      res++;
    }
  }

  ans = max(ans, res);
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> med[i][j];
    }
  }

  for (int i = 0; i < pow(2, n); i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}