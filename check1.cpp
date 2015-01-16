#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b)
    {
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
bool check(vector<int> arr)
    {
    for(int i=0;i<arr.size();i++)
        {
        for(int j=1;j<arr.size();j++)
            {
            if(gcd(arr[i],arr[j])==1)
                return true;
                
            
        }
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    int n;
    cin>>n;
    int inp;
    while(t--){
        
        vector<int> arr;
        while(n--)
            {
            cin>>inp;
            arr.push_back(inp);
        }
        if(check(arr))
            {
            cout<<"YES"<<endl;
            
        }
        else
            {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}