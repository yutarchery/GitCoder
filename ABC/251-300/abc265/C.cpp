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

int h, w;
char g[505][505];

bool visited[505][505];
const int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};
const char c[4] = {'U', 'D', 'L', 'R'};

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> g[i][j];
    }
  }

  int i = 1, j = 1;
  visited[i][j] = true;

  while (true) {
    int next_i, next_j;
    for (int k = 0; k < 4; k++) {
      if (c[k] == g[i][j]) {
        next_i = i + di[k];
        next_j = j + dj[k];
        break;
      }
    }

    if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w) {
      i = next_i;
      j = next_j;

      if (visited[i][j]) {
        cout << -1 << endl;
        return 0;
      } else {
        visited[i][j] = true;
      }
    } else {
      cout << i << " " << j << endl;
      return 0;
    }
  }

  return 0;
}
