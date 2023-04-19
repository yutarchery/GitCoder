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

int n, k;
string s[int(1e5 + 5)];
vector<pair<int, string>> ans;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  sort(s + 1, s + n + 1);

  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == s[i + 1]) {
      cnt++;
    } else {
      ans.push_back({cnt, s[i]});
      cnt = 1;
    }
  }
  sort(ans.begin(), ans.end(), greater<pair<int, string>>());

  bool flag = true;
  if (k - 2 >= 0 && ans[k - 1].first == ans[k - 2].first) {
    flag = false;
  }
  if (k <= ans.size() - 1 && ans[k - 1].first == ans[k].first) {
    flag = false;
  }

  if (flag) {
    cout << ans[k - 1].second << endl;
  } else {
    cout << "AMBIGUOUS" << endl;
  }
  return 0;
}