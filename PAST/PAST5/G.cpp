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

int h, w, k = 0;
string s[4];

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
int dist[4][4];
bool flag = false;

void solve(int i_start, int j_start, int d) {

  if (d == k) {
    if (flag) {
      return;
    }

    for (int l = 1; l <= k; l++) {
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          if (dist[i][j] == l) {
            cout << i + 1 << " " << j + 1 << endl;
          }
        }
      }
    }
    flag = true;
    return;
  }

  for (int l = 0; l < 4; l++) {
    int i_next = i_start + di[l], j_next = j_start + dj[l];

    if (0 <= i_next && i_next < h && 0 <= j_next && j_next < w) {
      if (s[i_next][j_next] == '#' && dist[i_next][j_next] == 0) {
        dist[i_next][j_next] = d + 1;
        solve(i_next, j_next, d + 1);
        dist[i_next][j_next] = 0;
      }
    }
  }

  return;
}

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        k++;
      }
    }
  }
  cout << k << endl;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        dist[i][j] = 1;
        solve(i, j, 1);
        dist[i][j] = 0;
      }
    }
  }

  return 0;
}