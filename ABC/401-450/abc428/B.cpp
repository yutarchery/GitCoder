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

int n, k;
char s[105];

int x = 0;
vector<string> ans, cand;
map<string, int> cnt;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i + (k - 1) <= n; i++) {
    string now = "";
    for (int j = 0; j < k; j++) {
      now += s[i + j];
    }
    if (cnt[now] == 0) {
      cand.push_back(now);
    }
    cnt[now]++;
    x = max(x, cnt[now]);
  }

  for (string c : cand) {
    if (x == cnt[c]) {
      ans.push_back(c);
    }
  }
  sort(ans.begin(), ans.end());

  cout << x << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
