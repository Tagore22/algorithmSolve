#include <iostream>
#include <vector>

using namespace std;

class RangeQuery
{
private:
	vector<int> vec;
	vector<pair<int, int>> QV;
public:
	RangeQuery(const vector<int>& a);
	pair<int, int> init(int idx, int left, int right);
	pair<int, int> init();
	pair<int, int> query(int left, int right, int idx, int nodeLeft, int nodeRight) const;
	pair<int, int> query(int from, int to) const;
};

RangeQuery::RangeQuery(const vector<int>& a) : vec(a.begin(), a.end()), QV(a.size() * 4)
{
}

pair<int, int> RangeQuery::init(int idx, int left, int right)
{
	if (left == right)
		return QV[idx] = make_pair(vec[left], vec[left]);
	int mid = (left + right) / 2;
	auto low = init(idx * 2, left, mid);
	auto hi = init(idx * 2 + 1, mid + 1, right);
	return QV[idx] = make_pair(max(low.first, hi.first), min(low.second, hi.second));
}

pair<int, int> RangeQuery::init()
{
	return init(1, 0, vec.size() - 1);
}

pair<int, int> RangeQuery::query(int left, int right, int idx, int nodeLeft, int nodeRight) const
{
	if (right < nodeLeft || nodeRight < left)
		return make_pair(-987654321, 987654321);
	if (left <= nodeLeft && right >= nodeRight)
		return QV[idx];
	int mid = (nodeLeft + nodeRight) / 2;
	auto low = query(left, right, idx * 2, nodeLeft, mid);
	auto hi = query(left, right, idx * 2 + 1, mid + 1, nodeRight);
	return make_pair(max(low.first, hi.first), min(low.second, hi.second));
}

pair<int, int> RangeQuery::query(int from, int to) const
{
	return query(from, to, 1, 0, vec.size() - 1);
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
		int n, q;
		vector<int> check;
		cin >> n >> q;
		for (int j = 0; j < n; ++j)
		{
			int x;
			cin >> x;
			check.push_back(x);
		}
		RangeQuery RQ(check);
		RQ.init();
		for (int j = 0; j < q; ++j)
		{
			int x, y;
			cin >> x >> y;
			auto answer = RQ.query(x, y);
			cout << answer.first - answer.second << '\n';
		}
	}
	return 0;
}