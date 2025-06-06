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

char s[2][2];

int main() {
  int cnt = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> s[i][j];
      if (s[i][j] == '#') {
        cnt++;
      }
    }
  }

  if (cnt == 2) {
    if (s[0][0] == '#' && s[1][1] == '#') {
      No();
    } else if (s[0][1] == '#' && s[1][0] == '#') {
      No();
    } else {
      Yes();
    }
  } else {
    Yes();
  }
  return 0;
}
