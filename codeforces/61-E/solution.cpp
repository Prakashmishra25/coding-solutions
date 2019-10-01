#include <bits/stdc++.h>
using namespace std;
 
 
//Enemy is Weak
#define int long long
const int N = 1e6 + 6;
 
int power[N], power2[N];
map<int, int> reducedValues;
 
int segmentTree[N*4] = {0};
int lazy[N*4] = {0};
 
void update(int start, int end, int idx, int qs, int qe) {
	
	if(lazy[idx] != 0) {
		segmentTree[idx] += (end - start + 1) * lazy[idx];
		
		if(start != end) {
			lazy[idx * 2 + 1] += lazy[idx];
			lazy[idx * 2 + 2] += lazy[idx];
		}
		
		lazy[idx] = 0;
	}
	
	if(qe < start or qs > end) return;
	
	if(qs <= start and qe >= end) {
		segmentTree[idx] += (end - start + 1) * 1;
	//	cout << "updated " <<idx << " " << endl;
		if(start != end) {
			lazy[idx * 2 + 1] += 1;
			lazy[idx * 2 + 2] += 1;
		}
		return;
	}
	
	int mid = (start + end) / 2;
	
	update(start, mid, idx * 2 + 1, qs, qe);
	update(mid + 1, end, idx * 2 + 2, qs, qe);
	
	segmentTree[idx] = segmentTree[idx * 2 + 1] + segmentTree[idx * 2 + 2];
}
 
int query(int start, int end, int idx, int actual_idx) {
	if(lazy[idx] != 0) {
		segmentTree[idx] += (end - start + 1) * lazy[idx];
		
		if(start != end) {
			lazy[idx * 2 + 1] += lazy[idx];
			lazy[idx * 2 + 2] += lazy[idx];
		}
		
		lazy[idx] = 0;
	}
	
	if(start == end) {
		return segmentTree[idx];
	}
	
	int mid = (start + end)/ 2;
	if(actual_idx <= mid) return query(start, mid, idx * 2 + 1, actual_idx);
	else return query(mid + 1, end, idx * 2 + 2, actual_idx);
	
	
}
 
void updateSingle(int start, int end, int idx, int actual_idx) {
	if(start == end) {
		segmentTree[idx]++;
		return ;
	}
	
	int mid = (start + end) / 2;
	if(actual_idx <= mid) {
		updateSingle(start, mid, idx * 2 + 1, actual_idx);
	} else {
		updateSingle(mid + 1, end, idx * 2 +2 , actual_idx);
	}
	
	segmentTree[idx] = segmentTree[idx * 2 + 1] + segmentTree[idx * 2 + 2];
}
 
int queryRange(int start, int end, int idx, int qs, int qe) {
	if(qs > end or qe < start) return 0;
	if(qs <= start and qe >= end) {
		return segmentTree[idx];
	}
	int mid = (start + end) / 2;
	int ans1 = queryRange(start, mid, idx * 2 + 1, qs, qe);
	int ans2 = queryRange(mid + 1, end, idx * 2 + 2, qs, qe);
	return ans1 + ans2;
}
 
int grt[N]={0};
int lwr[N];
 
 
signed main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> power[i];
		power2[i] = power[i];
	}
	sort(power2, power2 + n);
	
	for(int i = 0; i < n; i++) {
		reducedValues[power2[i]] = i;
	}
	
	for(int i = 0; i < n; i++) {
		power[i] = reducedValues[power[i]];
	//	cout << "value i is " << power [i] << endl;
		update(0, n-1, 0, 0, power[i]);
		grt[i] = query(0, n-1, 0, power[i]) - 1;
	//	cout << "lol" << endl;
	//	cout << grt[i] << endl;
	}
	
	memset(segmentTree, 0, sizeof(segmentTree));
	memset(lazy, 0, sizeof(lazy));
	
	unsigned long long sumi = 0;
	
	for(int i = n-1; i >= 0; i--) {
		updateSingle(0, n-1, 0, power[i]);
		lwr[i] = queryRange(0, n-1,0, 0, power[i] - 1);
	//	cout << "second lol" << endl;
	//	cout << lwr[i] << endl;
		sumi += lwr[i] * grt[i] ;
	}
	
	cout << sumi << endl;
 
	
	cout << endl;
	
	return 0;
}
