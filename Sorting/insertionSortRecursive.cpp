void insertionSort(vector<int> &nums, int n){
    if(n <= 1)
        return;
        
    insertionSort(nums, n-1);
    int last = nums[n-1];
    int j = n-2;
    while(j >= 0 && nums[j] > last){
        nums[j+1] = nums[j];
        j--;
    }
    nums[j+1] = last;
}
