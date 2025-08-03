void bubbleSort(vector<int> &nums, int n){
    if(n == 1)
        return;
    int count = 0;
    for(int i=0;i<n-1;i++){
        if(nums[i] > nums[i+1]){
            swap(nums[i], nums[i+1]);
            count++;
        }
    }
    
    if(count == 0)
        return;
    bubbleSort(nums, n-1);
    return;
}
