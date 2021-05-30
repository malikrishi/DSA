#include<iostream>
using namespace std;


    
int climbStairs(int n) {
    int stepOne = 1;
    int stepTwo = 2;
    int res = 0;
    if(1 == n) return 1;
    if(2 == n) return 2;
    for (int i = 3 ; i <= n ; i++) {
        res = stepOne + stepTwo;
        stepOne = stepTwo;
        stepTwo = res;
    }
    return res;
}

int main() {
   cout << climbStairs(2) << endl;
   cout << climbStairs(3) << endl;
   cout << climbStairs(4) << endl;
   cout << climbStairs(5) << endl;
   cout << climbStairs(6) << endl;
}
