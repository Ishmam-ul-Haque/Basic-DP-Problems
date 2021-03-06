#include <bits/stdc++.h>
using namespace std;

// M x N matrix
#define M 5
#define N 5
#define mx 1007

int dp[mx][mx];

// Naive recursive function to find the minimum cost to reach
// cell (m, n) from cell (0, 0)
int findMinCost(int cost[M][N], int m, int n)
{
	// base case
	if (n == 0 || m == 0)
        return dp[m][n] = INT_MAX;

    // if we're at first cell (0, 0)
    if (m == 1 && n == 1)
        return dp[m][n] = cost[0][0];

	// include cost of the current cell in path and recuse to find minimum of
	// the path from adjacent left cell and adjacent top cell.
    return dp[m][n] = min (findMinCost(cost, m - 1, n), findMinCost(cost, m, n - 1))
				+ cost[m - 1][n - 1];
}

// main function
int main()
{
	int cost[M][N] =
	{
		{ 4, 7, 8, 6, 4 },
		{ 6, 7, 3, 9, 2 },
		{ 3, 8, 1, 2, 4 },
		{ 7, 1, 7, 3, 7 },
		{ 2, 9, 8, 9, 3 }
	};

    cout << "The minimum cost is " << findMinCost(cost, M, N)<<endl;

    return 0;
}
