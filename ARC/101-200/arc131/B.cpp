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
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
string s[705];

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] != '.') {
        continue;
      }

      bool used[5] = {};
      for (int k = 0; k < 4; k++) {
        int next_i = i + di[k], next_j = j + dj[k];

        if (0 <= next_i && next_i < h && 0 <= next_j && next_j < w &&
            s[next_i][next_j] != '.') {
          used[s[next_i][next_j] - '1'] = true;
        }

        for (int k = 0; k < 5; k++) {
          if (!used[k]) {
            s[i][j] = '1' + k;
            break;
          }
        }
      }
    }
    cout << s[i] << endl;
  }

  return 0;
}