#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int divv = 20091101;
int n, k;
vector<int> board;
vector<long long> check;
vector<long long> sum;

void firstCal()
{
	for (int i = 0; i <= n; ++i)
		++check[sum[i] % k];
	long long ans = 0;
	for (int i = 0; i < k; ++i)
	{
		ans += (check[i] * (check[i] - 1) / 2) % divv;
		ans %= divv;
	}
	cout << ans << '\n';
}

void secondCal()
{
	vector<int> answer(n + 1, 0);
	vector<int> prev(k, -1);
	for (int i = 0; i <= n; ++i)
	{
		if (i != 0)
			answer[i] = answer[i - 1];
		if (prev[sum[i] % k] != -1)
			answer[i] = max(answer[i], answer[prev[sum[i] % k]] + 1);
		prev[sum[i] % k] = i;
	}
	cout << answer.back() << '\n';
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n >> k;
		board.assign(n, 0);
		sum.assign(n + 1, 0);
		check.assign(k, 0);
		for (int j = 0; j < n; ++j)
		{
			cin >> board[j];
			sum[j + 1] = sum[j] + board[j];
		}
		firstCal();
		secondCal();
	}
	return 0;
}