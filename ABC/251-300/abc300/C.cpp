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

int h, w, ans[105];
const int di[4] = {-1, -1, 1, 1}, dj[4] = {-1, 1, -1, 1};
char c[105][105];

int search(int start_i, int start_j) {
  vector<Pii> p;
  for (int k = 0; k < 4; k++) {
    p.push_back({start_i + di[k], start_j + dj[k]});
  }

  int res = 0;
  while (true) {
    bool flag = true;
    for (int k = 0; k < 4; k++) {
      if (c[p[k].first][p[k].second] != '#') {
        flag = false;
      }
      p[k].first += di[k];
      p[k].second += dj[k];
    }

    if (!flag) {
      break;
    } else {
      res++;
    }
  }

  return res;
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> c[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (c[i][j] == '#') {
        ans[search(i, j)]++;
      }
    }
  }

  for (int i = 1; i <= min(h, w); i++) {
    cout << ans[i];
    if (i == min(h, w)) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
