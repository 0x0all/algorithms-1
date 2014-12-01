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
    template <typename T>
        class dl_mem: public l_mem
        {
            private:
                dl_mem *pre;
            public:
                dl_mem();
                dl_mem(dl_mem & cp);
                dl_mem operator=(dl_mem assi);
                inline void setpre(l_mem * n){this->pre = n;};
                inline l_mem * getpre(){return pre;};
        };
    template <typename T1>
        class dou_list: public link
        {
            private:
            public:
                dou_list();
                dou_list(dou_list & cp);
                ~dou_list();
                int linklist_ins_pre(T1 ins_data, l_mem<T1> *ins_pos = NULL);
                int rm_pre(l_mem<T1> *rm_pos);
        };
}
#endif
