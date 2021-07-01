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

int N, A[105], sum;

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++){
    cin >> A[i];
    sum += A[i];
  }

  if (sum % N != 0){
    cout << -1 << endl;
    return 0;
  }

  int ans = 0, now = 0;
  for (int i = 1; i <= N; i++){
    now += A[i];
    if (now != i * (sum / N)){
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}