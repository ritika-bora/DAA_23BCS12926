class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        unordered_set<int> used(passengers.begin(), passengers.end());

        int j = 0; 
        int lastBoarded = -1;
        
        for (int b : buses) {
            int count = 0;
            while (j < passengers.size() && passengers[j] <= b && count < capacity) {
                lastBoarded = passengers[j];
                j++;
                count++;
            }
            if (b == buses.back()) {
                if (count < capacity) {
                    int ans = b;
                    while (used.count(ans)) ans--;
                    return ans;
                } else {
                    int ans = lastBoarded - 1;
                    while (used.count(ans)) ans--;
                    return ans;
                }
            }
        }
        return -1;
    }
};
