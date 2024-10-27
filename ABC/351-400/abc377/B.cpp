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

char s[8][8];
bool h[8], w[8];
int cnt_h = 8, cnt_w = 8;

int main() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> s[i][j];
      if (s[i][j] == '#') {
        if (!h[i]) {
          cnt_h--;
        }
        if (!w[j]) {
          cnt_w--;
        }
        h[i] = true;
        w[j] = true;
      }
    }
  }

  cout << cnt_h * cnt_w << endl;

  return 0;
}
