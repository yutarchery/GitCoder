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

int a[5];
pair<int, string> ans[32];

bool compare(pair<int, string> &a, pair<int, string> &b) {
  if (a.first != b.first) {
    return a.first > b.first;
  } else {
    return a.second < b.second;
  }
}

int main() {
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < (1 << 5); i++) {
    int rest = i;
    for (int j = 0; j < 5; j++) {
      if (rest % 2 == 1) {
        ans[i].first += a[j];
        ans[i].second += char('A' + j);
      }
      rest /= 2;
    }
  }
  sort(ans + 1, ans + 32, compare);


  for (int i = 1; i < (1 << 5); i++){
    cout << ans[i].second << endl;
  }

  return 0;
}
