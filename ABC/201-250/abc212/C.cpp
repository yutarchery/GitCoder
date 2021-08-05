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

int n, m;
int a[int(2e5 + 5)], b[int(2e5 + 5)];
int ans;

int solve(int i){
  if (a[i] >= b[m - 1]){
    ans = min(ans, a[i] - b[m - 1]);
    return 0;
  }
  if (a[i] <= b[0]){
    ans = min(ans, b[0] - a[i]);
    return 0;
  }

  int l = 0, r = m - 1;
  while (r - l > 1){
    int mid = (l + r) / 2;
    if (b[mid] <= a[i]) l = mid;
    else r = mid;
  }

  ans = min(ans, min(a[i] - b[l], b[r] - a[i]));
  return 0;
}

int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(b, b + m);

  ans = max(a[n - 1], b[m - 1]);
  for (int i = 0; i < n; i++){
    solve(i);
  }
  cout << ans << endl;


  return 0;
}