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
 # Last modified: 2014-12-01 16:20
 # 
 # Filename: dou_list.h
 # 
 # Description: All Rights Are Reserved                 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
#ifndef DOU_LIST_H_
#define DOU_LIST_H_
#include "linklist.h"
namespace myalg
{
    using namespace myalg;
    template <typename T = int>
        class dl_mem:public l_mem<T>
        {
            private:
                dl_mem *pre;
                dl_mem *next;
            public:
                dl_mem();
                //dl_mem(dl_mem & cp);
                dl_mem operator=(dl_mem assi);
                inline int getpos(){return this->position;};
                inline void setpos(int pos){this->position = pos;};
                inline T getdata(){return this->mem_data;};
                inline void setdata(T data){this->mem_data = data;};
                inline void setnext(dl_mem * n){this->next = n;};
                inline dl_mem * getnext(){return next;};
                inline void setpre(dl_mem * n){this->pre = n;};
                inline dl_mem * getpre(){return pre;};
        };

    template <typename T1 = int>
        class dou_list:public linklist<T1>
        {
            private:
                dl_mem<T1> *head;
                dl_mem<T1> *tail;
            public:
                dou_list();
                dou_list(dou_list & cp);
                int linklist_ins_pre(T1 ins_data, dl_mem<T1> *ins_pos = NULL);
                int linklist_ins_next(T1 ins_data, dl_mem<T1> *ins_pos = NULL);
                virtual ~dou_list();
                int rm_pre(dl_mem<T1> *rm_pos);
                dl_mem<T1>* find_mem(T1 find_data);
                void print_list();
        };
}
#endif
