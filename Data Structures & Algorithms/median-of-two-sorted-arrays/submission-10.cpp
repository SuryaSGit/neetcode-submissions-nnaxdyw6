//We know the median must be greater than half of the total elements.
// We can partition elements from the left of both the arrays (x from arr1, half-x from arr2)
// If the next element after the partition in the arrays is less than any element
//Inside the partition, it doesnt work. We can check in O(1) since it is sorted.
//Once we find a partition that works, the next element thats not in the partition
//is the median (or average if total size is even).
//Have to check for edge cases where we take 0 or all items from one array.
//Time Complexity: O(log(min(M,N)))
//Space Complexity: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            swap(nums1,nums2);
        }
        if(nums1.empty()){
            if(nums2.size()%2==1){
                return nums2[nums2.size()/2];
            }
            else{
                return (nums2[nums2.size()/2] + nums2[-1 + nums2.size()/2])/2.0;
            }
        }
        int low = 0; 
        int high = nums1.size();
        int mid = (low + high) / 2;
        int half = (nums1.size() + nums2.size()) / 2;
        while(low <= high){
            if(mid == 0){
                break;
            }
            if(mid == nums1.size()){
                break;
            }
            if(nums1[mid-1] <= nums2[half-mid] && nums2[-1+half-mid] <= nums1[mid]){
                break;
            }
            if(nums1[mid] < nums2[-1 + half-mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            mid = (low + high) / 2;
        }
        if((nums1.size() + nums2.size())%2==1){
            if(mid == nums1.size()){
                cout << mid << endl;
                return min(nums1[mid-1],nums2[0]);
            }
            if(mid == 0){
                return min(nums1[0],nums2[nums2.size()-1]);
            }
            return min(nums1[mid], nums2[half - mid]);
        }
        if(mid == nums1.size()){
            return (nums1[mid-1]+nums2[0])/2.0;
        }
        if(mid == 0){
            return (nums2[nums2.size()-1]+nums1[0])/2.0;
        }
        int temp1 = min(nums1[mid],nums2[half-mid]);
        int temp2 = max(nums1[mid-1],nums2[-1+half-mid]);
        cout << temp2 << endl;
        cout << temp1 << endl;
        return (temp1 + temp2)/2.0;
    }
};
