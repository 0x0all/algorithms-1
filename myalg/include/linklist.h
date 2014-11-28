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
namespace myalg 
{
    template <typename T = int>
        //define the list member
        struct l_mem
        {
            T mem_data;
            int position;
            l_mem *next;
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
                    head->position = 0;
                    this->tail = new l_mem<T1>;
                    head->position = this->size;
                }

                //copy constructor
                linklist(const linklist& other_list)
                {
                    this->size += other_list.getsize();
                    this->head = new l_mem<T1>;
                    //this->head = (l_mem*)malloc(sizeof *head);
                    *head = *(other_list.head);
                    this->tail = new l_mem<T1>;
                    //this->tail = (l_mem*)malloc(sizeof *tail);
                    *tail = *(other_list.tail);
                    this->size = other_list.getsize();
                }

                //destructor
                ~linklist()
                {
                    delete head;
                    //free(head);
                    delete tail;
                    //free(head);
                }

                //insert the next member after the member ins_pos,
                //-1 for the failing to insert and 0 for successing to insert
                int linklist_ins_next(l_mem<T1> *ins_pos, T1 ins_data)
                {
                    l_mem<T1> *ins = new l_mem<T1>;
                    if(ins == NULL) return -1;
                    ins->mem_data = ins_data;

                    ins->mem_data = ins_data;
                    if(ins_pos == NULL)//insert at the head for default
                    {
                        if(this->getsize() == 0)
                        {
                            this->tail = ins;
                        }
                        ins->next = this->head;
                        this->head = ins;
                        ins->position = this->head + 1;
                        this->size++;
                        this->tail = this->size;
                    }
                    else
                    {
                        ins->next = ins_pos->next;
                        ins_pos->next = ins;
                        if(ins->next == NULL)
                        {
                            this->tail = ins;
                        }
                        ins->position = ins_pos->position + 1;
                        this->size++;
                        this->tail = this->size;
                    }
                    return 0;

                }

                //remove the member
                int rm_next(l_mem<T1> *rm_pos)
                {
                    if(rm_pos == NULL || rm_pos->next ==NULL) return -1;//error removement

                    rm_pos->next = rm_pos->next->next;
                    this->size--;
                    l_mem<T1> * tmp = new l_mem<T1>;
                    tmp = rm_pos->next;
                    while(tmp != NULL)
                    {
                        tmp->position--;
                        tmp = tmp->next;
                    }
                    delete tmp;
                    return 0;//finish removement
                }
                
                //find the mem
                int find_mem(T1 find_data, l_mem<T1> * pop_mem)
                {
                    l_mem<T1> * tmp = new l_mem<T1>;
                    if(tmp == NULL) return -1;
                    tmp = this->head->next;
                    while(tmp != NULL)
                    {
                        if(tmp->mem_data != find_data)
                        {
                            tmp = tmp->next;
                        }
                        else
                        {
                            pop_mem = tmp;
                            return 0;
                        }
                    }
                }

                inline int getsize(){return size;}
        };
}
#endif

