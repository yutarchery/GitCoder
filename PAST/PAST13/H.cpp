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

int d;
string n;
ll cnt[10];

int main() {
  cin >> d;
  cin >> n;

  for (int i = 0; i < d; i++) {
    cnt[n[i] - '0']++;
  }

  ll ans = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      ans += cnt[i] * cnt[j] * (j - i);
    }
  }
  cout << ans << endl;

  return 0;
}