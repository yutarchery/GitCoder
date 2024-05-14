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

ll a[3][3];
int point[3][3];

int judge() {
  for (int i = 0; i < 3; i++) {
    if (point[i][0] == point[i][1] && point[i][1] == point[i][2] &&
        point[i][0] > 0) {
      return point[i][0];
    }
  }

  for (int j = 0; j < 3; j++) {
    if (point[0][j] == point[1][j] && point[1][j] == point[2][j] &&
        point[0][j] > 0) {
      return point[0][j];
    }
  }

  if (point[0][0] == point[1][1] && point[1][1] == point[2][2] &&
      point[0][0] > 0) {
    return point[0][0];
  }

  if (point[2][0] == point[1][1] && point[1][1] == point[0][2] &&
      point[2][0] > 0) {
    return point[2][0];
  }

  return 0;
}

int solve(int turn, int player) {
  if (judge() != 0) {
    return judge();
  }

  if (turn == 9) {
    ll p1 = 0, p2 = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (point[i][j] == 1) {
          p1 += a[i][j];
        } else {
          p2 += a[i][j];
        }
      }
    }

    if (p1 >= p2) {
      return 1;
    } else {
      return 2;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (point[i][j] > 0) {
        continue;
      }

      point[i][j] = player;
      int next = solve(turn + 1, 3 - player);
      point[i][j] = 0;
      if (player == next) {
        return player;
      }
    }
  }

  return 3 - player;
}

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }

  if (solve(0, 1) == 1) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }

  return 0;
}
