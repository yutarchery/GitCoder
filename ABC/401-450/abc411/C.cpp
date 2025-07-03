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

int n, q, a[int(5e5 + 5)];
bool visited[int(5e5 + 5)];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 1; i <= q; i++) {
    if (visited[a[i]]) {
      if (visited[a[i] - 1] && visited[a[i] + 1]) {
        ans++;
      } else if (!visited[a[i] - 1] && !visited[a[i] + 1]) {
        ans--;
      }
      visited[a[i]] = false;
    } else {
      if (!visited[a[i] - 1] && !visited[a[i] + 1]) {
        ans++;
      } else if (visited[a[i] - 1] && visited[a[i] + 1]) {
        ans--;
      }
      visited[a[i]] = true;
    }

    cout << ans << endl;
  }

  return 0;
}
