#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int steadyGene(string gene) {
    int n = gene.length();
    int target = n / 4; // Each nucleotide should appear 'n / 4' times.

    // Step 1: Count occurrences of each nucleotide.
    unordered_map<char, int> count;
    for (char c : gene) {
        count[c]++;
    }

    // Step 2: Determine excess nucleotides.
    unordered_map<char, int> excess;
    for (auto& [key, value] : count) {
        if (value > target) {
            excess[key] = value - target;
        }
    }

    // If no nucleotide exceeds the target, the gene is already steady.
    if (excess.empty()) {
        return 0;
    }

    // Step 3: Sliding window to find the minimum substring length.
    int minLength = n;
    unordered_map<char, int> window;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        char current = gene[right];
        window[current]++;

        // Check if the current window satisfies the condition.
        bool valid = true;
        for (auto& [key, value] : excess) {
            if (window[key] < value) {
                valid = false;
                break;
            }
        }

        // Shrink the window from the left if it's valid.
        while (valid && left <= right) {
            minLength = min(minLength, right - left + 1);
            char toRemove = gene[left];
            window[toRemove]--;
            left++;

            // Recheck validity.
            for (auto& [key, value] : excess) {
                if (window[key] < value) {
                    valid = false;
                    break;
                }
            }
        }
    }

    return minLength;
}

int main() {
    int n;
    string gene;

    gene = "GAAATAAA";
    cout << steadyGene(gene) << endl;   // 5
    /*
    Explanation:
    - Excess nucleotides: {'A': 3}.
    - Minimum substring to replace is AAATA. After replacement, the gene becomes GAAACTAA, which is steady.
    */

    gene = "TGATGCCGTCCCCTCAACTTGAGTGCTCCTAATGCGTTGC";
    cout << steadyGene(gene) << endl;   // 5

    return 0;
}
/*
A gene is represented as a string of length n (where n is divisible by ),
composed of the letters A, C, T, and G.
ACTGAAAG A:4, C:1, T:1, G:2,
     AA   -> CT = ACTGACTG  A:2, C:2, T:2, G:2
    AA    -> TC = ACTGTCAG  A:2, C:2, T:2, G:2
*/

/*
Explanation
1. Count Excess Nucleotides:
- Use a count map to determine the frequency of each nucleotide in the gene.
- If a nucleotide occurs more than n / 4 times, calculate the excess amount and store it in the excess map.
2. Sliding Window Technique:
- Use two pointers (left and right) to define a window within the gene.
- Expand the window by moving right and include characters in the window map.
- Check if the window contains enough of the excess nucleotides to replace them and make the gene steady.
- If valid, move left to shrink the window and potentially minimize its size.
3. Optimization:
- The sliding window ensures that we process the string in O(n) time for each pass, resulting in an efficient solution.
Complexity
- Time Complexity: O(n) due to the sliding window.
Space Complexity: O(1), since the maximum size of the maps is limited to the four nucleotides.
*/
