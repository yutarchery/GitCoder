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
char s[1005][1005];

int i_min = 1e9, i_max = 0, j_min = 1e9, j_max = 0;

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
      if (s[i][j] == '#') {
        i_min = min(i_min, i), i_max = max(i_max, i);
        j_min = min(j_min, j), j_max = max(j_max, j);
      }
    }
  }

  for (int i = i_min; i <= i_max; i++) {
    for (int j = j_min; j <= j_max; j++) {
      if (s[i][j] == '.') {
        No();
        return 0;
      }
    }
  }
  Yes();

  return 0;
}
