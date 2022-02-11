#include <iostream>

using namespace std;

struct node
{
    int n;
    node *front, *rear;
};

int main(){
    int n,k;
    cin >> n >> k;
    cout << "<";
    node* l = new node();
    l->n = 1;
    node* p=l, *tp;
    for(int i=2;i<=n;i++){
        p->rear = new node();
        p->rear->front = p;
        p = p->rear;
        p->n = i;
    }
    p->rear = l;
    l->front = p;
    p = l;
    int i;
    for(int j=0;j<n-1;j++){
        for(i=0;i<k-1;i++)
        {
            //cout << "!" << p->n << " -> " << p->rear->n << endl;
            p = p->rear;
        }
        cout << p->n << ", ";
        p->front->rear = p->rear;
        p->rear->front = p->front;
        tp = p;
        p = p->rear;
        delete tp;
    }
    cout << p->n << ">\n";
    return 0;
}