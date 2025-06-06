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

vector<ll> v, primes;
bool is_prime[int(1e6 + 5)], visited[int(1e6 + 5)];

void prepare() {
  for (int i = 2; i <= int(5e5); i++) {
    if (visited[i]) {
      continue;
    }

    is_prime[i] = true;
    primes.push_back(i);
    for (int j = i; j <= int(5e5); j += i) {
      visited[j] = true;
    }
  }

  for (int i = 0; i < primes.size(); i++) {
    ll now = primes[i];
    while (now <= ll(1e6)) {
      for (int j = i + 1; j < primes.size(); j++) {
        if (now * primes[j] > ll(1e6)) {
          break;
        }

        ll q = now * primes[j];
        while (q <= ll(1e6)) {
          v.push_back(q);
          q *= primes[j];
        }
      }

      now *= primes[i];
    }
  }

  sort(v.begin(), v.end());
  return;
}

int main() {
  prepare();

  int q;
  cin >> q;

  while (q--) {
    ll a;
    cin >> a;

    int ok = 0, ng = v.size();
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;

      if (v[mid] * v[mid] <= a) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    cout << v[ok] * v[ok] << endl;
  }

  return 0;
}
