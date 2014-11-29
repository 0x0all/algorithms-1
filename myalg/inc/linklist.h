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
 # Last modified: 2014-11-28 15:25
 # 
 # Filename: linklist.h
 # 
 # Description: All Rights Are Reserved                 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdlib.h>
#include <iostream>
using namespace std;
namespace myalg 
{
    template <typename T = int>
        //define the list member class
        class l_mem
         {
            private:
                T mem_data;
                int position;
                l_mem *next;
            public:
                inline int getpos(){return position;};
                inline void setpos(int pos){this->position = pos;};
                inline T getdata(){return mem_data;};
                inline void setdata(T data){this->mem_data = data;};
                inline void setnext(l_mem * n){this->next = n;};
                inline l_mem * getnext(){return next;};
                //default constructor
                l_mem()
                {
                    this->next = NULL;
                    position = 0;
                    //mem_data = 0;//not sure
                };
                //overload operator =
                l_mem operator =(const l_mem &tmp);
        };

    template <typename T1 = int>
        //define the linklist class
        class linklist
        {
            private:
                //sieze of the list
                int size;

                //pointer pointer to member of the list 
                l_mem<T1> *head;
                l_mem<T1> *tail;

            public:
                //default constructor
                linklist()
                {
                    this->size = 0;
                    this->head = new l_mem<T1>;
                    head->setpos(0);
                    //this->tail = new l_mem<T1>;
                    //this->tail->setnext(NULL);
                    head->setpos(this->size);
                };

                //copy constructor
                linklist(const linklist& other_list)
                {
                    this->size += other_list.getsize();
                    //this->head = (l_mem*)malloc(sizeof *head);
                    *head = *(other_list.head);
                    //this->tail = (l_mem*)malloc(sizeof *tail);
                    *tail = *(other_list.tail);
                    this->size = other_list.getsize();
                };

                //destructor
                ~linklist()
                {
                    delete head;
                    //free(head);
                    delete tail;
                    //free(head);
                };

                //insert the next member after the member ins_pos,
                //-1 for the failing to insert and 0 for successing to insert
                int linklist_ins_next(T1 ins_data, l_mem<T1> *ins_pos = NULL);

                //remove the member
                int rm_next(l_mem<T1> *rm_pos)
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
                };
                
                //find the mem
                l_mem<T1>* find_mem(T1 find_data)
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


                void print_list()
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
                };

                //l_mem<T1> * gettail()
                //{
                    //return this->tail;
                //};
                inline int getsize(){return size;};
        };
}
#endif

