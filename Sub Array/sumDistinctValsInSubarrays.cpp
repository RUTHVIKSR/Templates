// --- Template Start ---

/**
 * @brief Calculates the sum of the number of distinct values over all subarrays.
 * * This function implements an efficient O(n) algorithm by summing the
 * contributions of each individual element rather than iterating through
 * every subarray. An element at index `i` contributes to the total for
 * every subarray where it is the *first* occurrence of its value.
 * * Time Complexity: O(n)
 * Space Complexity: O(k), where k is the number of distinct elements.
 * * @tparam T The type of the elements in the array. This type must be hashable
 * to be used as a key in std::unordered_map (all standard numeric
 * types and std::string are hashable by default).
 * @param arr The input data, provided as a const reference to a std::vector.
 * @return long long The total sum, returned as a 64-bit integer to prevent
 * potential overflow from large calculations.
 */
template <typename T>
long long calculate_distinct_subarray_sum(const std::vector<T>& arr) {
    long long total_sum = 0;
    const int n = arr.size();
    
    // This map stores the most recent index seen for each element's value.
    // Key: element value, Value: index
    std::unordered_map<T, int> last_pos;

    // We iterate through the array using 0-based indexing.
    for (int i = 0; i < n; ++i) {
        int prev_pos = -1; // Default for the first occurrence of a value
        
        // Find the last position where this element's value was seen.
        auto it = last_pos.find(arr[i]);
        if (it != last_pos.end()) {
            prev_pos = it->second;
        }

        // The contribution of arr[i] is based on the number of subarrays
        // where it acts as a new distinct element.
        // - Number of valid starts: Subarrays must start after the previous
        //   occurrence. This gives (i - prev_pos) choices.
        // - Number of valid ends: Subarrays must end at or after the current
        //   index. This gives (n - i) choices.
        long long contribution = (long long)(i - prev_pos) * (n - i);
        total_sum += contribution;

        // Update the map with the current index for this element's value.
        last_pos[arr[i]] = i;
    }

    return total_sum;
}

// --- Template End ---
