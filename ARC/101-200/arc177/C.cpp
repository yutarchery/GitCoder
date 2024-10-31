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

int n, r[505][505], b[505][505];
char c[505][505];
bool visited_r[505][505], visited_b[505][505];

priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que_r, que_b;
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];
    }
  }

  que_r.push({0, {1, 1}});
  while (!que_r.empty()) {
    pair<int, Pii> p = que_r.top();
    que_r.pop();

    Pii q = p.second;
    if (visited_r[q.first][q.second]) {
      continue;
    }
    visited_r[q.first][q.second] = true;
    r[q.first][q.second] = p.first;

    for (int k = 0; k < 4; k++) {
      int i = q.first + di[k], j = q.second + dj[k];
      if (1 <= i && i <= n && 1 <= j && j <= n && !visited_r[i][j]) {
        if (c[i][j] == 'R') {
          que_r.push({r[q.first][q.second], {i, j}});
        } else {
          que_r.push({r[q.first][q.second] + 1, {i, j}});
        }
      }
    }
  }

  que_b.push({0, {1, n}});
  while (!que_b.empty()) {
    pair<int, Pii> p = que_b.top();
    que_b.pop();

    Pii q = p.second;
    if (visited_b[q.first][q.second]) {
      continue;
    }
    visited_b[q.first][q.second] = true;
    b[q.first][q.second] = p.first;

    for (int k = 0; k < 4; k++) {
      int i = q.first + di[k], j = q.second + dj[k];
      if (1 <= i && i <= n && 1 <= j && j <= n && !visited_b[i][j]) {
        if (c[i][j] == 'B') {
          que_b.push({b[q.first][q.second], {i, j}});
        } else {
          que_b.push({b[q.first][q.second] + 1, {i, j}});
        }
      }
    }
  }

  cout << r[n][n] + b[n][1] << endl;

  return 0;
}
