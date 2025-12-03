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

const char c[3] = {'A', 'B', 'C'};
const int di[3][4] = {{0, 1, -1, 0}, {1, 0, 0, -1}, {-1, 0, 0, 1}};
const int dj[3][4] = {{1, 0, 0, -1}, {0, 1, -1, 0}, {0, -1, 1, 0}};
const int dk[3][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}};

int h, w;
vector<char> s[int(2e5 + 5)];
vector<int> ans[4][int(2e5 + 5)];
vector<bool> visited[4][int(2e5 + 5)];

void prepare() {
  cin >> h >> w;

  for (int i = 0; i <= h + 1; i++) {
    s[i].resize(w + 2);
  }
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i <= h + 1; i++) {
      ans[k][i].resize(w + 2, 0);
      visited[k][i].resize(w + 2, false);
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  return;
}

struct Location {
  int dist, dir, i, j;
};
auto operator<=>(const Location &a, const Location &b) {
  return a.dist <=> b.dist;
}

int solve() {
  priority_queue<Location, vector<Location>, greater<Location>> que;
  que.push({0, 0, 1, 1});

  while (!que.empty()) {
    Location q = que.top();
    que.pop();
    if (visited[q.dir][q.i][q.j]) {
      continue;
    }

    visited[q.dir][q.i][q.j] = true;
    ans[q.dir][q.i][q.j] = q.dist;

    if (1 <= q.i && q.i <= h && 1 <= q.j && q.j <= w) {
      for (int a = 0; a < 3; a++) {
        if (c[a] == s[q.i][q.j]) {
          que.push(
              {q.dist, dk[a][q.dir], q.i + di[a][q.dir], q.j + dj[a][q.dir]});
        } else {
          que.push({q.dist + 1, dk[a][q.dir], q.i + di[a][q.dir],
                    q.j + dj[a][q.dir]});
        }
      }
    }
  }

  return ans[0][h][w + 1];
}

void reset() {
  for (int i = 0; i <= h + 1; i++) {
    s[i].resize(0);
    for (int k = 0; k < 4; k++) {
      ans[k][i].resize(0);
      visited[k][i].resize(0);
    }
  }

  return;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    prepare();
    cout << solve() << endl;
    reset();
  }

  return 0;
}
