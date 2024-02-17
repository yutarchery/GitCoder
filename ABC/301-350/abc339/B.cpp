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
char c[105][105];

int now_i = 0, now_j = 0, dir = 0;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

int main() {
  cin >> h >> w >> n;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      c[i][j] = '.';
    }
  }

  for (int i = 1; i <= n; i++) {
    if (c[now_i][now_j] == '.') {
      c[now_i][now_j] = '#';
      dir = (dir + 1) % 4;
    } else {
      c[now_i][now_j] = '.';
      dir = (dir + 3) % 4;
    }

    now_i = (now_i + di[dir] + h) % h;
    now_j = (now_j + dj[dir] + w) % w;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << c[i][j];
    }
    cout << endl;
  }

  return 0;
}
