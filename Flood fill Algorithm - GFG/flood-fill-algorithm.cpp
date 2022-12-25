//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int i, int j, int n, int m, int sourceColor, int color, vector<vector<int>>& image){
        if(image[i][j] == sourceColor){
            image[i][j] = color;
        }
        else{
            return;
        }

        if(i > 0){
            dfs(i-1, j, n, m, sourceColor, color, image);
        }
        if(j > 0){
            dfs(i, j-1, n, m, sourceColor, color, image);
        }
        if(i < n-1){
            dfs(i+1, j, n, m, sourceColor, color, image);
        }
        if(j < m-1){
            dfs(i, j+1, n, m, sourceColor, color, image);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size(), sourceColor = image[sr][sc];
        if(sourceColor != color){
            dfs(sr, sc, n, m, sourceColor, color, image);
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends