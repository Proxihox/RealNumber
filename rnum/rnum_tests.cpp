
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include "../rnum/rnum.cpp"
#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define vl vector<ll> 
#define vvl vector<vl> 
#define vpll vector<pll>
#define vvpll vector<vpll>
#define pb push_back
#define loop(n,i) for(ll i = 0; i < n; i++)
#define fa(i,v) for(auto &i:v)
#define HALF frac(1,2)
using namespace std;

void test_assign(){
    term rt2 = pow(2,HALF);
    rnum a(rt2);
    rnum b(5);
    a = b;
    if(a != b) cout << "Assign failed\n";
    else cout << "Assign passed\n";
}

void test_cout(){
    term rt2 = pow(frac(2),HALF);
    rnum a(rt2);
    cout << a << "\n";
}

void test_add(){
    
    rnum a(2);
    rnum b(8);
    frac d(1,2);
    a = pow(a,d); // root2
    b = pow(b,d);
    //cout << "b" << b << "\n";
    b = b + 2;
    a = a + 1;
    a = a*2;
    if(a != b) cout << "Add failed\n";
    else cout << "Add passed\n";
    
}


void (*tests[])() = {
    test_assign,
    test_cout,
    test_add,
};

int main(){
    fa(x,tests){
        x();
    }
}