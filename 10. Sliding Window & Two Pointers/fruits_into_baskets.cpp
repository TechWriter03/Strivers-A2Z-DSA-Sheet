// Input:
// fruits = [ 0, 1, 2, 2, 2, 2 ]
// Output: 
// 5

int totalFruits(int n,vector<int>& fruits) 
{
    int left=0,right=0,maxFruits=0;
    unordered_map<int,int>mp;
    while(right<n)
    {
        mp[fruits[right]]++;
        if(mp.size()>2)
        {
            mp[fruits[left]]--;
            if(mp[fruits[left]]==0)
                mp.erase(fruits[left]);
            left++;
        }
        maxFruits=max(maxFruits,right-left+1);
        right++;
    }
    return maxFruits;
}
