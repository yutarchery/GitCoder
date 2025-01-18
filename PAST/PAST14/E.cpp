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
string s[int(4e5 + 5)], t[int(4e5 + 5)];
int cnt_s[int(4e5 + 5)], cnt_t[int(4e5 + 5)];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        cnt_s[i]++;
      }
    }
  }
  for (int i = 1; i <= h; i++) {
    cin >> t[i];
    for (int j = 0; j < w; j++) {
      if (t[i][j] == '#') {
        cnt_t[i]++;
      }
    }
  }

  for (int i = 1; i <= h; i++) {
    if (cnt_s[i] != cnt_t[i]) {
      No();
      return 0;
    }
  }
  Yes();

  return 0;
}
