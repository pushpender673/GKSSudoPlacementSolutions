
#include<bits/stdc++.h>

using namespace std;
#define nl printf("\n")

int painterPartitionB(int a[], int n,int k){
    
    int hi = accumulate(a,a+n,0);
    int lo = *max_element(a,a+n);
   // printf("low : %d hi:%d\n",lo,hi);
    
    while(lo<hi){
        int x = lo+(hi-lo)/2;
        
        int required_worker=1, curr_workload=0;
        for(int i =0;i<n;i++){
            if((curr_workload+a[i]) <=x)
            {
                curr_workload+=a[i];
            } else {
                curr_workload = a[i];
                ++required_worker;
            }
        }
        if(required_worker<=k){
            hi = x;
        } else {
            lo = x+1;
        }
    }
    
    return lo;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	  int k,n;
	  cin>>k>>n;
	  int a[n];
	  for(int i =0;i<n;i++)
	  {
	      cin>>a[i];
	  }
	  printf("%d\n", painterPartitionB(a,n,k));
	}
	
	return 0;
}
