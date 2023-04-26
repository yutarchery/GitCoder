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

int r1, c1, r2, c2;
int now_r, now_c, ans = 3;

void solve_a(int r, int c, int turn) {
  if (turn == 3) {
    return;
  }
  if (r == r2 && c == c2) {
    ans = min(ans, turn);
  }
  if (r + c == r2 + c2) {
    ans = min(ans, turn + 1);
  }
  if (r - c == r2 - c2) {
    ans = min(ans, turn + 1);
  }
  if ((r + c) % 2 == (r2 + c2) % 2) {
    ans = min(ans, turn + 2);
  }

  for (int i = -3; i <= 3; i++) {
    for (int j = -3; j <= 3; j++) {
      if (abs(i) + abs(j) <= 3) {
        solve_a(r + i, c + j, turn + 1);
      }
    }
  }
}

int main() {
  cin >> r1 >> c1 >> r2 >> c2;
  solve_a(r1, c1, 0);
  cout << ans << endl;

  return 0;
}