/* 
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
 
Example 1:

Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: 2
Explanation: There are 2 triplets: 
1 + 2 = 3 and 3 +2 = 5 
*/

using namespace std;

int main() {
    //code
    long t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int start,end,ans=0;
        for(int i=n-1;i>=0;i--){
            start=0,end=i-1;
            while(start<end){
               if(a[start]+a[end]==a[i]){
                   ans++;
                   start++;
                   end--;
               }
               else if(a[start]+a[end]<a[i])
               start++;
               else end--;
            }
        }
        if(ans!=0)
        cout<<ans<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
