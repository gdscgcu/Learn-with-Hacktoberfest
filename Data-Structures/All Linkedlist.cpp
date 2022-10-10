#include<iostream>
using namespace std;
class Node{
public:
	int key;
	int data;
	Node* next;

	// default constructor
	Node(){
		key = 0;
		data = 0;
		next = NULL;
	}
	Node(int k, int d){
		key = k;
		data = d;
	}
};

class SinglyLinkedList{
public:
	Node* head;
	SinglyLinkedList(){			// default constructor
		head = NULL;
	}

	// parameterized constructo it will pass an argurment and it will store  that arguement in the head variabl
	SinglyLinkedList(Node* n){
		head = n;
	}

	//functions first we will check if  node exist or not
	Node* NodeExists(int k){	// we need this function it will check it node exist or not
		// this function helps us in the rest of the functions.
		Node*temp = NULL;
		Node* ptr = head;

		while (ptr != NULL){
			if (ptr->key == k){
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

	// appending node function
	void appendNode(Node* n){
		if (NodeExists(n->key) != NULL){
			cout << "Node already exist with key value: " << n->key << "append another one\n";
		}
		else
		if (head == NULL){	//if it will check if there is no actual node it will create
			head = n;
			cout << "Node Appended Successfully\n";
		}
		else{		// it will iterate till the last then it will create one
			Node* ptr = head;
			while (ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr->next = n;
			cout << "Node Appended\n";
		}
	}

	//Prepend node operation it wil prepend at the beggining
	void PrependNode(Node* n){
		if (NodeExists(n->key) != NULL){
			cout << "Node already exist with key value: " << n->key << "append another one\n";
		}
		else{
			n->next = head;			// it will store the addresss of old head and linked with that node
			head = n;				// here we will make the new node as a head
			cout << "Node Prepended Successfully\n";
		}
	}


	// insert a node after a particular node in the list
	void InsertNodeAfter(int k, Node*n)// the k represent the key value of after node and d will be the data of new node
	{
		Node* ptr = NodeExists(k);
		if (ptr == NULL){  // it means no node exist with k particular node
			cout << "No Node Exist with the key value" << k;
		}
		else {
			if (NodeExists(n->key) != NULL){  // it will check the new value if it matches with the old one
				cout << "Node already exist with key value " << n->key << " insert another one\n";
			}
			else{		// here we will linking
				n->next = ptr->next; // n(4 is in case) of next has to store the address of ptr(ptr is 2 in case) of next 
				ptr->next = n; // here we will connect n which 4 with 4 which is n;
				cout << "Node Inserted Successfully" << endl;
			}
		}
	}

	// Update node by key
	void UpdateNodeByKey(int k, int d)
	{
		Node*ptr = NodeExists(k);
		if (ptr != NULL){
			ptr->data = d;
			cout << "Data Updated Successfully\n";
		}
		else{
			cout << "Node Doesn't Exist with key value: " << k << endl;
		}
	}

	// Deleting a particular node
	void DeleteNodeByKey(int k){
		//first we will check if there is no node in the linked list
		if (head == NULL){
			cout << "The linked list is already Empty\n";
		}
		else if (head != NULL){
			if (head->key == k){
				head = head->next;
				cout << "Node Unlinked with the " << k << endl;
			}
			else{
				Node* temp = NULL;
				Node* prevptr = head;
				Node* currentptr = head->next;
				while (currentptr != NULL){
					if (currentptr->key == k){
						temp = currentptr;
						currentptr = NULL;
					}
					else
					{
						prevptr = prevptr->next;
						currentptr = currentptr->next;
					}
				}
				if (temp != NULL){
					prevptr->next = temp->next;  // it means first node is = to the third one
					cout << "Node Unlocked with key value: " << k << endl;
				}
				else{
					cout << "Node Doesn't Exist with key value: " << k << endl;
				}
			}
		}
	}


	// printing the linked list
	void PrintLinkedList(){
		if (head == NULL){
			cout << "No Node Exist int the linked list\n";
		}
		else
		{
			cout << "The linked list values are:" << endl;
			Node* temp = head;
			while (temp != NULL){
				cout << "(" << temp->key << "," << temp->data << ") -->";
				temp = temp->next;
			}
		}
	}

	// Other Extra Function for The variety of understanding

};

int main(){
	SinglyLinkedList s1;
	int option;
	int key1, k1, data1;

	do
	{
		cout << "What operation do you want to perform" << endl;
		cout << "Select one option but Enter [0] to exit the program" << endl;
		cout << "1. Append Node()" << endl;
		cout << "2. PrePend Noe()" << endl;
		cout << "3. Insert Node After()" << endl;
		cout << "4. Delete Node By Key()" << endl;
		cout << "5. Update Node By Key()" << endl;
		cout << "6. Print the Entire list()" << endl;
		cout << "7. Clear the Screen()" << endl;

		cin >> option;
		Node* n1 = new Node();

		//if we use static memory concept then after execution of loop once the varival will lost.
		switch (option)
		{
		case 1:
			cout << "\n\t Append Node Operation\n";
			cout << "\t Enter key and data of the node to be appended\n";
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s1.appendNode(n1);
			break;
		case 2:
			cout << "\n\t Prepend Node Operation\n";
			cout << "\t Enter key and data of the node to be Prepended\n";
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s1.PrependNode(n1);
			break;
		case 3:
			cout << "\n\t Insert After Node Operation\n";
			cout << "\n\t Enter key of Existed Node:: and Data of the new Node which you want to insert\n";
			cin >> k1;
			cout << "Now Enter the Key and data of the new Node\n";
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s1.InsertNodeAfter(k1, n1);
			break;
		case 4:
			cout << "\n\t Delete node by key operation\n";
			cout << "\n\t Enter Key of the node to be deleted\n";
			cin >> k1;
			s1.DeleteNodeByKey(k1);
			break;
		case 5:
			cout << "\n\t Update by the key Operation\n";
			cout << "\n\t Enter the key of a node to be Updated\n";
			cin >> k1;
			cin >> data1;
			s1.UpdateNodeByKey(k1, data1);
			break;
		case 6:
			cout << "\n\t Print the Entire List Operation\n";
			s1.PrintLinkedList();
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Please Enter a valid Option\n";
		}
	} while (option != 0);


	return 0;
}


// Doubly Linked list

#include<iostream>

using namespace std;

class Node {
  public:
    int key;
  int data;
  Node * next;
  Node * previous;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
    previous = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class DoublyLinkedList {

  public:
    Node * head;

  DoublyLinkedList() {
    head = NULL;
  }
  DoublyLinkedList(Node * n) {
    head = n;
  }

  // 1. CHeck if node exists using key value

  Node * nodeExists(int k) {
    Node * temp = NULL;
    Node * ptr = head;

    while (ptr != NULL) {
      if (ptr-> key == k) {
        temp = ptr;
      }
      ptr = ptr-> next;
    }

    return temp;
  }

  // 2. Append a node to the list

  void appendNode(Node * n) {
    if (nodeExists(n-> key) != NULL) {
      cout << "Node Already exists with key value : " << n-> key << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Appended as Head Node" << endl;
      } else {
        Node * ptr = head;
        while (ptr-> next != NULL) {
          ptr = ptr-> next;
        }
        ptr-> next = n;
        n-> previous = ptr;
        cout << "Node Appended" << endl;
      }
    }
  }

  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node * n) {
    if (nodeExists(n-> key) != NULL) {
      cout << "Node Already exists with key value : " << n-> key << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Prepended as Head Node" << endl;
      } else {
        head-> previous = n;
        n-> next = head;
        head = n;
        cout << "Node Prepended" << endl;
      }

    }
  }

  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {
      if (nodeExists(n-> key) != NULL) {
        cout << "Node Already exists with key value : " << n-> key << ". Append another node with different Key value" << endl;
      } else {
        Node * nextNode = ptr-> next;
        // inserting at the end
        if (nextNode == NULL) {
          ptr-> next = n;
          n-> previous = ptr;
          cout << "Node Inserted at the END" << endl;
        }

        //inserting in between
        else {
          n-> next = nextNode;
          nextNode-> previous = n;
          n-> previous = ptr;
          ptr-> next = n;

          cout << "Node Inserted in Between" << endl;

        }

      }
    }
  }

  // 5. Delete node by unique key. Basically De-Link not delete
  void deleteNodeByKey(int k) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {

      if (head-> key == k) {
        head = head-> next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      } else {
        Node * nextNode = ptr-> next;
        Node * prevNode = ptr-> previous;
        // deleting at the end
        if (nextNode == NULL) {

          prevNode-> next = NULL;
          cout << "Node Deleted at the END" << endl;
        }

        //deleting in between
        else {
          prevNode-> next = nextNode;
          nextNode-> previous = prevNode;
          cout << "Node Deleted in Between" << endl;

        }
      }
    }
  }

