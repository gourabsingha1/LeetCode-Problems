#define ll long long

class Solution {
public:
    int M = 1e9 + 7;

    int helper(int usedSongs, int curLocation, int& n, int& goal, int& k, vector<vector<int>>& dp) {
        if(curLocation == goal) { // reached goal
            return usedSongs == n; // check if all songs are used
        }
        if(dp[usedSongs][curLocation] != -1) {
            return dp[usedSongs][curLocation];
        }
        
        ll newSongs = 1LL * (n - usedSongs) * helper(usedSongs + 1, curLocation + 1, n, goal, k, dp) % M;
        ll oldSongs = 1LL * max(0, usedSongs - k) * helper(usedSongs, curLocation + 1, n, goal, k, dp);
        ll total = (newSongs + oldSongs) % M; // place newSong or oldSong at curLocation
        return dp[usedSongs][curLocation] = total;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(goal + 1, vector<int> (goal + 1, -1));
        return helper(0, 0, n, goal, k, dp);
    }
};