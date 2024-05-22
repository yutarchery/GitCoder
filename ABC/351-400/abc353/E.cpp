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

int n;
string s[int(3e5 + 5)];

ll ans = 0;
const int sz = 50;
array<ll, sz> mods;
map<array<ll, sz>, ll> cnt;

bool is_prime(ll num) {
  for (ll i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

void prepare() {
  ll num = 2;
  for (int i = 0; i < sz; i++) {
    while (!is_prime(num)) {
      num++;
    }
    mods[i] = num;
    num++;
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  prepare();
  for (int i = 1; i <= n; i++) {
    array<ll, sz> now = {};

    for (int j = 0; j < s[i].length(); j++) {
      for (int k = 0; k < sz; k++) {
        now[k] *= MOD2;
        now[k] += s[i][j];
        now[k] %= mods[k];
      }

      ans += cnt[now];
      cnt[now]++;
    }
  }
  cout << ans << endl;

  return 0;
}
