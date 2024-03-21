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

int h, w, k;
string s[int(2e5 + 5)];
int ans = 1e9;

int main() {
  cin >> h >> w >> k;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < h; i++) {
    int start = 0, cnt = 0;
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'x') {
        start = j + 1;
        cnt = 0;
      } else if (s[i][j] == '.') {
        cnt++;
      }

      if (j - start == k - 1) {
        ans = min(ans, cnt);

        if (s[i][start] == '.') {
          cnt--;
        }

        start++;
      }
    }
  }
  for (int j = 0; j < w; j++) {
    int start = 0, cnt = 0;
    for (int i = 0; i < h; i++) {
      if (s[i][j] == 'x') {
        start = i + 1;
        cnt = 0;
      } else if (s[i][j] == '.') {
        cnt++;
      }

      if (i - start == k - 1) {
        ans = min(ans, cnt);

        if (s[start][j] == '.') {
          cnt--;
        }

        start++;
      }
    }
  }

  if (ans == 1e9) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
