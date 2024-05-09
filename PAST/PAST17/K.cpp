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

int n;
string s;

bool visited[int(2e5 + 5)][10][10];
int ans[int(2e5 + 5)];

int main() {
  cin >> n;
  cin >> s;

  visited[0][0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      bool flag = false;
      for (int k = 0; k <= 9; k++) {
        if (visited[i - 1][j][k]) {
          flag = true;
        }
      }
      if (!flag) {
        continue;
      }

      if (s[i - 1] == '?') {
        for (int k = 0; k <= 9; k++) {
          visited[i][(j + k * i) % 10][k] = true;
        }
      } else {
        int now = s[i - 1] - '0';
        visited[i][(j + i * now) % 10][now] = true;
      }
    }
  }

  bool flag = false;
  int now = 0, sum = 0;
  for (int k = 0; k <= 9; k++) {
    if (visited[n][0][k]) {
      flag = true;
      now = k;
    }
  }

  if (!flag) {
    No();
    return 0;
  }

  Yes();
  for (int i = n; i >= 1; i--) {
    ans[i] = now;

    sum = (sum - (now * i)) % 10;
    if (sum < 0) {
      sum += 10;
    }

    for (int k = 0; k <= 9; k++) {
      if (visited[i - 1][sum][k]) {
        now = k;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
