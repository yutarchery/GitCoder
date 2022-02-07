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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
ll ans, a[20][20];

bool visited[20];

int solve(ll now, int turn) {
  if (turn == n) {
    ans = max(ans, now);
    return 0;
  }

  for (int i = 0; i < 2 * n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      for (int j = i + 1; j < 2 * n; j++) {
        if (!visited[j]) {
          visited[j] = true;
          solve(now ^ a[i][j], turn + 1);
          visited[j] = false;
        }
      }
      visited[i] = false;
      break;
    }
  }
  return 0;
}

int main() {
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      cin >> a[i][j];
    }
  }
  solve(0, 0);
  cout << ans << endl;

  return 0;
}