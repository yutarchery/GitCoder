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

int coins[6] = {500, 100, 50, 10, 5, 1};
int holes[6] = {0, 0, 1, 0, 1, 0};

int n, a, b, ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    int rest = b - a;
    for (int j = 0; j < 6; j++) {
      ans += (rest / coins[j]) * holes[j];
      rest -= (rest / coins[j]) * coins[j];
    }
  }
  cout << ans << endl;

  return 0;
}