#include <iostream>
#include <vector>
#include <algorithm> // For std::max
#include <limits>    // For std::numeric_limits

/**
 * @brief Finds the maximum sum of a contiguous subarray using Kadane's Algorithm.
 * @tparam T The numeric data type of the array elements (e.g., int, long long).
 * @param nums The input vector of numbers.
 * @return The maximum possible sum of a contiguous subarray.
 */
template <typename T>
T kadanesAlgorithm(const std::vector<T>& nums) {
    // Handle the edge case of an empty array.
    if (nums.empty()) {
        return 0; // Or throw an exception, depending on requirements.
    }

    // Initialize both max values with the first element of the array.
    T currentMax = nums[0];
    T globalMax = nums[0];

    // Start the loop from the second element.
    for (size_t i = 1; i < nums.size(); ++i) {
        // For the current position, decide what's greater:
        // 1. Starting a new subarray with the current element (nums[i]).
        // 2. Extending the previous subarray by adding the current element (currentMax + nums[i]).
        currentMax = std::max(nums[i], currentMax + nums[i]);

        // Update the overall global maximum if the current subarray's max is greater.
        globalMax = std::max(globalMax, currentMax);
    }

    return globalMax;
}
