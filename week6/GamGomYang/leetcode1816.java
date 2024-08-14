import java.util.List;
import java.util.ArrayList;
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
class leetcod1816 {
    public ListNode reverseList(ListNode head) {
        ListNode root = new ListNode(0);
        root.next = head;

        if(head == null || head.next == null){
            return head;
        }

        ListNode start = root.next;
        ListNode end = start.next;
        ListNode current = head;
        int count =0;

        while(current != null){
            count++;
            current = current.next;


        }


        for(int i=1; i<count; i++ ){
            ListNode temp = start.next;
            start.next = end.next;
            end.next = root.next;
            root.next = end;
            end = start.next;
            


        }
        

        return root.next;
        



    }
}