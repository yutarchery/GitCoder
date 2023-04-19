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

char dir[4] = {'v', '>', '^', '<'};
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

int h, w, r, c;
string s[int(1e6 + 5)];
vector<bool> visited[int(1e6 + 5)];

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    visited[i].resize(w);
    fill(visited[i].begin(), visited[i].end(), false);
  }
  cin >> r >> c;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  queue<Pii> que;
  visited[r - 1][c - 1] = true;
  que.push({r - 1, c - 1});

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (int k = 0; k < 4; k++) {
      int i = q.first + di[k], j = q.second + dj[k];
      if (0 <= i && i < h && 0 <= j && j < w) {
        if (s[i][j] == '#' || visited[i][j]) {
          continue;
        }

        if (s[i][j] == '.') {
          que.push({i, j});
          visited[i][j] = true;
        } else {
          if (s[i][j] == dir[k]) {
            que.push({i, j});
            visited[i][j] = true;
          }
        }
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        cout << '#';
      } else {
        if (visited[i][j]) {
          cout << 'o';
        } else {
          cout << 'x';
        }
      }
    }
    cout << endl;
  }

  return 0;
}