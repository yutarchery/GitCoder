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

int r, c;
char b[25][25];

vector<Pii> ans;
const int di[4] = {-1, -1, 1, 1}, dj[4] = {-1, 1, -1, 1};

int main() {
  cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if ('1' <= b[i][j] && b[i][j] <= '9') {
        int num = b[i][j] - '0';
        for (int ii = 0; ii <= num; ii++) {
          for (int jj = 0; ii + jj <= num; jj++) {
            for (int k = 0; k < 4; k++) {
              ans.push_back({i + di[k] * ii, j + dj[k] * jj});
            }
          }
        }
      }
    }
  }

  for (Pii p : ans) {
    if (1 <= p.first && p.first <= r && 1 <= p.second && p.second <= c) {
      b[p.first][p.second] = '.';
    }
  }

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cout << b[i][j];
    }
    cout << endl;
  }

  return 0;
}
