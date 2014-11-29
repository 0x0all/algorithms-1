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
    l_mem tmp_ = new l_mem;
    tmp_.mem_data = tmp.mem_data;
    tmp_.position = tmp.position;
    tmp_.next = tmp.next;
    return tmp;
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

