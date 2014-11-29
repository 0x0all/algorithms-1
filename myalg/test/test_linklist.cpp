#include <iostream>
#include "linklist.h"
using namespace std;
using namespace myalg;

int main()
{
    linklist<int>  mylist;
    l_mem<int> * mem1 = new l_mem<int>;
    int a = 10;
    int b =12;
    int c = 14;
    int d = 22;
    mylist.linklist_ins_next(a);
    mylist.print_list();
    l_mem<int> * mem2 = mylist.find_mem(a);
    mylist.linklist_ins_next(b, mem2);
    mylist.linklist_ins_next(c, mem2);
    mylist.linklist_ins_next(d);
    mylist.print_list();
    mylist.rm_next(mem2);
    mylist.print_list();
    delete mem1;
}
