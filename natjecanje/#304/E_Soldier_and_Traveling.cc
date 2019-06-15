#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <iomanip>
#include <list>
#include <queue>

using namespace std;
#define mod 1000000007
#define eps (1.0E-9)

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
struct connected{
    int amount;
    vector<int> o;
};
vector<connected> q;
bool p[101][101];
int n1[101],n2[101],ndelta[101],s1,s2;
int n,m;
int out[101][101];

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
void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
}
void input(){
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> n1[i];
        s1+=n1[i];
    }
    for (int i=0;i<n;i++){
        cin >> n2[i];
        s2+=n2[i];
    }
    for (int i=0;i<n;i++){
        ndelta[i]=n2[i]-n1[i];
    }
    for (int i=0;i<m;i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        p[temp1-1][temp2-1]=true;
        p[temp2-1][temp1-1]=true;
    }
    
}
bool bil[101];
connected con(int i,connected a){
    if (bil[i])return a;
    a.o.push_back(i);
    a.amount++;
    bil[i]=true;
    for (int j=0;j<n;j++){
        if (p[i][j])a=con(j,a);
    }
    return a;
}
bool prov(){
    for (int i=0;i<q.size();i++){
        connected temp=q[i];
        int tempsum1=0,tempsum2=0;
        //cout << i << ": ";
        for (int j=0;j<temp.amount;j++){
           // cout << temp.o[j] << "  ";
            tempsum1+=n1[temp.o[j]];
            tempsum2+=n2[temp.o[j]];
        }
       // cout << endl;
        if (tempsum1!=tempsum2)return false;
    }
    return true;
}
void print(){
    
    for (int i=0;i<n;i++){
        out[i][i]=n1[i];
    }
    for (int i=0;i<q.size();i++){
        connected temp=q[i];
        int passon;
        
        for (int j=0;j<temp.amount;j++){
            int h=j+1;
            int k=temp.o[j];
            if (ndelta[k]<0){
                passon=ndelta[k];
                passon*=-1;
                out[k][k]+=ndelta[k];
                ndelta[k]=0;
               // cout << j << endl;
                
                while (passon){
                    if (ndelta[k]>0){
                        if (passon>ndelta[k]){
                            passon-=ndelta[k];
                            out[j][k]=ndelta[k];
                            ndelta[k]=0;
                        }else {
                            ndelta[k]-=passon;
                            out[j][k]=passon;
                            passon=0;
                        }
                    
                    }
                    h+=1;
                    //cout << passon << "  " << k << endl;
                    
                    k=temp.o[(h)%temp.amount];
                    
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
    return ;
}
int main(){
	init();
    input();
    if (s1!=s2){
        cout << "NO";
        return 0;
    }
    int graps=0;
    int tempsum=0;
    for (int i=0;i<n;i++){
        connected a;
        a.amount=0;
        a=con(i,a);
        //cout << a.amount << endl;
        if (a.amount){
            graps++;
            q.push_back(a);
        }
    }
    if (prov()){
        cout << "YES" << endl;
        print();
        return 0;
    }
    cout << "NO";
	return 0;
}
