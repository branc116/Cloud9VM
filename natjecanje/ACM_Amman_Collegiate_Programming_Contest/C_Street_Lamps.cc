#include <iostream>
#include <string>

using namespace std;
int t,n;

int main(){
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n;
        string s=".";
        cin >> s;
        s=","+s;
        s=s+",";
        int sum=0;
        if (i){cout << endl;}
        for (int j=1;j<n;j++){
            
            
            
            if (s[j]!='*'){
                if (s[j-1]!='*'&&s[j+1]!='*'){
                    if (s[j-1]!=','&&s[j+1]!=','){
                        s[j]='*';
                        sum++;
                    }
                }else s[j]=',';
            }
        }
        
        for (int j=1;j<=n;j++){
        if (s[j]!='*'&&s[j-1]!='*'&&s[j+1]!='*' ){
                s[j]='*';
                sum++;
            }
        }
        
        cout  << sum ;
    }
    return 0;
}