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
#ifndef LINKLIST_H_
#define LINKLIST_H_
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
                l_mem();
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
                linklist();

                //copy constructor
                linklist(linklist& other_list);

                //destructor
                ~linklist();

                //insert the next member after the member ins_pos,
                //-1 for the failing to insert and 0 for successing to insert
                int linklist_ins_next(T1 ins_data, l_mem<T1> *ins_pos = NULL);

                //remove the member
                int rm_next(l_mem<T1> *rm_pos);
                
                //find the mem
                l_mem<T1>* find_mem(T1 find_data);


                void print_list();

                //l_mem<T1> * gettail()
                //{
                    //return this->tail;
                //};
                inline int getsize(){return size;};
        };
}
#endif

