//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
   void dfs(int row, int col, vector<vector<int>>& image, int newColor, int oldColor) {
    int n = image.size();
    int m = image[0].size();
    image[row][col] = newColor;
    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++) {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == oldColor) {
            dfs(nrow, ncol, image, newColor, oldColor);
        }
    }
}
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
     int oldColor = image[sr][sc];
    if (oldColor != color) {
        dfs(sr, sc, image, color, oldColor);
    }
    return image;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends