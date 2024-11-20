class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int min=-1, max=-1;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {   if(mid==0)
            {
                min=mid;
                goto run;
            }
                if (nums[mid + 1] != target)
                {
                    run:
                    max = mid;
                    for (int i = mid; i >= 0; i--)
                    {
                        if (nums[i-1] != target)
                        {
                            return {i, max};
                            break;
                        }
                    }
                }
            else if (nums[mid - 1] != target)
                {
                    min = mid;
                    for (int i = mid; i < nums.size(); i++)
                    {
                        if (nums[i+1] != target)
                        {
                            return {min, i};
                            break;
                        }
                    }
                }
                else low=mid+1;
            }
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {min, max};
    }
};