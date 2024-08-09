import java.util.Scanner;
import java.util.List;
import java.util.LinkedList;
//206번과 함께 보면 더좋음
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
  * 
  수도코드
  1: 해당 리스트의 인덱스 번호에따라 마지막 리스트 헤드를 처음 부분에 붙이고 
  차례대로 리스트 next를 정하는 로직

  list swap 로직



  */
class leetcode92 {
    public ListNode reverseBetween(ListNode head, int left, int right) {

        //exeption
        if(head == null || left == right){

            return head;


        }
       ListNode root = new ListNode(0);

       root.next = head;

       ListNode start = root;

       

       for(int i =0 ; i< left-1 ; i++ ){
        start = start.next;



       }

       ListNode end = start.next;

       for(int i =0; i<right-left ; i++ ){


        ListNode tmp = start.next;
        start.next = end.next;
        end.next = end.next.next;
        start.next.next = tmp;
       }


       return root.next;

        
    }
}