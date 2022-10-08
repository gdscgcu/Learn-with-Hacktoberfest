#include <iostream>
using namespace std;
void getPairsCount(int N,int K, int arr[]){
	int count=0;
	for(int i=0; i<N;i++){
		for(int j=i+1;j<N;j++){
			if(arr[i]+arr[j]==K){
				count=count+1;
				
			}
			
		}
		
	}
	cout<<count;
	
}
int main(){
	int N=4,K=2,arr[]={1,1,1,1};
	      getPairsCount(N,K,arr);
}
