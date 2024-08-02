//deque의 poll을 이용한 풀이

/*import java.util.LinkedList;
import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
*/
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
/*class Solution {
    public ListNode reverseList(ListNode head) {

        ListNode node = head;
        //node -> head를 노드로 갖는 링크드 리스트

        Deque<Integer>deque = new LinkedList();

       while(node!=null){
        deque.add(node.val);
        node = node.next;
       }

        ListNode dummyHead = new ListNode(0);
        ListNode current = dummyHead;

        while(!deque.isEmpty()){

            int value = deque.pollLast();

            current.next = new ListNode(value);
            current = current.next;
        }





        return dummyHead.next;
        
    }
}*/


//recursive 이용한 reverse

import java.util.LinkedList;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;



public class Solution{

    public ListNode reverse(ListNode node, ListNode prev){
        if(node == null){

            return prev;
        }

        ListNode next =node.next;
        node.next = prev;

        return reverse(next, node);

        
        
    }




  public ListNode reverseList(ListNode head){
    return reverse( head , null);
  }

}