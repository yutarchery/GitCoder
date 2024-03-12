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
ll p[305], m[1005][305];
string a[1005];

map<vector<ll>, ll> cnt;
bool visited[2005];

void prepare_primes() {
  visited[1] = true;
  int prime_cnt = 0;
  ll now = 1;
  while (prime_cnt < 50 && now <= 2000) {
    if (visited[now]) {
      now++;
      continue;
    }

    visited[now] = true;

    ll big_prime = now;
    while (big_prime < 1e9) {
      big_prime *= now;
    }
    if (big_prime <= 2e9) {
      prime_cnt++;
      p[prime_cnt] = big_prime;
    }

    for (int i = now; i < 2000; i += now) {
      visited[i] = true;
    }
  }

  return;
}

ll calculate(string s, ll mod) {
  ll ans = 0;
  for (int i = 0; i < s.length(); i++) {
    ans *= 10;
    ans += s[i] - '0';
    ans %= mod;
  }
  return ans;
}

int main() {
  prepare_primes();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vector<ll> v;
    for (int j = 1; j <= 20; j++) {
      m[i][j] = calculate(a[i], p[j]);
      v.push_back(m[i][j]);
    }
    cnt[v]++;
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      vector<ll> v;
      for (int k = 1; k <= 20; k++) {
        ll num = m[i][k] * m[j][k] % p[k];
        v.push_back(num);
      }
      ans += cnt[v];
    }
  }
  cout << ans << endl;

  return 0;
}
