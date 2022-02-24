#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    /// <summary>
    /// 模拟 有手就行系列
    /// 先从列开始，然后遍历行，列的位置不断更新，如果出现越过边界时或者V字形则算不能落在底部
    /// 咋算V？
    /// 同一行变化前前和变化后的数值必须相同
    /// so，have hand just ok！
    /// </summary>
    /// <param name="grid"></param>
    /// <returns></returns>
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            // 球的初始列
            int col = i;
            for (auto& row : grid)
            {
                int num = row[col];
                col += row[col];
                // 越过边界或者出现V字形
                if (col < 0 || col >= n || row[col] != num)
                {
                    col = -1;
                    break;
                }
            }
            ans[i] = col;
        }
        return ans;
    }
};

int main(int argc, char** argv)
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }
    Solution sol;
    auto ans = sol.findBall(grid);
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

	return 0;
}