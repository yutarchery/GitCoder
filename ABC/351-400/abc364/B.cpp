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

int h, w, si, sj;
char c[55][55];
string x;

const char dir[4] = {'L', 'R', 'U', 'D'};
const int di[4] = {0, 0, -1, 1}, dj[4] = {-1, 1, 0, 0};

int main() {
  cin >> h >> w;
  cin >> si >> sj;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> c[i][j];
    }
  }
  cin >> x;

  for (int i = 0; i < x.length(); i++) {
    int next_i = si, next_j = sj;
    for (int k = 0; k < 4; k++) {
      if (x[i] == dir[k]) {
        next_i += di[k];
        next_j += dj[k];
      }
    }

    if (c[next_i][next_j] == '.') {
      si = next_i;
      sj = next_j;
    }
  }
  cout << si << " " << sj << endl;

  return 0;
}
