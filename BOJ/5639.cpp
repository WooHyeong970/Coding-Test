#include <iostream>

using namespace std;

class tree
{
private:
    int num;
    tree *left;
    tree *right;
public:
    tree(int n)
    {
        num = n;
        left = NULL;
        right = NULL;
    };
    
    int getNum()
    {
        return num;
    }
    
    tree* getLeft()
    {
        return left;
    }
    
    tree* getRight()
    {
        return right;
    }
    
    void setLeft(tree *l)
    {
        left = l;
    }
    
    void setRight(tree *r)
    {
        right = r;
    }
};

int n;

void insert_node(tree *t, int n)
{
    if(n < t->getNum())
    {
        if(t->getLeft() == NULL)
        {
            tree *new_t = new tree(n);
            t->setLeft(new_t);
        }
        else
            insert_node(t->getLeft(), n);
    }
    else
    {
        if(t->getRight() == NULL)
        {
            tree *new_t = new tree(n);
            t->setRight(new_t);
        }
        else
            insert_node(t->getRight(), n);
    }
}

void postorder(tree *temp)
{
    if(temp != NULL)
    {
        postorder(temp->getLeft());
        postorder(temp->getRight());
        cout << temp->getNum() << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    tree *t = new tree(n);
    while(cin >> n)
        insert_node(t, n);
    postorder(t);
}
