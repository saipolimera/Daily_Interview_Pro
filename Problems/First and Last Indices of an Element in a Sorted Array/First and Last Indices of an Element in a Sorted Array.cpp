    int binary_search(vector<int>& nums, int target, bool isLowerLimit)
    {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        
        while(left <= right)
        {
            int mid = left + (right-left) /2;
            if (nums[mid] == target)
            {
                result = mid;
                isLowerLimit? right = mid -1 : left = mid+1;
            }
            else if (nums[mid] > target) // move left
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1 ; // move right
            }
        }
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ret;
        
        if (nums.empty())
        {
            
            return {-1,-1};
        }
        
        return {binary_search(nums,target,true), binary_search(nums,target,false)};
	}