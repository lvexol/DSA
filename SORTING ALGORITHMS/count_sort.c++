#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 

void count_sort(int arr[], int n) 
{ 
	int k=arr[0];
	for(int i=0;i<n;i++){
		if(k<arr[i])
			k=arr[i];
	}

	int count[k + 1] = { 0 }; 

	for (int i = 0; i < n; i++) { 
		count[arr[i]]++; 
	} 
	for (int i = 1; i <= k; i++) { 
		count[i] = count[i] + count[i - 1]; 
	} 
	int ans[n]; 
	for (int i = 0; i <n; i++) { 
		ans[--count[arr[i]]] = arr[i]; 
	} 
	for (int i = 0; i < n; i++) { 
		arr[i] = ans[i]; 
	} 
} 
int main() 
{ 
	int arr[] = { 1,5,3,7,3,7,7,8,9,7,8,3,9,0 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	count_sort(arr, n); 
	cout << "Array after performing count sort : " << endl; 
	for (int i = 0; i < n; i++) { 
		cout << arr[i] << " "; 
	} 
	return 0; 
}
