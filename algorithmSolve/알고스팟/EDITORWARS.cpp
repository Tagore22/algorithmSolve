#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

class UnionFind
{
private:
	vector<int> size;
	vector<int> parent;
	vector<int> enemy;
	vector<int> rank;
public:
	UnionFind(int n);
	int FindParent(int num);
	int Fusion(int a, int b);
	bool Ack(int a, int b);
	bool Dis(int a, int b);
	int Calcul() const;
};

UnionFind::UnionFind(int n) : size(n, 1), parent(n, 0), enemy(n, -1), rank(n, 0)
{
	for (int i = 0; i < n; ++i)
		parent[i] = i;
}

int UnionFind::FindParent(int num)
{
	if (parent[num] == num)
		return num;
	return parent[num] = FindParent(parent[num]);
}

int UnionFind::Fusion(int a, int b)//a에 b를 결속시킨다.
{
	if (a == -1 || b == -1)
		return max(a, b);

	a = FindParent(a);
	b = FindParent(b);

	if (a == b)
		return a;

	if (rank[a] < rank[b])
		swap(a, b);

	size[a] += size[b];
	parent[b] = a;
	if (rank[a] == rank[b])
		++rank[a];
	return a;
}

bool UnionFind::Ack(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);

	if (enemy[a] == b)
		return false;

	int first = Fusion(a, b);
	int second = Fusion(enemy[a], enemy[b]);

	enemy[first] = second;

	if (second != -1)
		enemy[second] = first;
	return true;
}

bool UnionFind::Dis(int a, int b)
{
	a = FindParent(a);
	b = FindParent(b);

	if (a == b)
		return false;

	int first = Fusion(a, enemy[b]);
	int second = Fusion(b, enemy[a]);

	enemy[first] = second;
	enemy[second] = first;
	return true;
}

int UnionFind::Calcul() const
{
	int answer = 0;
	for (int i = 0; i < n; ++i)
		if (parent[i] == i)
		{
			if (i < enemy[i])
				continue;
			int Msize = size[i];
			int Esize = enemy[i] == -1 ? 0 : size[enemy[i]];
			answer += max(Msize, Esize);
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
		int m;
		cin >> n >> m;
		UnionFind UF(n * 10);
		bool check = true;
		int checkNum = 0;
		for (int j = 0; j < m; ++j)
		{
			string str;
			int a, b;
			cin >> str >> a >> b;
			if (!check)
				continue;
			if (str == "ACK")
			{
				if (!UF.Ack(a, b))
				{
					check = false;
					checkNum = j + 1;
				}
			}
			else
			{
				if (!UF.Dis(a, b))
				{
					check = false;
					checkNum = j + 1;
				}
			}
		}
		if (check)
			cout << "MAX PARTY SIZE IS " << UF.Calcul() << '\n';
		else
			cout << "CONTRADICTION AT " << checkNum << '\n';
	}
	return 0;
}