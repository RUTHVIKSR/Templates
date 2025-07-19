#include <vector>
#include <algorithm> // for std::swap
#include <stdexcept> // for std::runtime_error

/**
 * @brief Partitions a subarray using the Lomuto partition scheme.
 * @param nums The vector to partition.
 * @param left The starting index of the subarray.
 * @param right The ending index of the subarray.
 * @return The final index of the pivot.
 */
int partition(std::vector<int>& nums, int left, int right) {
    // A simple strategy is to pick the last element as the pivot.
    // For better average performance and to avoid worst-case O(n^2),
    // consider a random pivot:
    // int pivot_idx = left + rand() % (right - left + 1);
    // std::swap(nums[pivot_idx], nums[right]);
    
    int pivotValue = nums[right];
    int storeIndex = left;

    for (int i = left; i < right; ++i) {
        if (nums[i] < pivotValue) {
            std::swap(nums[storeIndex], nums[i]);
            storeIndex++;
        }
    }
    std::swap(nums[storeIndex], nums[right]); // Move pivot to its final place
    return storeIndex;
}

/**
 * @brief Finds the k-th smallest element in a vector using the Quickselect algorithm.
 * Note: This function will partially sort the input vector `nums`.
 *
 * @param nums The vector of integers. The vector is passed by reference and will be modified.
 * @param k The desired rank (0-based index). For example, k=0 for the smallest element.
 * @return The k-th smallest element.
 *
 * @throws std::runtime_error if k is out of bounds.
 */
int quickSelect(std::vector<int>& nums, int k) {
    int left = 0;
    int right = nums.size() - 1;

    if (k < 0 || k > right) {
        throw std::runtime_error("k is out of the bounds of the vector.");
    }

    while (left <= right) {
        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == k) {
            return nums[k];
        } else if (pivotIndex < k) {
            left = pivotIndex + 1;
        } else {
            right = pivotIndex - 1;
        }
    }
    
    // Should not be reached with valid inputs
    return -1;
}

// To find the K-th LARGEST element, you would call it like this:
// int kthLargest = quickSelect(my_nums, my_nums.size() - k_largest);
