class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int total=0;
        for(int i=0;i<flowerbed.size()&&total<n;i++)
        {
            if(flowerbed[i]==0)
            {
                bool prev=(i==0)?0:flowerbed[i-1];
                bool next=(i==flowerbed.size()-1)?0:flowerbed[i+1];
                if(prev==0&&next==0)
                {
                    flowerbed[i]=1;
                    total++;
                }
            }
        }
        return total==n;
    }
};