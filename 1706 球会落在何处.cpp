#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    /// <summary>
    /// ģ�� ���־���ϵ��
    /// �ȴ��п�ʼ��Ȼ������У��е�λ�ò��ϸ��£��������Խ���߽�ʱ����V�������㲻�����ڵײ�
    /// զ��V��
    /// ͬһ�б仯ǰǰ�ͱ仯�����ֵ������ͬ
    /// so��have hand just ok��
    /// </summary>
    /// <param name="grid"></param>
    /// <returns></returns>
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            // ��ĳ�ʼ��
            int col = i;
            for (auto& row : grid)
            {
                int num = row[col];
                col += row[col];
                // Խ���߽���߳���V����
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