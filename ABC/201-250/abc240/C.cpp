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

int n, x;
ll a[105], b[105];
bool visited[105][10005];

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  visited[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 10000; j++) {
      if (visited[i - 1][j]) {
        visited[i][j + a[i]] = true;
        visited[i][j + b[i]] = true;
      }
    }
  }

  if (visited[n][x]) {
    Yes();
  } else {
    No();
  }

  return 0;
}