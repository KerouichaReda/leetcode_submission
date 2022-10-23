/*
 * 445_Add_Two_Numbers_II.cxx
 * 
 * Copyright 2020 RedaKerouicha <redakerouicha@localhost>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <stack>

#include "listnode.hpp"


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        std::stack<int> sl1;
        std::stack<int> sl2;
        
        while(l1!=nullptr){
            sl1.push(l1->val);
            l1=l1->next;
        }
         while(l2!=nullptr){
            sl2.push(l2->val);
            l2=l2->next;
        }
        
        ListNode* temp =nullptr;
        int r=0;
        
        while (!sl1.empty() || !sl2.empty() || r>0){
            
            if (sl1.empty() && sl2.empty()){
                temp = new ListNode (r,temp);
                r=0;
            }else if (sl1.empty()) {                
                temp = new ListNode ((sl2.top()+ r)%10,temp);
                r= (sl2.top()+ r)/10;
                sl2.pop();
            }else if (sl2.empty()){
                temp = new ListNode ((sl1.top()+ r)%10,temp);
                r= (sl1.top()+ r)/10;
                sl1.pop();
            } 
            else {
                temp = new ListNode ((sl1.top()+sl2.top()+ r)%10,temp);
                r= (sl1.top()+sl2.top()+ r)/10;
                sl2.pop();
                sl1.pop();
            }
        }
        return temp;        
    }
int main(int argc, char **argv)
{
	
	return 0;
}

