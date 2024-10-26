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

ll n, m, a, b;
map<Pll, bool> visited;

const ll di[2] = {1, 2}, dj[2] = {2, 1}, dk[2] = {-1, 1};
ll ans;

int main() {
  cin >> n >> m;
  ans = n * n;

  while (m--) {
    cin >> a >> b;
    if (!visited[{a, b}]) {
      ans--;
      visited[{a, b}] = true;
    }

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          ll now_a = a + di[i] * dk[j], now_b = b + dj[i] * dk[k];
          if (1 <= now_a && now_a <= n && 1 <= now_b && now_b <= n &&
              !visited[{now_a, now_b}]) {
            ans--;
            visited[{now_a, now_b}] = true;
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
