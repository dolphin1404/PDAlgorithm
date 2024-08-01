/*  
  실패함

import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;
import java.util.LinkedList;


class ListNode {
       int val;
       ListNode next;
       ListNode() {}
       ListNode(int val) { this.val = val; }
       ListNode(int val, ListNode next) { this.val = val; this.next = next; }

       public static ListNode deserialize(String data){
        if(data == null || data.isEmpty()){
            return null;
        }

        String[] parts = data.split(",");
        ListNode head = new ListNode(Integer.parseInt(parts[0]));
        ListNode current = head;
        for(int i=1 ; i< parts.length; i++ ){
            current.next = new ListNode(Integer.parseInt(parts[i]));
            current = current.next;
        }

        return head;

       }


    
    
    }

public class Solution{

    public boolean isPalindrome(ListNode head){

        Stack<Integer> stack = new Stack<>();
        ListNode node = head;

        while(node != null){
            stack.add(node.val);

            node = node.next;
        }


        while(head != null){
            if(head.val != stack.pop()){
                return false;

            }

            head = head.next;

        }

        return true;
    }





    }






// 데크 사용 
// deque == 양방향 stack 이라고 생각하면 좋다.


import java.util.ArrayList;
import java.util.Scanner;
import java.util.Deque;
import java.util.LinkedList;


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


 /*
public class Solution{


    public boolean isPalindrome(ListNode head){

        Deque dq = new LinkedList();

        ListNode node = head;

        while(node != null){
            dq.add(node.val);
            node  = node.next;

        }

        while(!dq.isEmpty()&& dq.size()>1){

            if(dq.pollFirst() != dq.pollLast()){

                return false;

            }

        }

        return true;


    }
}

*/



//runner를 이용한 풀이
//solve runner
// 중간까지의 list 를 만들고 그이후의 list는 역순으로 만들어 비교


import java.util.Scanner;
import java.util.List;
import java.util.LinkedList;
import java.util.Deque;




public class LTC234{
    public boolean isPalindrome(ListNode head){

        ListNode fastRunner =head;
        ListNode slowRunner = head;

        while(fastRunner!= null && fastRunner.next != null){

            fastRunner=fastRunner.next.next;
            slowRunner = slowRunner.next;

        }
        
        if(fastRunner != null){
            slowRunner= slowRunner.next;


        }

        ListNode rev =null;
        while(slowRunner != null){
            ListNode next = slowRunner.next;
            slowRunner.next = rev;
            rev = slowRunner;
            slowRunner = next;

        }

        while(rev != null){

            if(rev.val != head.val){
                return false;
            }
            rev = rev.next;
            head = head.next;



        }


        return true;
    }



}