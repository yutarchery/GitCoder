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

ll Pow(ll A, ll N){
  if (N == 0) return 1;
  if (N % 2 == 0) return Pow(A * A % MOD2, N / 2);
  else return Pow(A * A % MOD2, N / 2) * A % MOD2;
}

int N, F[int(2e5 + 5)], loopIndex[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> F[i];
  
  int loopCount = 0, tryCount = 0, startNode = 1;
  queue <int> que; que.push(startNode);
  visited[startNode] = true;

  while (!que.empty()){
    int Q = que.front(); que.pop();

    if (visited[F[Q]]){
      if (loopIndex[F[Q]] == loopIndex[Q]) loopCount++;
      tryCount++;
      for (int i = startNode; i <= N; i++){
        if (!visited[i]){
          visited[i] = true;
          que.push(i);
          loopIndex[i] = tryCount;
          startNode = i;
          break;
        }
      }
    }else{
      visited[F[Q]] = true;
      loopIndex[F[Q]] = loopIndex[Q];
      que.push(F[Q]);
    }
  }
   
  ll ans = Pow(2, loopCount) - 1;
  if (ans < 0) ans += MOD2;
  cout << ans << endl;

  return 0;
}