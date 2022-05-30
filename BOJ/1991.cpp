#include <iostream>
#include <queue>
#include <map>
#define X first
#define Y second

using namespace std;

class tree
{
private:
    char key;
    tree *right;
    tree *left;
public:
    tree()
    {
        right = NULL;
        left = NULL;
        key = '-';
    }
    
    tree* getLeft()
    {
        return left;
    }
    
    tree* getRgiht()
    {
        return right;
    }
    
    void insert_left(char k)
    {
        left = new tree();
        left->getKey(k);
    }
    
    void insert_right(char k)
    {
        right = new tree();
        right->getKey(k);
    }
    
    void getKey(char k)
    {
        key = k;
    }
    
    char showKey()
    {
        return key;
    }
};

map<char, pair<char, char>> m;
queue<tree*> tree_Q;
int n, idx(0);
char k, l, r;

void visit(tree *t)
{
    cout << t->showKey();
}

void preorder(tree *t)
{
    if(t == NULL) return;
    visit(t);
    preorder(t->getLeft());
    preorder(t->getRgiht());
}

void inorder(tree *t)
{
    if(t == NULL) return;
    inorder(t->getLeft());
    visit(t);
    inorder(t->getRgiht());
}

void postorder(tree *t)
{
    if(t == NULL) return;
    postorder(t->getLeft());
    postorder(t->getRgiht());
    visit(t);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    tree *t = new tree();
    t->getKey('A');
    tree_Q.push(t);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> k >> l >> r;
        m.insert({k, {l, r}});
    }
    while(!tree_Q.empty())
    {
        tree *temp = tree_Q.front();
        tree_Q.pop();
        auto m_key = m.find(temp->showKey());
        pair<char, char> m_val = m_key->second;
        if(m_val.X !='.')
        {
            temp->insert_left(m_val.X);
            tree_Q.push(temp->getLeft());
        }
        if(m_val.Y != '.')
        {
            temp->insert_right(m_val.Y);
            tree_Q.push(temp->getRgiht());
        }
    }
    // 전위 순환
    preorder(t);
    cout << "\n";
    // 중위 순환
    inorder(t);
    cout << "\n";
    // 후위 순환
    postorder(t);
    cout << "\n";
}
