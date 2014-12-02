#include <iostream>
#include "linklist.h"
#include "dou_list.h"
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

    //double-link list
    cout<<"start the double-link list!"<<endl;
    dou_list<int> mydol;
    dl_mem<int> * dmem1 = new dl_mem<int>;
    int A = 10;
    int B =12;
    int C = 14;
    int D = 22;
    mydol.linklist_ins_pre(A);
    mydol.print_list();
    dl_mem<int> * dmem2 = mydol.find_mem(A);
    mydol.linklist_ins_pre(B, dmem2);
    mydol.print_list();
    mydol.linklist_ins_next(C, dmem2);
    mydol.print_list();
    mydol.linklist_ins_pre(D);
    mydol.print_list();
    mydol.rm_pre(dmem2);
    mydol.print_list();
    dl_mem<int> * dmem3 = mydol.find_mem(C);
    if(dmem3 == NULL)cout<<"can not find the mem"<<endl;
    dmem3 = mydol.find_mem(D);
    mydol.linklist_ins_next(555,dmem3);
    mydol.print_list();
    delete dmem1;


    return 0;
}
