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
    this->mem_data = tmp.mem_data;
    cout<<mem_data<<endl;
    this->position = tmp.position;
    cout<<position<<endl;
    this->next = tmp.next;
    cout<<next<<endl;
    return *this;
}

template<typename T>
l_mem<T>::l_mem()
{
    cout<<"constructor a new object!"<<endl;
    this->next = NULL;
    position = 0;
    //mem_data = 0;//not sure
}

//template <typename T>
//l_mem<T>::~l_mem()
//{
//    cout<<"destructor"<<endl;
//}

template<typename T1>
linklist<T1>::linklist()
{
    this->size = 0;
    this->head = new l_mem<T1>;
    this->head->setpos(0);
    this->tail = new l_mem<T1>;
    this->tail->setnext(NULL);
    this->tail->setpos(0);
}
//template linklist<int>::linklist<int>();

template<typename T1>
linklist<T1>::linklist(const linklist& other_list)
{
    cout<<"copied list"<<endl;
    this->head = new l_mem<T1>;
    this->size = 0;
    this->head->setpos(0);
    this->tail = new l_mem<T1>;
    this->tail->setpos(0);
    this->tail->setnext(NULL);
    l_mem<T1> *tmp = other_list.head->getnext();
    l_mem<T1> *tmp_ins = this->head;
    T1 data = tmp->getdata();
    while(tmp)
    {
        data = tmp->getdata();
        this->linklist_ins_next(data, tmp_ins);
        tmp_ins = tmp_ins->getnext();
        tmp = tmp->getnext();
    }
    this->tail->setnext(tmp_ins);
    tmp_ins->setnext(NULL);
}

template<typename T1>
linklist<T1>::~linklist()
{
    delete head;
    delete tail;
}

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
        l_mem<T1> *poschange = ins->getnext();
        while(poschange != NULL)
        {
            poschange->setpos(poschange->getpos() + 1);
            poschange = poschange->getnext();
        }
        this->size++;
        if(this->size == 1)
        {
            this->tail->setnext(ins);
            ins->setnext(NULL);
        }
     }
     else
     {
         ins->setnext(ins_pos->getnext());
         ins_pos->setnext(ins);
         ins->setpos(ins_pos->getpos() + 1);
         l_mem<T1> *poschange = ins->getnext();
         while(poschange != NULL)
         {
             poschange->setpos(poschange->getpos() + 1);
             poschange = poschange->getnext();
         }
         this->size++;
         if(ins->getnext() == NULL)
         {
             this->tail->setnext(ins);
             ins->setnext(NULL);
         }
     }
     return 0;
}

template<typename T1>
int linklist<T1>::rm_next(l_mem<T1> *rm_pos)
{
    if(rm_pos == NULL || rm_pos->getnext() ==NULL) return -1;//error removement
    l_mem<T1> * del = rm_pos->getnext();
    rm_pos->setnext(del->getnext());
    if(del->getnext() == NULL)//if remove the last one ,reset the tail
    {
        this->tail->setnext(rm_pos);
        rm_pos->setnext(NULL);
    }
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
    std::cout<<"head "<<this->head<<std::endl;
    std::cout<<" |"<<std::endl;
    while(s > 0)
    {
        T1 out = tmp->getdata();
        int position = tmp->getpos();
        std::cout<<out<<"--"<<position<<" now "<<tmp<<" next "<<tmp->getnext()<<std::endl;
        tmp = tmp->getnext();
        s--;
    }
    std::cout<<" |"<<std::endl;
    std::cout<<"tail "<<this->tail<<std::endl;
}
//template void linklist<int>::print_list<int>();
