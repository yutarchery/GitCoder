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
char a[35][35], b[35][35], c[35][35];

bool judge(int dh, int dw) {
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      c[(i + dh) % h + 1][(j + dw) % w + 1] = a[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (b[i][j] != c[i][j]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> b[i][j];
    }
  }

  for (int i = 0; i <= h; i++){
    for (int j = 0; j <= w; j++){
      if (judge(i,j)){
        Yes();
        return 0;
      }
    }
  }
  No();

  return 0;
}
