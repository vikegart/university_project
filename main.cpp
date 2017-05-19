#include <iostream>
#include <fstream>
//Ќайти минимальный элемент и вывести его
using namespace std;

class tree {
private:
    struct el {
        int val;
        el *l_tree;
        el *r_tree;
        el() {
            l_tree = 0;
            r_tree = 0;
        }
    };
    el *root;
public:
    tree() {root = 0;}
    void push (int x, el *&b) { //ссылка на указатель
        if (!b) {
            el *t = new el;
            t->val = x;
            t->l_tree = t->r_tree = NULL;
            b = t;
        }
        if (b->val > x)
            push (x, b->l_tree);
        else
            if (b->val < x)
                push (x, b->r_tree);
    }
    void add (int x) {
        push(x, root);
    }
    //метод вывод€щий дерево в симметричном пор€дке
    void print (el *r = 0) {
        if (r == 0)
            r = root;
        if (r->l_tree != 0)
            print (r->l_tree);
        cout <<r->val<< ' ';
        if (r->r_tree != 0)
            print (r->r_tree);
    }




//наименьшее значение из листьев
    int minlist (el*r =0){
        if (r==0)
            r = root;
        if (!r->l_tree){
            return r->val;
        }
        else return minlist(r->l_tree);
    }
};


int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int x;
    tree derevo;
    while (in >> x) {
        derevo.add(x);
    }
    cout << "Bin tree search:";
    derevo.print();
//    cout << endl << "Answer:" << endl;
//    cout << derevo.ans() << endl;
    cout << endl << "Min:" << endl;
    cout<<derevo.minlist();

    return 0;
}