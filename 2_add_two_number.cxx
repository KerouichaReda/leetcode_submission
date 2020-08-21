/*
 * 2_add_two_number.cxx
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
 * https://leetcode.com/problems/add-two-numbers/
 */


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {       
      
        
        ListNode  *ptr1=l1;
        ListNode  *ptr2=l2; 
        int sum = (*ptr1).val+(*ptr2).val;
        int rest = 0;
        ListNode  *result = new ListNode(sum) ;
        ListNode  *ptr3=result;
        
        while(ptr1!= nullptr)
        {
                
            
            //std::cout<<ptr1<<" "<<sum<<std::endl;
            if((*ptr1).next== nullptr)
            {
                break;
            }
            ptr1=(*ptr1).next;
            ptr2=(*ptr2).next; 
            sum=(*ptr1).val+(*ptr2).val+rest;
            rest = (int)sum /10;
            sum = sum%10;
            ListNode *r= new ListNode(sum) ; 
            
            (*ptr3).next=r;  
            ptr3=r;
            
             
        }

        return result;
    }

#include <iostream>

int main(int argc, char **argv)
{

	return 0;
}

