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

int n, a, b, c, d;
bool visited[105][105];

void prepare() {
  for (int i = a + 1; i <= b; i++) {
    for (int j = c + 1; j <= d; j++) {
      visited[i][j] = true;
    }
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> c >> d;
    prepare();
  }

  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      if (visited[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
