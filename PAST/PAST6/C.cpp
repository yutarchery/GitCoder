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

int n, m;
bool a[55][55];
int p, q, b[55];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int aij;
      cin >> aij;
      a[i][aij] = true;
    }
  }
  cin >> p >> q;
  for (int i = 1; i <= p; i++) {
    cin >> b[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= p; j++) {
      if (a[i][b[j]]) {
        cnt++;
      }
    }
    if (cnt >= q) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}