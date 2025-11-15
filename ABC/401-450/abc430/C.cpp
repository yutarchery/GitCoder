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

int n, a, b;
char s[int(3e5 + 5)];

int cnt_a[int(3e5 + 5)], cnt_b[int(3e5 + 5)];

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] == 'a') {
      cnt_a[i]++;
    } else {
      cnt_b[i]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cnt_a[i] += cnt_a[i - 1];
    cnt_b[i] += cnt_b[i - 1];
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt_a[n] - cnt_a[i - 1] < a){
      break;
    }

    int a_ng = i - 1, a_ok = n;
    while (a_ok - a_ng > 1){
      int now = (a_ok + a_ng) / 2;
      if (cnt_a[now] - cnt_a[i - 1] >= a){
        a_ok = now;
      }else{
        a_ng = now;
      }
    }

    if (cnt_b[n] - cnt_b[i - 1] < b){
      ans += n - a_ok + 1;
      continue;
    }
    int b_ok = i - 1, b_ng = n;
    while (b_ng - b_ok > 1){
      int now = (b_ok + b_ng) / 2;
      if (cnt_b[now] - cnt_b[i - 1] < b){
        b_ok = now;
      }else{
        b_ng = now;
      }
    }
    ans += max(0, b_ok - a_ok + 1);
  }
  cout << ans << endl;

  return 0;
}
