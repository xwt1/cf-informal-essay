#include <bits/stdc++.h>
#define Mod 998244353;
using namespace std;
const int Maxn=1e6+10;
long long ans[Maxn],p[Maxn];
long long quickpow(long long a,long long b){
    long long base=a%Mod;
    long long ans=1;
    while(b){
        if(b&1) ans=(base*ans)%Mod;
        base=(base*base)%Mod;
        b>>=1;
    }
    return ans;
}
int main() {
    long long n,p;
    scanf("%lld",&n);
    long long sum=20;
    ans[1]=10;
    p=10;
    for(long long i=2;i<=n;i++){
        ans[i]=(quickpow(10,i)*i)%Mod;
        ans[i]=ans[i]-sum+Mod;
        ans[i]%=Mod;
        p=(p+ans[i])%Mod;
        sum=(sum+p+ans[i])%Mod;
    }
    for(int i=n;i>=1;i--)   printf("%lld ",ans[i]);
    return 0;
}
