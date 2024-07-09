class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n =customers.size();
        double totaltimewait=0;
        int currenttime=0;
        for(auto &vect:customers)
        {
            int arrivaltime=vect[0];
            int cooktime=vect[1];
            if(currenttime<arrivaltime)
            {
                currenttime=arrivaltime;
            }
            int waittime=currenttime+cooktime-arrivaltime;
            totaltimewait+=waittime;
            currenttime+=cooktime;
        }
        return totaltimewait/n;
    }
};