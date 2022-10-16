public class LinkedList implements List{
    Node head;
    
    public boolean isEmpty(){
        return head==null;
    }
    public int size(){
        int listCount=0;
        if(!isEmpty()){
            Node curNode=head;
            while(curNode!=null){
                listCount++;
                curNode=curNode.next;
            }
        }
        return listCount;
    }
    public void add(Object item){
        Node newNode = new Node(item);
        if(isEmpty()){
            head = newNode;
        }
        else{
            Node curNode=head;
            while(curNode.next!=null){
                curNode=curNode.next;
            }
            curNode.next=newNode;
        }
    }
    public void add(int index, Object item){
        Node newNode = new Node(item);
        if(isEmpty()){
            head = newNode;
        }
        else{
            Node curNode=head;
            Node indexNode=null;
            for(int i=1; i<index; i++){
                if(i<index-1)
                curNode=curNode.next;
                else if(i==index-1){
                    indexNode=curNode.next;
                    break;
                }
            }
            curNode.next=newNode;
            newNode.next=indexNode;
        }
    }
    public void remove(int index){
        if(index==1){
            head=head.next;   
        }
        else{
            Node curNode=head;
            Node indexNode=null;
            for(int i=1; i<index; i++){
                if(i<index-1)
                curNode=curNode.next;
                else if(i==index-1){
                    indexNode=curNode.next;
                    break;
                }
            }
            curNode.next=indexNode.next;
        }
    }
    public void remove1(Object item){
        if(head.data==item){
            head=head.next; 
        }
        else{
            Node curNode=head;
            Node previousNode=null;
            while(curNode!=null){
                if(curNode.data==item){
                    previousNode.next=curNode.next;
                    break;
                }
                previousNode=curNode;
                curNode=curNode.next;
            }
        }
    }
    
    public void duplicate(){
        Node duphead=null;
        Node curNode=head;
        while(curNode!=null){
            Node newNode = new Node(curNode.data);
            if(duphead==null){
                duphead=newNode;
            }
            else{
                newNode.next=duphead;
                duphead=newNode;
            }
            curNode=curNode.next;
        }
        Node cur=duphead;
        while(cur!=null){
            System.out.print(cur.data+" ");
            cur=cur.next;
        }
        System.out.println();
    }
    
    public void duplicateReversed(){
         Node duphead=null;
         Node curNode=head;
        while(curNode!=null){
            Node newNode = new Node(curNode.data);
            if(duphead==null){
                duphead=newNode;
            }
            else{
                Node curr = duphead;
                while(curr.next!=null){
                curr = curr.next;
                }
                curr.next=newNode;
            }
            curNode=curNode.next;
        }
        Node cur=duphead;
        while(cur!=null){
            System.out.print(cur.data+" ");
            cur=cur.next;
        }
        System.out.println();
    }
    public void printList(){
        if(head==null){
            System.out.println("list is empty.");
        }
        else{
            Node curNode=head;
            while(curNode!=null){
                System.out.print(curNode.data+" ");
                curNode=curNode.next;
            }
            System.out.println();
        }
    }
    
    class Node{
        Object data;
        Node next;
        Node(Object data){
            this.data=data;
            this.next = null;
        }
    }
    public static void main(String[] args) {
        LinkedList list1 = new LinkedList();
        list1.add(12);
        list1.add(10);
        list1.add(8);
        list1.add("Java");
        list1.printList();
        
        System.out.print("Size is: ");
        System.out.println(list1.size());
        
        System.out.println("Adding item to the given index..");
        list1.add(4, "Data1");
        list1.printList();
        
        System.out.print("New Size is: ");
        System.out.println(list1.size());
        
        System.out.println("Removing item from the given index..");
        list1.remove(3);
        list1.printList();
        
        System.out.println("Removing given item..");
        list1.remove1("Java");
        list1.printList();
        
         System.out.print("New Size is: ");
        System.out.println(list1.size());
        
        System.out.println("Duplicate list: ");
        list1.duplicate();
        System.out.println("printing reverse duplicate list ");
        list1.duplicateReversed();
    }
}
