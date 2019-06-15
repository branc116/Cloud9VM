#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>

using namespace std;
#define mod 1000000007

struct point{
    double x, y;
};
struct rectangle{
    point point1, point2;
};
struct circle{
    double r;
    point center;
};

int gcd(int a, int b){
    int c;
    while (a != 0) {
        c = a; a = b%a;  b = c;
    }
    return b;
}
int lcm(int a, int b){
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}
long long fast_pow(int a, int n){
    long long result = 1;
    long long power = n;
    long long value = a;
    while (power>0)
    {
        if (power & 1)
        {
            result = result*value;
            result = result % mod;
        }
        value = value*value;
        value = value % mod;
        power /= 2;
        //power >>= 1;
    }
    return result;
}
string s1,s2;
bool prov(int od1,int od2,int len){
    
    

    if (len%2){
        for (int i=0;i<len;i++){
            if (s1[i+od1]!=s2[i+od2])return false;    
        }
        return true;
    }
    
    
    len/=2;
    
    //cin >> temop;
    //cout << s11 << " " << s12 << " " << s21 << " " << s22 << endl;
    if ((prov(od1,od2,len)&&prov(od1+len,od2+len,len))||(prov(od1,od2+len,len)&&prov(od1+len,od2,len)))return true;
    return false;
}
int main()
{
    cin >> s1 >> s2;
    bool eql;
    eql=prov(0,0,s1.size());
    
    if (eql){cout << "YES";return 0;}
    cout << "NO";
    return 0;
}