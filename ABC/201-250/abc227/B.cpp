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

int n, s, ans;
map<int, bool> visited;

int main() {
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000 && 4 * i * j + 3 * i + 3 * j <= 1000; j++) {
      visited[4 * i * j + 3 * i + 3 * j] = true;
    }
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (!visited[s]) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
