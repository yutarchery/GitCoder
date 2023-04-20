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
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

string s[int(1e6 + 5)];
vector<bool> visited1[int(1e6 + 5)], visited2[int(1e6 + 5)];

int start_i, start_j;

bool solve(int k1, int k2) {
  for (int i = 0; i < h; i++) {
    fill(visited1[i].begin(), visited1[i].end(), false);
    fill(visited2[i].begin(), visited2[i].end(), false);
  }

  queue<Pii> que1, que2;
  que1.push({start_i + di[k1], start_j + dj[k1]});
  que2.push({start_i + di[k2], start_j + dj[k2]});

  while (!que1.empty()) {
    Pii q = que1.front();
    que1.pop();
    for (int k = 0; k < 4; k++) {
      int next_i = q.first + di[k], next_j = q.second + dj[k];
      if (0 <= next_i && next_i < h && 0 <= next_j && next_j < w) {
        if (s[next_i][next_j] == '.' && !visited1[next_i][next_j]) {
          visited1[next_i][next_j] = true;
          que1.push({next_i, next_j});
        }
      }
    }
  }

  while (!que2.empty()) {
    Pii q = que2.front();
    que2.pop();

    if (visited1[q.first][q.second]) {
      return true;
    }

    for (int k = 0; k < 4; k++) {
      int next_i = q.first + di[k], next_j = q.second + dj[k];
      if (0 <= next_i && next_i < h && 0 <= next_j && next_j < w) {
        if (s[next_i][next_j] == '.' && !visited2[next_i][next_j]) {
          visited2[next_i][next_j] = true;
          que2.push({next_i, next_j});
        }
      }
    }
  }

  return false;
}

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    visited1[i].resize(w);
    visited2[i].resize(w);
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'S') {
        start_i = i;
        start_j = j;
      }
    }
  }

  for (int k = 0; k < 4; k++) {
    int i1 = start_i + di[k], j1 = start_j + dj[k];
    if (!(0 <= i1 && i1 < h && 0 <= j1 && j1 < w && s[i1][j1] == '.')) {
      continue;
    }
    for (int l = k + 1; l < 4; l++) {
      int i2 = start_i + di[l], j2 = start_j + dj[l];
      if (0 <= i2 && i2 < h && 0 <= j2 && j2 < w && s[i2][j2] == '.') {
        if (solve(k, l)) {
          Yes();
          return 0;
        }
      }
    }
  }

  No();
  return 0;
}