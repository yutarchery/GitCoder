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

bool used[200];
ll t, N;
vector <ll> notUsed;

int main(){
  cin >> t >> N;
  N--;
  for (int i = 1; i <= 100; i++){
    int now = i * (100 + t) / 100;
    used[now] = true;
  }
  
  for (int i = 1; i <= 100 + t; i++){
    if (!used[i]) notUsed.push_back(i);
  }

  ll notUsedCount = notUsed.size();
  ll ans = (100 + t) * (N / notUsedCount);
  N %= notUsedCount;
  ans += notUsed[N];
  cout << ans << endl;

  return 0;
}