#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

class Node {
    public:
    int val;
    Node *left,*right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll to_number(string s) {
    ll ans = 0;
    int n = s.size(),i;
    for(i=0;i<n;i++) {
        ans = ans*10 + (s[i]-'0');
    }
    
    return ans;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t,cs=0;
    cin>>t;
    while(t--) {
        cs++;
        int i,j,k,n;
        cin>>n;
        vector<int> v(n);
        for(i=0;i<n;i++) cin>>v[i];
        
        int count = 0;
        int flag = 0;
        for(i=0;i<n-1;i++) {
            if(v[i] == v[i+1]) {
                count++;
                if(flag)
                flag = 2;
            }
            else {
                if(count && flag == 0) {
                    flag=1;
                }
            }
        }
        
        int ans = 0;
        if(count < 2) ans = 0;
        else {
            if(flag == 2) {
                int l = 0,r = n-1;
                while(l<n) {
                    if(v[l] == v[l+1]) break;
                    l++;
                }
                
                while(r>=0) {
                    if(v[r] == v[r-1]) break;
                    r--;
                }
                
                count = r-l;
            }
            
                ans = max(count-2,1);
            
        }
        cout<<ans<<endl;
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
