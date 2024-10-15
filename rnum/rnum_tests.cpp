
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
    rnum a(2);
    rnum b(5);
    a = b;
    if(a != b) cout << "Assign failed\n";
    else cout << "Assign Passed\n";
}

void test_add(){
    
    rnum a(2);
    rnum b(2);
    rnum c(2);
    frac d(1,2);
    c = pow(a,HALF);
    b = b + c;
    b = b*c;
    a = a*c;
    a = a + 2;
    if(a == b) cout << "Add passed\n";
    else cout << "Add Failed\n";
}


// void test_mul(){
//     rnum a(72);
//     rnum b(75);
//     rnum c(40);
//     frac d(1,3);
//     rnum r1 = pow(a,d);
//     rnum r2 = pow(b,d);
//     rnum r3 = pow(c,d);
//     cout << "Start" << "\n";
//     r1.out();
//     r2.out();
//     r3.out();
//     rnum res = r1*r2*r3;
    
//     rnum e(60);
//     if(e == res) cout << "Mul passed";
//     else cout << "Mul failed";
// }

void test_mul(){
    rnum a(2);
    rnum b(25);
    rnum c(9);
    frac d(1,2);
    rnum r1 = pow(a,d);
    r1.out();
    rnum r2 = pow(b,d);
    rnum r3 = pow(c,d);
    cout << "Start" << "\n";
    r1.out();
    r2.out();
    r3.out();
    rnum res = r1*r2*r3;
    
    rnum e(30);
    if(e == res) cout << "Mul passed";
    else cout << "Mul failed";
}

void test_pow(){
    rnum a(2);
    rnum b(3);
    rnum c(6);
    a = pow(a,HALF);
    b = pow(b,HALF);
    c = pow(c,HALF);
    if(c == a*b) cout << "Pow passed\n";
    else cout << "Pow Failed\n";
}

void test_pow2(){
    rnum a(4);
    a = pow(a,HALF);
    a.out();
    if(a == 2) cout << "Pow2 passed\n";
    else cout << "Pow2 Failed\n";
}


void (*tests[])() = {
    //test_pow,
    test_pow2,
    // test_assign,
    // test_add,
    //test_mul,
    //test_sub
};

int main(){
    bool res = true;
    fa(x,tests){
        x();
    }
    if(res) cout << "Passed";
}