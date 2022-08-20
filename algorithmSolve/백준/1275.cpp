#include <iostream>
#include <vector>

using namespace std;

class RangeQuery
{
private:
	vector<int> vec;
	vector<long long> sum;
public:
	RangeQuery(const vector<int>& a);
	long long init(int idx, int left, int right);
	long long init();
	long long query(int left, int right, int idx, int nodeLeft, int nodeRight) const;
	long long query(int from, int to) const;
	long long update(int idx, int newvalue, int node, int left, int right);
	long long update(int idx, int newvalue);
};

RangeQuery::RangeQuery(const vector<int>& a) : vec(a.begin(), a.end()), sum(a.size() * 4)
{
}

long long RangeQuery::init(int idx, int left, int right)
{
	if (left == right)
		return sum[idx] = vec[left];
	int mid = (left + right) / 2;
	long long low = init(idx * 2, left, mid);
	long long hi = init(idx * 2 + 1, mid + 1, right);
	return sum[idx] = low + hi;
}

long long RangeQuery::init()
{
	return init(1, 0, vec.size() - 1);
}

long long RangeQuery::query(int left, int right, int idx, int nodeLeft, int nodeRight) const
{
	if (right < nodeLeft || nodeRight < left)
		return 0;
	if (left <= nodeLeft && right >= nodeRight)
		return sum[idx];
	int mid = (nodeLeft + nodeRight) / 2;
	long long low = query(left, right, idx * 2, nodeLeft, mid);
	long long hi = query(left, right, idx * 2 + 1, mid + 1, nodeRight);
	return low + hi;
}

long long RangeQuery::query(int from, int to) const
{
	return query(from, to, 1, 0, vec.size() - 1);
}

long long RangeQuery::update(int idx, int newvalue, int node, int left, int right)
{
	if (idx < left || idx > right)
		return sum[node];
	if (left == right)
		return sum[node] = newvalue;
	int mid = (left + right) / 2;
	long long low = update(idx, newvalue, node * 2, left, mid);
	long long hi = update(idx, newvalue, node * 2 + 1, mid + 1, right);
	return sum[node] = low + hi;
}

long long RangeQuery::update(int idx, int newvalue)
{
	return update(idx, newvalue, 1, 0, vec.size() - 1);
}

vector<int> board;
int N, Q;

void MakeAnswer()
{
	RangeQuery RQ(board);
	RQ.init();
	for (int i = 0; i < Q; ++i)
	{
		int from, to, idx, newvalue;
		cin >> from >> to >> idx >> newvalue;
		if (from > to) //ÀÌ ºÎºÐÀ» ±ôºýÇØ¼­ ÇÑÂü ¿À·¡°É·È´Ù. ¤Ð¤Ð
			swap(from, to);
		cout << RQ.query(from - 1, to - 1) << '\n';
		RQ.update(idx - 1, newvalue);
	}
}

void Input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;
	for (int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;
		board.push_back(a);
	}
}

int main()
{
	Input();
	MakeAnswer();
	return 0;
}