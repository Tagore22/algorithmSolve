#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<string> StrVec;

struct TreeNode
{
    map<char, TreeNode*> board;
    bool IsEnd;
    TreeNode();
    ~TreeNode();
    void InsertTree(const char* key);
    TreeNode* FindTree(const char* key);
    int CountAnswer(const char* key, bool IsFirst);
};

TreeNode::TreeNode() : IsEnd(false)
{
}

TreeNode::~TreeNode()
{
    map<char, TreeNode*>::iterator iter;
    for (iter = board.begin(); iter != board.end(); ++iter)
        if (iter->second)
            delete iter->second;
}

void TreeNode::InsertTree(const char* key)
{
    if (*key == 0)
    {
        IsEnd = true;
        return;
    }
    if (board.find(*key) == board.end())
        board.insert(make_pair(*key, new TreeNode()));
    board[*key]->InsertTree(key + 1);
}

TreeNode* TreeNode::FindTree(const char* key)
{
    if (*key == 0)
        return this;
    if (board.find(*key) == board.end())
        return NULL;
    board[*key]->FindTree(key + 1);
}

int TreeNode::CountAnswer(const char* key, bool IsFirst)
{
    if (*key == 0)
        return 0;
    if (board.size() == 1 && !IsEnd && !IsFirst)
        return board[*key]->CountAnswer(key + 1, false);
    return board[*key]->CountAnswer(key + 1, false) + 1;
}

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n)
    {
        TreeNode* TN = new TreeNode();
        StrVec.clear();
        for (int i = 0; i < n; ++i)
        {
            string str;
            cin >> str;
            StrVec.push_back(str);
            TN->InsertTree(str.c_str());
        }
        double answer = 0; // 1인가 0인가
        for (int i = 0; i < n; ++i)
            answer += TN->CountAnswer(StrVec[i].c_str(), true);
        answer /= n;
        cout.precision(2);
        cout << fixed;
        cout << answer << '\n';
    }
    return 0;
}