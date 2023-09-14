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

int di[3] = {-1, 0, 1}, dj[3] = {-1, 0, 1};

int check(int h, int w) {
  bool used[105][105] = {};
  int cnt = 0;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (used[i][j]) {
        continue;
      }

      cnt++;
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          used[i + di[k]][j + dj[l]] = true;
        }
      }
    }
  }

  return cnt;
}

int main() {
  int h, w;
  cin >> h >> w;

  if (h == 1 || w == 1) {
    cout << h * w << endl;
  } else {
    cout << max(check(h, w), check(w, h)) << endl;
  }

  return 0;
}