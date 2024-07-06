class Solution {
public:
    int passThePillow(int n, int time) {
        //APPROACH 1

        // int current_index=1;
        // int direction=1 ;//indicated pillow is movinf from L to R
        // while(time)
        // {
        //     if(current_index+direction>=1 && current_index+direction<=n)
        //     {
        //         current_index+=direction;
        //         time--;
        //     }
        //     else
        //     {
        //         direction*=-1; // reverse the direction oce u reach the edge i.e either at first or last position
        //     }
        // }
        // return current_index;

        //APPROACH 2

        int fullround=time/(n-1);
        int remaining_time=time%(n-1);
        if(fullround%2==0)
        {
            return remaining_time+1;
        }
        else
        {
            return n-remaining_time;
        }
        return -1;
    }
};