 /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 #        .---.         .-----------  
 #       /     \  __  /    ------    
 #      / /     \(  )/    -----   (`-')  _ _(`-')              <-. (`-')_            
 #     //////    '\/ `   ---      ( OO).-/( (OO ).->     .->      \( OO) )     .->   
 #    //// / //  :   : ---      (,------. \    .'_ (`-')----. ,--./ ,--/  ,--.'  ,-.
 #   // /   /  / `\/ '--         |  .---' '`'-..__)( OO).-. ' |   \ |  | (`-')'.'  /
 #  //          //..\\          (|  '--.  |  |  ' |( _) | | | |  . '|  |)(OO \    / 
 # ============UU====UU====      |  .--'  |  |  / : \|  |)| | |  |\    |  |  /   /) 
 #             '//||\\`          |  `---. |  '-'  /  '  '-' ' |  | \   |  `-/   /`  
 #               ''``            `------' `------'    `-----' `--'  `--'    `--'    
 # ########################################################################################################################
 # 
 # Author: edony - edonyzpc@gmail.com                 
 # 
 # twitter : @edonyzpc                                
 # 
 # Last modified: 2014-11-30 00:12
 # 
 # Filename: linklist.cpp
 # 
 # Description: All Rights Are Reserved                 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
#include "linklist.h"
#include <iostream>
using namespace std;
using namespace myalg;
template<typename T>
l_mem<T> l_mem<T>::operator =(const l_mem<T> &tmp)
{
    l_mem tmp_;
    tmp_.mem_data = tmp.mem_data;
    tmp_.position = tmp.position;
    tmp_.next = tmp.next;
    return tmp;
}
//template l_mem<int> l_mem<int>::operator =<int>(const l_mem<T> &tmp);

template<typename T>
l_mem<T>::l_mem()
{
    this->next = NULL;
    position = 0;
    //mem_data = 0;//not sure
}
//template l_mem<int>::l_mem<int>();

template<typename T1>
linklist<T1>::linklist()
{
    this->size = 0;
    this->head = new l_mem<T1>;
    head->setpos(0);
    //this->tail = new l_mem<T1>;
    //this->tail->setnext(NULL);
    head->setpos(this->size);
}
//template linklist<int>::linklist<int>();

template<typename T1>
linklist<T1>::linklist(linklist& other_list)
{
    this->size += other_list.getsize();
    //this->head = (l_mem*)malloc(sizeof *head);
    *head = *(other_list.head);
    //this->tail = (l_mem*)malloc(sizeof *tail);
    *tail = *(other_list.tail);
    this->size = other_list.getsize();
}
//template linklist<int>::linklist<int>(const linklist other_list);

template<typename T1>
linklist<T1>::~linklist()
{
    delete head;
    //free(head);
    delete tail;
    //free(head);
}
//template linklist<int>::~linklist<int>();

template<typename T1>
int linklist<T1>::linklist_ins_next(T1 ins_data, l_mem<T1> *ins_pos)
{
    l_mem<T1> *ins = new l_mem<T1>;
    if(ins == NULL) return -1;
    ins->setdata(ins_data);

    if(ins_pos == NULL)//insert at the head for default
    {
        ins->setnext(this->head->getnext());
        this->head->setnext(ins);
        ins->setpos(this->head->getpos() + 1);
        this->size++;
        if(this->size == 1)
        {
            this->tail = ins;
            ins->setnext(NULL);
        }
        this->tail->setpos(this->size);
     }
     else
     {
         ins->setnext(ins_pos->getnext());
         ins_pos->setnext(ins);
         ins->setpos(ins_pos->getpos() + 1);
         this->size++;
         if(ins->getnext() == NULL)
         {
             this->tail = ins;
            this->tail->setnext(NULL);
         }
         else
         {
            this->tail->setpos(this->size);
            this->tail->setnext(NULL);
         }
     }
     return 0;
}
//template int linklist<int>::linklist_ins_next<int>(int ins_data, l_mem<int> *ins_pos);

template<typename T1>
int linklist<T1>::rm_next(l_mem<T1> *rm_pos)
{
    if(rm_pos == NULL || rm_pos->getnext() ==NULL) return -1;//error removement
    l_mem<T1> * del = rm_pos->getnext();
    rm_pos->setnext(del->getnext());
    this->size--;
    l_mem<T1> * tmp = rm_pos->getnext();
    int i = 0;
    while(tmp != NULL)
    {
        tmp->setpos(tmp->getpos() - 1);
        tmp = tmp->getnext();
        std::cout<<"loop:"<<++i<<std::endl;
    }
    delete del;
    return 0;//finish removement
}
//template int linklist<int>::rm_next(l_mem<int> *rm_pos);

template<typename T1>
l_mem<T1>* linklist<T1>::find_mem(T1 find_data)
{
    l_mem<T1> * tmp = this->head;
    if(tmp == NULL) return NULL;

    tmp = tmp->getnext();
    while(tmp != NULL)
    {
        if(tmp->getdata() != find_data)
        {
            tmp = tmp->getnext();
            continue;
        }
        else
        {
            break;
        }
    }
    return tmp;
};
//template l_mem<int>* linklist<int>::find_mem(int find_data);

template<typename T1>
void linklist<T1>::print_list()
{
    l_mem<T1>* tmp = this->head->getnext();
    int s = this->size;
    std::cout<<"head"<<std::endl;
    std::cout<<" |"<<std::endl;
    while(s > 0)
    {
        T1 out = tmp->getdata();
        std::cout<<out<<std::endl;
        tmp = tmp->getnext();
        s--;
    }
    std::cout<<" |"<<std::endl;
    std::cout<<"tail"<<std::endl;
}
//template void linklist<int>::print_list<int>();
