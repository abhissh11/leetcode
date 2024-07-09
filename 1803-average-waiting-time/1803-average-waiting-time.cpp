class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        //customers[i][0] ==> arrival time && customers[0][1] ==> preparation time
     //sum the total waiting time  
        double totalWait = customers[0][1];       
    //current time is = (arrival time + preparing time) for the current customer
        double currTime = customers[0][0] + customers[0][1];

        for(int i=1; i<customers.size(); i++){
        //if current time is greater than the arrival of next customer, means customer has to wait
            if((currTime - customers[i][0]) > 0){
                //sum up the wait time for the ith customer in totalWait
                totalWait += currTime - customers[i][0] + customers[i][1];
                // update the currtime with summing up the preparing time for the ith cust.
                currTime = currTime + customers[i][1];
            }
            else{
                //else if the current time is less or = to the arrival time the prepartion will start immediately
                //so add up the preparation time to totalWait
                totalWait += customers[i][1];
                //update the currTime with summing up the prep.Time
                currTime = customers[i][0] + customers[i][1];
            }
        }
        double avgWait = (totalWait) / customers.size();
        return avgWait;
    }
};