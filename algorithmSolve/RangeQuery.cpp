#include <iostream>
#include <vector>

using namespace std;

class RangeQuery
{
private:
	vector<int> vec;
	vector<int> QV;
public:
	RangeQuery(const vector<int>& a);
	int init(int idx, int left, int right);
	int init();
	int query(int left, int right, int idx, int nodeLeft, int nodeRight) const;
	int query(int from, int to) const;
	int update(int idx, int nodevalue, int node, int left, int right);
};

RangeQuery::RangeQuery(const vector<int>& a) : vec(a.begin(), a.end()), QV(a.size() * 4, 0)
{
}

int RangeQuery::init(int idx, int left, int right)
{
	if (left == right)
		return QV[idx] = vec[left];
	int mid = (left + right) / 2;
	return QV[idx] = min(init(idx * 2, left, mid), init(idx * 2 + 1, mid + 1, right));
}

int RangeQuery::init()
{
	return init(1, 0, vec.size() - 1);
}

int RangeQuery::query(int left, int right, int idx, int nodeLeft, int nodeRight) const
{
	if (right < nodeLeft || nodeRight < left)
		return 987654321;
	if (left <= nodeLeft && right >= nodeRight)
		return QV[idx];
	int mid = (nodeLeft + nodeRight) / 2;
	return min(query(left, right, idx * 2, nodeLeft, mid), query(left, right, idx * 2 + 1, mid + 1, nodeRight));
}

int RangeQuery::query(int from, int to) const
{
	return query(from, to, 1, 0, vec.size() - 1);
}

int RangeQuery::update(int idx, int nodevalue, int node, int left, int right)
{
	if (left == right)
		QV[node] = nodevalue;
	if (idx < left || idx > right)
		return 987654321;
	int mid = (left + right) / 2;
	return QV[node] = min(update(idx, nodevalue, node * 2, left, mid), update(idx, nodevalue, node * 2 + 1, mid + 1, right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> check;
	while (true)
	{
		int x;
		cin >> x;
		if (x == 0)
			break;
		check.push_back(x);
	}
	RangeQuery ins(check);
	ins.init();
	while (true)
	{
		int from, to;
		cin >> from >> to;
		if (from == 0 && to == 0)
			break;
		cout << ins.query(from, to) << '\n';
	}
	return 0;
}