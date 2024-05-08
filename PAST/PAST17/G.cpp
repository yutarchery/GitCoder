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

int h, w, n;
char c[15][15];
string s;

bool visited[15][15], ans = false;
const int di[3] = {-1, 0, 1}, dj[3] = {-1, 0, 1};

void judge(int i, int j, int turn, string t) {
  if (turn == n) {
    if (s == t) {
      ans = true;
    }
    return;
  }

  for (int k = 0; k < 3; k++) {
    for (int l = 0; l < 3; l++) {
      int next_i = i + di[k], next_j = j + dj[l];
      if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w &&
          !visited[next_i][next_j]) {
        visited[next_i][next_j] = true;
        judge(next_i, next_j, turn + 1, t + c[next_i][next_j]);
        visited[next_i][next_j] = false;
      }
    }
  }
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> c[i][j];
    }
  }
  cin >> n;
  cin >> s;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      judge(i, j, 0, "");
    }
  }

  if (ans) {
    Yes();
  } else {
    No();
  }

  return 0;
}
