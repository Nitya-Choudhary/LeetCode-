#include <vector>
using namespace std;
class Solution{
    public:
    vector<vector<int>>floodfill(vector<vector<int>>&image, int sr, int sc, int newcolor){
        int oldcolor= image[sr][sc];
        if(oldcolor==newcolor) return image;

        dfs();
        return image;
    }

    void dfs(vector<vector<int>>&image, int r, int c,int oldcolor, int newcolor){
        int m= image.size();
        int n= image[0].size();
        if(r<0 ||r>=m ||c<0 ||c>=n) return;
        if(image[r][c]!=oldcolor) return;
        image[r][c]= newcolor;
        dfs(image,r+1,c,oldcolor,newcolor);
        dfs(image,r-1,c,oldcolor,newcolor);
        dfs(image,r,c+1,oldcolor,newcolor);
        dfs(image,r,c-1,oldcolor,newcolor);
        }
}