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
string s[505], t;
vector<int> v;
const char c[4] = {'L', 'R', 'U', 'D'};
const int di[4] = {0, 0, -1, 1}, dj[4] = {-1, 1, 0, 0};
bool visited[505][505];

Pii judge(int i, int j) {
  for (int k = 0; k < n; k++) {
    i += di[v[k]];
    j += dj[v[k]];

    if (s[i][j] == '#') {
      return {-1, -1};
    }
  }
  return {i, j};
}

int main() {
  cin >> h >> w >> n;
  cin >> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      if (t[i] == c[j]) {
        v.push_back(j);
      }
    }
  }
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.') {
        Pii goal = judge(i, j);
        if (goal.first != -1) {
          if (!visited[goal.first][goal.second]) {
            ans++;
          }
          visited[goal.first][goal.second] = true;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
