#include <iostream>
int pass[31][31];
int main()
{
    int n, m, i, j;
    std::cin >> n >> m;
    pass[0][0] = 1;
    for (i = 0; i <= m; ++i)
	for (j = 0; j < n; ++j)
	    if (pass[i][j] > 0)
	    {
		if (j == n - 1)
		    pass[i + 1][0] += pass[i][j];
		else
		    pass[i + 1][j + 1] += pass[i][j];
		if (j == 0)
		    pass[i + 1][n - 1] += pass[i][j];
		else
		    pass[i + 1][j - 1] += pass[i][j];
	    }
    std::cout << pass[m][0] << std::endl;
    return 0;
}