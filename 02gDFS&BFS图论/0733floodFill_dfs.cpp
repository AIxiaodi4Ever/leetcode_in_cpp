/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, 
"flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of 
the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color 
as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

Note:
The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flood-fill
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int m;
    int n;
    int currColor;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        currColor = image[sr][sc];
        if (currColor == newColor)
            return image;
        m = image.size();
        n = image[0].size();
        myDfs(image, sr, sc, newColor);
        return image;
    }

    void myDfs(vector<vector<int>>& image, int x, int y, int newColor)
    {
        image[x][y] = newColor;
        for (int i = 0; i < 4; ++i)
        {
            int mx = x + dx[i], my = y + dy[i];
            // mx的条件错用成n
            if (mx >= 0 && mx < m && my >= 0 && my < n && image[mx][my] == currColor)
                myDfs(image, mx, my, newColor);
        }
    }
};