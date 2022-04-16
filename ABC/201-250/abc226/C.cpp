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

int n;
ll t[int(2e5 + 5)];
vector<int> a[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
ll dp[int(2e5 + 5)];

ll search(int idx) {

  ll sum = t[idx];

  for (int before : a[idx]) {
    if (!visited[before]) {
      sum += search(before);
    }
  }

  visited[idx] = true;
  return dp[idx] = sum;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> t[i] >> k;
    a[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
    }
    sort(a[i].begin(), a[i].end(), greater<int>());
  }

  cout << search(n) << endl;

  return 0;
}