#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
int reach(vector <vector<int> > C, vector <vector<int> > P, int i, int j, int f, int n, int m){
    if(i==n-1 && j==m-1){
        return 0;
    }else if(i==n-1){
        int cost1, cost2;
        if(f==1){
            cost1 = C[i][j+1]+reach(C, P, i, j+1, 1, n, m);
        }else{
            cost2 = C[i][j+1]+ P[i][j]+reach(C, P, i, j+1, 1, n, m);
        }
        return min(cost1, cost2);
        
    }else if(j==n-1){
        
        int cost1, cost2;
        if(f==0){
            cost1 = C[i+1][j]+ P[i+1][j]+reach(C,P, i+1, j, 1, n, m);
        }else{
            cost2 = C[i+1][j]+reach(C, P, i+1, j, 0, n, m);
        }
        return min(cost1, cost2);
    }else{
        int cost1, cost2;
        if(f==1){
            cost1 = C[i][j+1]+min( reach(C, P, i, j+1, 1, n, m), P[i][j+1]+reach(C,P, i, j+1, 0, n, m) );
        }else{
            cost2 = C[i+1][j]+min( P[i+1][j]+reach(C,P, i+1, j, 1, n, m), reach(C,P, i+1, j, 0, n, m) );
        }
        return min(cost1, cost2);
    }
}
//1 == right
//0== bottom
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
 
	int t;
	cin>>t;
	while(t--){
	    int n, m;
        cin>>n>>m;
         vector <vector<int> > C;
         vector <vector<int> > P;
        
        
        for(int i=0;i<n;i++){
            vector <int> temp;
            for(int j=0;j<m;j++){
                int temp1;
                cin>>temp1;
                temp.push_back(temp1);
            }
            C.push_back(temp);
        }
        for(int i=0;i<n;i++){
            vector <int> temp;
            for(int j=0;j<m;j++){
                int temp1;
                cin>>temp1;
                temp.push_back(temp1);
            }
            P.push_back(temp);
            
        }
        int face =1, i=0, j=0;
        int cost =P[0][0]+C[0][0]+min( reach(C, P, i, j, 1, n, m), reach(C, P, i, j, 0, n, m) );
        cout<<cost<<endl;
	}
    return 0;
} 
