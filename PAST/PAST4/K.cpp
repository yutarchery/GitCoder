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

int k;
vector<int> a[int(1e5 + 5)];
ll above[int(1e5 + 5)][25], precious[int(1e5 + 5)][25], flip[int(1e5 + 5)];

ll cnt[25];
ll ans = 0;

ll calc_flip(int i) {
  vector<ll> tmp(21);
  ll res = 0;
  int n = a[i].size();

  for (int j = n - 1; j >= 0; j--) {
    for (int k = 0; k <= a[i][j] - 1; k++) {
      res += tmp[k];
      res %= ll(1e9);
    }
    tmp[a[i][j]]++;
  }

  return res;
}

int main() {
  cin >> k;
  for (int i = 1; i <= k; i++) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      int aij;
      cin >> aij;
      a[i].push_back(aij);
      precious[i][aij]++;
    }

    for (int j = 1; j <= 20; j++) {
      above[i][j] = above[i][j - 1] + precious[i][j];
    }

    flip[i] = calc_flip(i);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int b;
    cin >> b;

    for (int j = 1; j <= 20; j++) {
      ans += cnt[j] * above[b][j - 1];
      ans %= ll(1e9);
    }
    ans += flip[b];
    ans %= ll(1e9);

    for (int j = 0; j <= 20; j++) {
      cnt[j] += precious[b][j];
      cnt[j] %= ll(1e9);
    }
  }

  cout << ans << endl;

  return 0;
}