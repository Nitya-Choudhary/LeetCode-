void reverse(int arr,int start, int end){
    hwile(start<=end){
        swap(arr[start,arr[end]]);
        start++;
        end--;

    }
}
void rotate(int arr, int k,int n){
    k= k%n;
    reverse(arr,0,n);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    
}
