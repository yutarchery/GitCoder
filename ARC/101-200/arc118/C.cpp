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
vector<int> ans;

void prepare() {
  for (int i = 1; i <= 10000; i++) {
    if (i % 6 == 0 || i % 10 == 0 || i % 15 == 0) {
      ans.push_back(i);
    }
  }
  swap(ans[2], ans[3]);
}

int main() {
  prepare();

  cin >> n;
  cout << ans[0];
  for (int i = 1; i < n; i++) {
    cout << " " << ans[i];
  }
  cout << endl;

  return 0;
}