#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

const int MaxNum = 1000000;

class RangeQuery
{
private:
	vector<long long> QV;
	vector<int> board;
public:
	RangeQuery();
	long long Query(int Qleft, int Qright, int idx, int left, int right) const;
	long long Query(int Qleft, int Qright) const;
	long long Update(int Qidx, int idx, int left, int right);
	long long Update(int Qidx);
};

RangeQuery::RangeQuery() : QV(MaxNum * 4, 0), board(MaxNum, 0)
{
}

long long RangeQuery::Query(int Qleft, int Qright, int idx, int left, int right) const
{
	if (Qright < left || right < Qleft)
		return 0;
	if (Qleft <= left && right <= Qright)
		return QV[idx];
	int mid = (left + right) / 2;
	return Query(Qleft, Qright, idx * 2, left, mid) + Query(Qleft, Qright, idx * 2 + 1, mid + 1, right);
}

long long RangeQuery::Query(int Qleft, int Qright) const
{
	return Query(Qleft, Qright, 1, 0, board.size() - 1);
}

long long RangeQuery::Update(int Qidx, int idx, int left, int right)
{
	if (Qidx < left || Qidx > right)
		return QV[idx];
	if (left == right)
		return QV[idx] = QV[idx] + 1;
	int mid = (left + right) / 2;
	return QV[idx] = Update(Qidx, idx * 2, left, mid) + Update(Qidx, idx * 2 + 1, mid + 1, right);
}

long long RangeQuery::Update(int Qidx)
{
	return Update(Qidx, 1, 0, board.size() - 1);
}

int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; ++i)
	{
		int n;
		cin >> n;
		int answer = 0;
		RangeQuery RQ;
		for (int j = 0; j < n; ++j)
		{
			int x;
			cin >> x;
			answer += RQ.Query(x + 1, MaxNum - 1);
			RQ.Update(x);
		}
		cout << answer << '\n';
	}
	return 0;
}