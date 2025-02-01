class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int maxi = *max_element(piles.begin(), piles.end());

    // The possible range of speeds is from 1 banana per hour to maxi bananas per hour.
    int low = 1, high = maxi;

    while (low <= high) {

        // Calculate the middle speed which is current speed
        int mid = (low + high) / 2;
        long long hours = 0;

        // Calculate the total hours required to finish all piles at speed 'mid'
        for (int &x : piles) {
            // The number of hours to eat pile x at speed 'mid' is ceil(x / mid)
            // Instead of using floating point division, we use (x + mid - 1) / mid
            hours += (x + mid - 1) / mid;
        }

        // If the total hours exceed 'h', we need to increase the speed
        if (hours > h) {
            low = mid + 1;  // Increase eating speed
        } else {
            high = mid - 1; // Try a lower speed
        }
    }

    // The smallest valid speed that allows Koko to finish eating within 'h' hours
    return low;
}
};