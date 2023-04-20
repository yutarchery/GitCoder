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

int n, k, a[105];
bool dp[2][int(1e5 + 5)], visited[2][int(1e5 + 5)];

bool solve(int turn, int rest) {
  if (visited[turn][rest]) {
    return dp[turn][rest];
  }

  visited[turn][rest] = true;
  bool ans = false;
  for (int i = 0; i < n; i++) {
    if (rest >= a[i]) {
      if (!solve(1 - turn, rest - a[i])) {
        ans = true;
      }
    }
  }
  return dp[turn][rest] = ans;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (solve(0, k)) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }

  return 0;
}