#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // For std::max

/**
 * @brief A generic template for solving subarray problems using prefix sums and hashing.
 * * @tparam T The data type of the elements in the input array.
 * @tparam U The data type for the accumulator (e.g., long long for sums to avoid overflow).
 * @param data The input vector.
 * @param target The target value for the accumulator condition.
 * @return The length of the longest subarray satisfying the condition.
 */
template <typename T, typename U>
int solveWithPrefixHash(const std::vector<T>& data, U target) {
    // 1. INITIALIZATION
    // The map stores the first time an accumulator value was seen.
    // Key: Accumulator Value, Value: Index
    std::unordered_map<U, int> prefix_map;
    
    U accumulator = 0;
    int max_length = 0;

    // A crucial step for problems where the valid subarray starts at index 0.
    // This seeds the map to handle the case where `accumulator == target`
    // inside the loop. The accumulator value for an empty prefix (before index 0) is 0.
    prefix_map[0] = -1;

    // 2. ITERATION
    for (int i = 0; i < data.size(); ++i) {
        // 3. UPDATE ACCUMULATOR
        // This is the primary line to change based on the problem.
        // For sum problems: accumulator += data[i];
        // For 0/1 balance: accumulator += (data[i] == 1 ? 1 : -1);
        accumulator += data[i]; // <-- MODIFY THIS LOGIC

        // 4. CHECK FOR SUBARRAY
        // We are looking for a past accumulator state such that:
        // current_accumulator - past_accumulator = target
        // Therefore, past_accumulator = current_accumulator - target
        U required_val = accumulator - target;

        if (prefix_map.count(required_val)) {
            // A valid subarray is found ending at the current index 'i'.
            // The start of this subarray is the index after where we first saw `required_val`.
            int current_length = i - prefix_map[required_val];
            max_length = std::max(max_length, current_length);
        }

        // 5. UPDATE MAP
        // Store the accumulator value and index *only if it's the first time* we've seen it.
        // This is essential for "longest subarray" problems.
        if (prefix_map.find(accumulator) == prefix_map.end()) {
            prefix_map[accumulator] = i;
        }
    }

    return max_length;
}
