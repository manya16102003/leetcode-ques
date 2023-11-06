class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        int sign=1;
        if(dividend<0 || divisor<0)sign=-1;
        if(dividend<0 && divisor<0)sign=1;
        dividend=abs(dividend);
        divisor=abs(divisor);
        long long s=0;
        long long end=abs(dividend);
        long long mid=(s+end)/2;
        long long ans=0;
        while(s<=end)
        {
            if(abs(mid*divisor)==abs(dividend)) 
            {
                ans= mid;
                break;
            }
           if(abs(mid*divisor)>abs(dividend))
            {
                end=mid-1;
            }
            else
            {
               ans=mid;
               s=mid+1;
            }
            mid=(s+end)/2;
        }
         if(sign<0)return -ans;
        else return ans; 
    }
};