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

int m, order[3] = {0, 1, 2};
string s[3];
bool visited[3][10][305];

int ans = 1e9;

int check(int target) {
  int now = 0;
  for (int i = 0; i < 3; i++) {
    while (!visited[order[i]][target][now]) {
      now++;

      if (now > 3 * m) {
        return 1e9;
      }
    }

    if (i < 2) {
      now++;
    }
  }

  return now;
}

int main() {
  cin >> m;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      visited[i][s[i][j] - '0'][j] = true;
      visited[i][s[i][j] - '0'][j + m] = true;
      visited[i][s[i][j] - '0'][j + m * 2] = true;
    }
  }

  do {
    for (int i = 0; i < 10; i++) {
      ans = min(ans, check(i));
    }
  } while (next_permutation(order, order + 3));

  if (ans == 1e9) {
    ans = -1;
  }
  cout << ans << endl;

  return 0;
}