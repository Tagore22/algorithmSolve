#include <iostream>
#include <vector>

//평범한 구간 트리 문제다. 동작 원리를 잘 기억해둘것.

using namespace std;

class RangeQuery
{
private:
	vector<long long> vec;
	vector<long long> sum;
public:
	RangeQuery(const vector<long long>& a);
	long long init(int idx, int left, int right);
	long long init();
	long long query(int left, int right, int idx, int nodeLeft, int nodeRight) const;
	long long query(int from, int to) const;
	long long update(int idx, long long newvalue, int node, int left, int right);
	long long update(int idx, long long newvalue);
};

RangeQuery::RangeQuery(const vector<long long>& a) : vec(a.begin(), a.end()), sum(a.size() * 4)
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

long long RangeQuery::update(int idx, long long newvalue, int node, int left, int right)
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

long long RangeQuery::update(int idx, long long newvalue)
{
	return update(idx, newvalue, 1, 0, vec.size() - 1);
}

vector<long long> board;
int N, M, K;

void MakeAnswer()
{
	RangeQuery RQ(board);
	RQ.init();
	for (int i = 0; i < M + K; ++i)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			RQ.update(b - 1, c);
		else
			cout << RQ.query(b - 1, c - 1) << '\n';
	}
}

void Input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		long long a;
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