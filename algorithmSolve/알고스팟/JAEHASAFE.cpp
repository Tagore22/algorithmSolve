#include <iostream>
#include <vector>

using namespace std;

vector<int> ff(const string& str)
{
	vector<int> pi(str.size(), 0);
	int begin = 1;
	int matched = 0;
	while (begin + matched < str.size())
	{
		if (str[begin + matched] == str[matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
			{
				++begin;
			}
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}//반시계 = f,s , 시계 = s,f;

vector<int> kmp(const string& a, const string& b)
{
	vector<int> answer;
	vector<int> pi = ff(b);
	int begin = 0;
	int matched = 0;
	while (begin + matched < a.size())
	{
		if (matched < b.size() && a[begin + matched] == b[matched])
		{
			++matched;
			if (matched == b.size())
				answer.push_back(begin);
		}
		else
		{
			if (matched == 0)
			{
				++begin;
			}
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return answer;
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
		int n;
		cin >> n;
		int check = 0;
		string first;
		cin >> first;
		for (int j = 0; j < n; ++j)
		{
			string second;
			cin >> second;
			if (j % 2 == 0)
				check += kmp(second + second, first)[0];
			else
				check += kmp(first + first, second)[0];
			first = second;
		}
		cout << check << '\n';
	}
	return 0;
}