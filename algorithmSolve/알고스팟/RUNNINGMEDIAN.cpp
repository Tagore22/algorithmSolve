#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> first;
priority_queue<int, vector<int>, less<int>> second;
int board[200000];
int n, a, b;

int calcul(int num)
{
	if (first.size() == second.size())
		second.push(num);
	else
		first.push(num);
	if (!first.empty() && !second.empty() && (first.top() < second.top()))
	{
		int a = first.top();
		first.pop();
		int b = second.top();
		second.pop();
		first.push(b);
		second.push(a);
	}
	return second.top();
}

void makeBoard()
{
	board[0] = 1983;
	for (int i = 1; i < n; ++i)
		board[i] = (board[i - 1] * static_cast<long long>(a) + b) % 20090711;
}

void queueClear()
{
	while (!first.empty())
	{
		first.pop();
	}
	while (!second.empty())
	{
		second.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		int answer = 0;
		cin >> n >> a >> b;
		makeBoard();
		for (int j = 0; j < n; ++j)
		{
			answer += calcul(board[j]);
			answer %= 20090711;
		}
		cout << answer << '\n';
		queueClear();
	}
	return 0;
}