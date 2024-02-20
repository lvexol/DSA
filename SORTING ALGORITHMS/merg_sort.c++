
void merg(int arr[],int lb,int up,int mid){
	int i=lb;
	int j=mid+1;
	int k=0;
	int b[up+1];
	while(i<=mid && j<=up){
		if(arr[i]<=arr[j]){
            b[k]=arr[i];
			i++;
        }
        else{
            b[k]=arr[j];
			j++;
        }
		k++;
	}
	for(int x=0;x<=up;x++){
		arr[x]=b[x];
	}
}
void mergsort(int arr[],int lb,int up){
	if(lb<up){
		int mid=(lb+up)/2;
		
		mergsort(arr,lb,mid);
		mergsort(arr,mid+1,up);

		merg(arr,lb,up,mid);
	}
}