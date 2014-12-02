 /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
 # ########################################################################################################
 # 
 # Author: edony - edonyzpc@gmail.com                 
 # 
 # twitter : @edonyzpc                                
 # 
 # Last modified: 2014-12-02 13:40
 # 
 # Filename: dou_list.cpp
 # 
 # Description: All Rights Are Reserved                 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
#include "dou_list.h"
using namespace myalg;
using namespace std;

template <typename T>
dl_mem<T>::dl_mem():l_mem<T>()
{
    this->pre = NULL;
    this->next = NULL;
}

template <typename T>
dl_mem<T> dl_mem<T>::operator=(dl_mem<T> assi)
{
    dl_mem<T> tmp;
    tmp.setdata(assi.getdata());
    tmp.setpos(assi.getpos());
    tmp.setnext(assi.getnext());
    tmp.setpre(assi.getpre());
    return tmp;
}

template <typename T1>
dou_list<T1>::dou_list():linklist<T1>()
{
    this->head = new dl_mem<T1>;
    
}

template <typename T1>
dou_list<T1>::dou_list(dou_list &cp):linklist<T1>()
{
    this->size = cp.getsize();
    *(this->head) = *(cp.head);
    *(this->tail) = *(cp.tail);
}


template <typename T1>
int dou_list<T1>::rm_pre(dl_mem<T1> *rm_pos)
{
    if(rm_pos == NULL || rm_pos->getpre() ==NULL) return -1;//error removement
    dl_mem<T1> * del = rm_pos->getpre();
    dl_mem<T1> * _del =del->getpre();
    cout<<del<<"|"<<_del<<endl;
    rm_pos->setpre(_del);
    _del->setnext(rm_pos);
    this->size--;
    dl_mem<T1> * tmp = rm_pos;
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

template <typename T1>
dl_mem<T1>* dou_list<T1>::find_mem(T1 find_data)
{
    dl_mem<T1> * tmp = this->head;
    if(tmp == NULL) return NULL;

    tmp = tmp->getnext();
    while(tmp != NULL)
    {
        if(tmp->getdata() != find_data)
        {
            cout<<tmp->getdata()<<endl;
            tmp = tmp->getnext();
            continue;
        }
        else
        {
            break;
        }
    }
    return tmp;

}

template <typename T1>
dou_list<T1>::~dou_list()
{
    delete head;
    delete tail;
}

template<typename T1>
void dou_list<T1>::print_list()
{
    dl_mem<T1>* tmp = this->head->getnext();
    int s = this->size;
    std::cout<<"head"<<std::endl;
    std::cout<<" |"<<std::endl;
    while(s > 0)
    {
        T1 out = tmp->getdata();
        int position = tmp->getpos();
        std::cout<<out<<"--"<<position<<"pre "<<tmp->getnext()<<" now "<<tmp<<" next "<<tmp->getnext()<<std::endl;
        tmp = tmp->getnext();
        s--;
    }
    std::cout<<" |"<<std::endl;
    std::cout<<"tail"<<std::endl;
}

template<typename T1>
int dou_list<T1>::linklist_ins_next(T1 ins_data, dl_mem<T1> *ins_pos)
{
    dl_mem<T1> *ins = new dl_mem<T1>;
    if(ins == NULL) return -1;
    ins->setdata(ins_data);

    if(ins_pos == NULL)//insert at the head for default
    {
        ins->setpre(this->head);
        if(this->head->getnext() == NULL)
        {
            this->head->setnext(ins);
        }
        else
        {
            ins->setnext(this->head->getnext());
            this->head->setnext(ins);
            this->head->getnext()->setpre(ins);
        }
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
            this->tail = ins;
            ins->setnext(NULL);
        }
        this->tail->setpos(this->size);
     }
     else
     {
         ins->setpre(ins_pos);
         if(ins_pos->getnext() == NULL)
         {
             ins->setnext(NULL);
         }
         else
         {
             ins->setnext(ins_pos->getnext());
         }
         ins_pos->setnext(ins);
         ins_pos->getnext()->setpre(ins);
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
template <typename T1>
int dou_list<T1>::linklist_ins_pre(T1 ins_data, dl_mem<T1> *ins_pos)
{
    dl_mem<T1> *ins = new dl_mem<T1>;
    if(ins == NULL) return -1;
    ins->setdata(ins_data);

    if(ins_pos == NULL)//insert at the head for default
    {
        ins->setpre(this->head);
        if(this->head->getnext() == NULL)
        {
            this->head->setnext(ins);
            ins->setnext(NULL);
        }
        else
        {
            ins->setnext(this->head->getnext());
            this->head->setnext(ins);
            this->head->getnext()->setpre(ins);
        }
        ins->setpos(this->head->getpos() + 1);
        dl_mem<T1> *poschange = ins->getnext();
        while(poschange != NULL)
        {
            poschange->setpos(poschange->getpos() + 1);
            poschange = poschange->getnext();
        }
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
        ins->setnext(ins_pos);
        ins->setpre(ins_pos->getpre());
        ins_pos->getpre()->setnext(ins);
        ins_pos->setpre(ins);
        ins->setpos(ins_pos->getpos());
        dl_mem<T1> *poschange = ins->getnext();
        while(poschange != NULL)
        {
            poschange->setpos(poschange->getpos() + 1);
            poschange = poschange->getnext();
        }
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
