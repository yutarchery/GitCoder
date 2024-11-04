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

int h, w, k;
char s[15][15];

int ans = 0;
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

bool visited[15][15];
void solve(int i, int j, int turn) {
  if (turn == k) {
    ans++;
    return;
  }

  for (int l = 0; l < 4; l++) {
    int next_i = i + di[l], next_j = j + dj[l];

    if (s[next_i][next_j] == '.' && !visited[next_i][next_j]) {
      visited[next_i][next_j] = true;
      solve(next_i, next_j, turn + 1);
      visited[next_i][next_j] = false;
    }
  }

  return;
}

int main() {
  cin >> h >> w >> k;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (s[i][j] == '.') {
        visited[i][j] = true;
        solve(i, j, 0);
        visited[i][j] = false;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
