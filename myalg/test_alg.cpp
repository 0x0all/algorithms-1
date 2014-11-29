#include <iostream>
#include "linklist.h"
using namespace std;
using myalg::linklist;

int main()
{
    linklist * mylist = new linklist;
    l_mem<int> * mem1 = new l_mem<int>;
    int a = 10;
    mylist->linklist->ins->next(a);
    mylist->find_mem(a, mem1);
    int b =12;
    mylist->linklist->ins->next(mem1, b);
}
