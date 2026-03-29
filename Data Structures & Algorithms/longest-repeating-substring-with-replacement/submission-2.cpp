class Solution {
public:
    int characterReplacement(string s, int k) {
    vector<int> count(26, 0);
    int max_f = 0; // Highest frequency of a single character in the current window
    int left = 0;
    int max_length = 0;

    for (int right = 0; right < s.size(); right++) {
        // Update frequency and track the peak frequency
        max_f = max(max_f, ++count[s[right] - 'A']);

        // Window Condition: (Total window size - most frequent char count) > k
        // If this is true, we have too many "other" characters to replace.
        while ((right - left + 1) - max_f > k) {
            count[s[left] - 'A']--;
            left++;
            // Note: We don't actually need to update max_f here!
        }

        max_length = max(max_length, right - left + 1);
    }
    return max_length;
}
};
