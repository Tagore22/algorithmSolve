#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxNum = 26;
vector<pair<int, string>> StrVec;
int n, m;

int TransAlpha(char ch)
{
	return ch - 'A';
}

struct SolongTree
{
	int first;
	int EndNum;
	SolongTree* board[MaxNum];
	SolongTree();
	~SolongTree();
	void InsertTree(const char* key, int id);
	SolongTree* FindTree(const char* key);
	int IsInChar(const char* key);
	int CountAnswer(const char* key, int id) const;
};

SolongTree::SolongTree() : first(-1), EndNum(-1)
{
	memset(board, 0, sizeof(board));
}

SolongTree::~SolongTree()
{
	for (int i = 0; i < MaxNum; ++i)
		if (board[i])
			delete board[i];
}

void SolongTree::InsertTree(const char* key, int id)
{
	if (first == -1)
		first = id;
	if (*key == 0)
		EndNum = id;
	else
	{
		int next = TransAlpha(*key);
		if (board[next] == NULL)
			board[next] = new SolongTree();
		board[next]->InsertTree(key + 1, id);
	}
}

SolongTree* SolongTree::FindTree(const char* key)
{
	if (*key == 0)
		return this;
	int next = TransAlpha(*key);
	if (board[next] == NULL)
		return NULL;
	return board[next]->FindTree(key + 1);
}

int SolongTree::IsInChar(const char* key)
{
	SolongTree* ST = FindTree(key);
	if (ST == NULL || ST->EndNum == -1)
		return strlen(key);
	return CountAnswer(key, ST->EndNum);
}

int SolongTree::CountAnswer(const char* key, int id) const
{
	if (*key == 0)
		return 0;
	if (first == id)
		return 1;
	int next = TransAlpha(*key);
	return board[next]->CountAnswer(key + 1, id) + 1;
}

SolongTree* FirstWork()
{
	SolongTree* ST = new SolongTree();
	sort(StrVec.begin(), StrVec.end());
	for (int i = 0; i < StrVec.size(); ++i)
		ST->InsertTree(StrVec[i].second.c_str(), i);
	ST->first = -1;
	return ST;
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
		int n, m;
		cin >> n >> m;
		StrVec.clear();
		for (int j = 0; j < n; ++j)
		{
			string str;
			int x;
			cin >> str >> x;
			StrVec.push_back(make_pair(-x, str));
		}
		SolongTree* ST = FirstWork();
		int answer = m - 1;
		for (int j = 0; j < m; ++j)
		{
			string str;
			cin >> str;
			answer += ST->IsInChar(str.c_str());
		}
		cout << answer << '\n';
	}
	return 0;
}