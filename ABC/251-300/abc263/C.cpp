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

int n, m, ans[15];

void display() {
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
  return;
}

void solve(int turn = 1, int now = 1) {
  if (turn == n + 1) {
    display();
    return;
  }

  for (int i = now; i <= m; i++) {
    ans[turn] = i;
    solve(turn + 1, i + 1);
    ans[turn] = 0;
  }
  return;
}

int main() {
  cin >> n >> m;
  solve();
  return 0;
}
