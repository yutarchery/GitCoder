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

string n;
ll ans = 500;

int main() {
  cin >> n;
  char now = n[0];
  for (int i = 1; i < n.length(); i++) {
    if (now == n[i]) {
      ans += 301;
      continue;
    }

    if ('1' <= now && now <= '5') {
      if ('1' <= n[i] && n[i] <= '5') {
        ans += 210;
      } else {
        ans += 100;
      }
    } else {
      if ('1' <= n[i] && n[i] <= '5') {
        ans += 100;
      } else {
        ans += 210;
      }
    }
    now = n[i];
  }
  cout << ans << endl;

  return 0;
}