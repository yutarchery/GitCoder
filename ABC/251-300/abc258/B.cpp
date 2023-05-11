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
string a[10];
int di[3] = {-1, 0, 1}, dj[3] = {-1, 0, 1};
string ans = "";

void solve(int turn, string now, int now_i, int now_j, int dir_i, int dir_j) {
  if (turn == n) {
    ans = max(ans, now);
    return;
  }

  int next_i = (now_i + dir_i) % n, next_j = (now_j + dir_j) % n;
  if (next_i < 0) {
    next_i = n - 1;
  }
  if (next_j < 0) {
    next_j = n - 1;
  }

  solve(turn + 1, now + a[next_i][next_j], next_i, next_j, dir_i, dir_j);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          if (di[k] == 0 && dj[l] == 0) {
            continue;
          }
          solve(0, "", i, j, di[k], dj[l]);
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}