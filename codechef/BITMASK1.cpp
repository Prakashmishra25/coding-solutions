#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(null);
	int t, temp, i, j, n, m, sum, low;
	cin>>t;
	while(t--){
	   sum=0;
	   cin>>n>>m;
	   while(n--){
	       low=9999;
	       for(i=0; i<m; i++){
	            cin>>temp;
	            if(temp<low) low=temp;
	       }
	       sum+=low;
	   }
	   cout<< sum<<endl;
	}
	return 0;
}