  // 6th update node
  void updateNodeByKey(int k, int d) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr-> data = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }

  }

  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Doubly Linked List";
    } else {
      cout << endl << "Doubly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp-> key << "," << temp-> data << ") <--> ";
        temp = temp-> next;
      }
    }

  }

};

int main() {

  DoublyLinkedList obj;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1-> key = key1;
      n1-> data = data1;
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1-> key = key1;
      n1-> data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1-> key = key1;
      n1-> data = data1;

      obj.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);

      break;
    case 6:
      obj.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}

//Circular Linked list
#include<iostream>
using namespace std;

class Node {
  public:
    int key;
  int data;
  Node * next;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class CircularLinkedList {
  public:
    Node * head;

  CircularLinkedList() {
    head = NULL;
  }

  // 1. CHeck if node exists using key value
  Node * nodeExists(int k) {

    Node * temp = NULL;
    Node * ptr = head;

    if (ptr == NULL) {
      return temp;
    } else {
      do {
        if (ptr - > key == k) {
          temp = ptr;
        }
        ptr = ptr - > next;

      } while (ptr != head);
      return temp;
    }

    //return temp;
  }

  // 2. Append a node to the list
  void appendNode(Node * new_node) {
    if (nodeExists(new_node - > key) != NULL) {
      cout << "Node Already exists with key value : " <<
        new_node - > key <<
        ". Append another node with different Key value" <<
        endl;
    } else {
      if (head == NULL) {
        head = new_node;
        new_node - > next = head;
        cout << "Node Appended at first Head position" << endl;
      } else {
        Node * ptr = head;
        while (ptr - > next != head) {
          ptr = ptr - > next;
        }
        ptr - > next = new_node;
        new_node - > next = head;
        cout << "Node Appended" << endl;
      }
    }

  }
  // 3. Prepend Node - Attach a node at the start
  void prependNode(Node * new_node) {
    if (nodeExists(new_node - > key) != NULL) {
      cout << "Node Already exists with key value : " <<
        new_node - > key <<
        ". Append another node with different Key value" <<
        endl;
    } else {
      if (head == NULL) {
        head = new_node;
        new_node - > next = head;
        cout << "Node Prepended at first Head position" << endl;
      } else {
        Node * ptr = head;
        while (ptr - > next != head) {
          ptr = ptr - > next;
        }

        ptr - > next = new_node;
        new_node - > next = head;
        head = new_node;
        cout << "Node Prepended" << endl;
      }

    }
  }

  // 4. Insert a Node after a particular node in the list
  void insertNodeAfter(int k, Node * new_node) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value OF: " << k << endl;
    } else {
      if (nodeExists(new_node - > key) != NULL) {
        cout << "Node Already exists with key value : " <<
          new_node - > key <<
          ". Append another node with different Key value" <<
          endl;
      } else {
        if (ptr - > next == head) {
          new_node - > next = head;
          ptr - > next = new_node;
          cout << "Node Inserted at the End" << endl;
        } else {
          new_node - > next = ptr - > next;
          ptr - > next = new_node;
          cout << "Node Inserted in between" << endl;
        }

      }
    }
  }

  // 5. Delete node by unique key
  void deleteNodeByKey(int k) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value OF : " << k <<
        endl;
    } else {

      if (ptr == head) {
        if (head - > next == NULL) {
          head = NULL;
          cout << "Head node Unlinked... List Empty";
        } else {
          Node * ptr1 = head;
          while (ptr1 - > next != head) {
            ptr1 = ptr1 - > next;
          }
          ptr1 - > next = head - > next;
          head = head - > next;
          cout << "Node UNLINKED with keys value : " << k << endl;
        }
      } else {
        Node * temp = NULL;
        Node * prevptr = head;
        Node * currentptr = head - > next;
        while (currentptr != NULL) {
          if (currentptr - > key == k) {
            temp = currentptr;
            currentptr = NULL;
          } else {
            prevptr = prevptr - > next;
            currentptr = currentptr - > next;
          }
        }

        prevptr - > next = temp - > next;
        cout << "Node UNLINKED with keys value : " << k << endl;

      }

    }

  }
  // 6th update node
  void updateNodeByKey(int k, int new_data) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr - > data = new_data;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }

  }

  // 7th printing
  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Circular Linked List";
    } else {
      cout << endl << "head address : " << head << endl;
      cout << "Circular Linked List Values : " << endl;

      Node * temp = head;

      do {
        cout << "(" << temp - > key << "," << temp - > data << "," << temp - > next << ") --> ";
        temp = temp - > next;
      } while (temp != head);
    }

  }

};

int main() {

  CircularLinkedList obj;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 - > key = key1;
      n1 - > data = data1;
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 - > key = key1;
      n1 - > data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 - > key = key1;
      n1 - > data = data1;

      obj.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);

      break;
    case 6:
      obj.printList();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}