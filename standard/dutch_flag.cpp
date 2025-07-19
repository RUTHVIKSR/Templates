#include <iostream>
#include <vector>
#include <utility> // For std::swap

/**
 * @brief Sorts an array of three distinct values in-place using the
 * Dutch National Flag algorithm.
 * @param nums The vector to be sorted.
 * @param pivot_val The middle value to partition around.
 */
void dutchNationalFlagSort(std::vector<int>& nums, int pivot_val) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    // Process the array until the mid and high pointers cross
    while (mid <= high) {
        if (nums[mid] < pivot_val) {
            // Case 1: The element is smaller than the pivot
            // Swap with the low pointer and advance both low and mid
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] > pivot_val) {
            // Case 2: The element is larger than the pivot
            // Swap with the high pointer and bring the high boundary in
            std::swap(nums[mid], nums[high]);
            high--;
        } else { // nums[mid] == pivot_val
            // Case 3: The element is equal to the pivot
            // It's in the correct partition, so just move to the next element
            mid++;
        }
    }
}
