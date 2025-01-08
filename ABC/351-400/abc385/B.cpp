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

int h, w, x, y;
char s[105][105];
string t;

const char c[4] = {'U', 'L', 'D', 'R'};
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int ans = 0;
bool visited[105][105];

int main() {
  cin >> h >> w >> x >> y;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }
  cin >> t;

  for (int l = 0; l < t.length(); l++) {
    int next_i, next_j;
    for (int k = 0; k < 4; k++) {
      if (t[l] == c[k]) {
        next_i = x + di[k];
        next_j = y + dj[k];
        break;
      }
    }

    if (s[next_i][next_j] != '#') {
      x = next_i;
      y = next_j;
      if (s[x][y] == '@' && !visited[x][y]) {
        visited[x][y]=true;
        ans++;
      }
    }
  }
  cout << x << " " << y << " " << ans << endl;

  return 0;
}
