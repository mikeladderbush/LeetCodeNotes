#include <vector>
#include <unordered_map>

class Solution {
public:
    // Here we are given an address of a vector and a target int.
    // We need to use two numbers from the vector to create the target.
    vector<int> twoSum(vector<int>& nums, int target) {

        // an unordered map is a form of hashmap that loads items in no specific order.
        // map<complement, vector position>
        unordered_map<int, int> numMap;

        // initialized integer that is set to the size of the vector.
        int n = nums.size();

        // loop through the vector and store a complement variable that is the target - the current element.
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];

            // if the complement is found in the map, because .count for unordered maps doesnt anything but 0 or 1
            if (numMap.count(complement)) {
                
                // returns a vector of the bucket containing the complement and the current position of the vector. 
                return {numMap[complement], i};
            }
            
            // if the complement is not present the current element of the vector is added to the numMap and its
            // key is assigned to the complement.
            // For example, if target = 9, nums[i] = 2, and i = 0 then the complement 7, will be <2,0> in the numMap.
            // So when we come back to numMap.count and search for the complement we already have all possible differences
            // meaning that if target = 9, nums[i] = 7, and i = 1 then the complement will be 2 and if we search that in the map
            // we will get our previously added <2,0> element. The position of that element along with the current position will be
            // returned : {0,1}
            // Regardless of the position we are at in the vector we assign the complement as the key and the vector position as the value.
            // That way further in the vector we can fetch the current positions complement position if it is there by passing the complement to the map.
            numMap[nums[i]] = i;
        }

        return {};
    }
};
