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
int cnt[int(1e7 + 5)];
vector<int> ans;

int main() {
  cin >> n;
  for (int i = 1; i * i <= n; i++) {
    for (int j = i + 1; i * i + j * j <= n; j++) {
      cnt[i * i + j * j]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 1) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ((i == ans.size() - 1) ? '\n' : ' ');
  }

  return 0;
}
