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
string s[505];

int min_h, min_w, max_h, max_w;

int main() {
  cin >> h >> w;
  min_h = h;
  min_w = w;

  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        min_h = min(i, min_h);
        min_w = min(j, min_w);
        max_h = max(i, max_h);
        max_w = max(j, max_w);
      }
    }
  }

  for (int i = min_h; i <= max_h; i++) {
    for (int j = min_w; j <= max_w; j++) {
      if (s[i][j] == '.') {
        cout << i + 1 << " " << j + 1 << endl;
        return 0;
      }
    }
  }

  return 0;
}