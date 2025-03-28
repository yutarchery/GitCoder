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
ll s, a[6];

bool now[5];

ll solve(int num) {
  for (int i = 0; i < n - 1; i++) {
    now[i] = num % 2;
    num /= 2;
  }

  queue<ll> que;
  ll q = a[0];
  for (int i = 0; i < n - 1; i++) {
    if (now[i]) {
      que.push(q);
      q = a[i + 1];
    } else {
      q *= a[i + 1];
    }
  }
  que.push(q);

  ll ans = 0;
  while (!que.empty()) {
    ans += que.front();
    que.pop();
  }

  return ans;
}

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);

  do {
    for (int i = 0; i < (1 << (n - 1)); i++) {
      if (solve(i) == s) {
        Yes();
        for (int j = 0; j < n - 1; j++) {
          cout << a[j] << (now[j] ? '+' : 'x');
        }
        cout << a[n - 1] << endl;
        return 0;
      }
    }
  } while (next_permutation(a, a + n));

  No();

  return 0;
}
