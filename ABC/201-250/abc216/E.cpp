#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int n, k;
ll a[int(1e5 + 5)];

int main(){
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());

  ll ans = 0, rest = k;
  for (ll i = 0; i < n; i++){
    ll diff = a[i] - a[i + 1];

    if (diff * (i + 1) < rest){
      rest -= diff * (i + 1);
      ans += (a[i] + a[i + 1] + 1) * diff / 2 * (i + 1);
      continue;
    }

    ans += (a[i] * 2 + 1 - rest / (i + 1)) * (rest / (i + 1)) / 2 * (i + 1);

    ans += (a[i] - rest / (i + 1)) * (rest % (i + 1));

    break;
  }

  cout << ans << endl;

  return 0;
}