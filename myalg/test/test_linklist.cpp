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
    l_mem<int> * mem3 = mylist.find_mem(c);
    if(mem3 == NULL)cout<<"can not find the mem"<<endl;
    mem3 = mylist.find_mem(d);
    if(mem3 != NULL)cout<<mem3->getdata()<<endl;
    mylist.linklist_ins_next(555,mem3);
    mylist.print_list();
    delete mem1;
    return 0;
}
