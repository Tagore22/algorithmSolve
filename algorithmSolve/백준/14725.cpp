#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<string> StrVec;
int k;

struct AntTree
{
    map<string, AntTree*> board;
    void Insert(int idx);
    void ShowAll(int d);
};

void AntTree::Insert(int idx)
{
    if (idx == k)
        return;
    if (board.find(StrVec[idx]) == board.end())
        board.insert(make_pair(StrVec[idx], new AntTree()));
    board[StrVec[idx]]->Insert(idx + 1);
}

void AntTree::ShowAll(int d)
{
    if (board.empty())
        return;
    map<string, AntTree*>::iterator iter;
    for (iter = board.begin(); iter != board.end(); ++iter)
    {
        for (int i = 0; i < d; ++i)
            cout << "--";
        cout << iter->first << '\n';
        iter->second->ShowAll(d + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    AntTree AT;
    for (int i = 0; i < n; ++i)
    {
        cin >> k;
        StrVec.assign(k, "");
        for (int j = 0; j < k; ++j)
            cin >> StrVec[j];
        AT.Insert(0);
    }
    AT.ShowAll(0);
    return 0;
}