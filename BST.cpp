/*Given a Binary Search Tree (BST), write a code for:
(7) int count(Node *) -> counting all the nodes in the BST
(8) int rangeSearch(int k1, int k2) ->range search: given two values k1 and k2, print all the elements (or keys) x in the BST such that k1 <= x <= k2. Also count the number of elements in the range from k1 to k2 and returns it.
(9) int height(Node *) -> Finds the height of the BST.*/
#include<iostream>
using namespace std;
//class node
class node {
      public:
      int data;
      node*parent;
      //filial nodes
      node*left;
      node*right;
      //default constructor
      node(int value) { 
            parent = NULL;
            left = NULL;
            right = NULL;
            data = value;
      }
};
//class BST for the tree
class BST {
      public:
      //roooooooooooooot
      node*root; 
      //default constructor
      BST() {
           root = NULL;
      }
      //1. insert()
      void insert(int value) { //dummy function
           insert(root, value); //sets current = root
           }
      void insert(node*current, int value) {
           if(root == NULL) { 
                   root = new node(value);
           }
           else {
                   if(value < current -> data) {
                            if(current -> left == NULL) {
                                       current -> left = new node(value);
                                       current -> left -> parent = current;
                            }
                            else {
                                       insert(current -> left, value);
                            }
                   }
                   else {
                            if(current -> right == NULL) {
                                       current -> right = new node(value);
                                       current -> right -> parent = current;
                            }
                            else {
                                       insert(current -> right, value);
                            }
                   }
           }
      }
      //2. display()
      void display() { //dummy function
           display(root); //sets current = root
           cout << endl;
      }
      void display(node*current) {
           if(current == NULL) {
                      return;
           }
           //display left
           display(current -> left);
           //display current
           cout << current -> data << ", ";
           //display right
           display(current -> right);
      }
      //3. search()
      node*search(int value) { //dummy function
           return search(root, value); //sets current = root
      }
      node*search(node*current, int value) {
           if(current == NULL || current -> data == value) {
                      return current;
           }
           else {
                      if(value < current -> data) {
                               return search(current -> left, value); //go left
                      }
                      else {
                               if(value > current -> data) {
                                        return search(current -> right, value); //go right
                               }
                      }
           }
      }
      //2D display
      void print2D() { //dummy function
           print2D(root, 0); //sets current = root 
      }  
      void print2D(node*current, int spaces) {  
           if(current == NULL) {
                       return;  
           }
           spaces += 5; 
           print2D(current -> right, spaces); 
           cout << endl;
           for(int i = 5; i < spaces; i++) {
                     cout << " ";
           }
           cout << current -> data;
           print2D(current -> left, spaces);
      }
      //4.node*find_min(node*)
      int find_min(int value) {
          node*current = search(root, value);
          node*min = find_min(current);
          return min -> data;
      }
      node*find_min(node*current) {
           if(current == NULL) {
                      cout << "No minimum." << endl;
                      return NULL;
           }
           else { 
                      if(current -> left == NULL) {
                                 cout << current -> data << endl;
                                 return current;
                      }
                      else {
                                 find_min(current -> left);
                      }
           }
      }
      //5.void replace_At_Parent(node*A, node*B)
      void replace_At_Parent(node*A, node*B) {
           if(A -> parent -> left == A) {
                A -> parent -> left = B;
           }
           else {
                if(A -> parent -> right == A) {
                     A -> parent -> right = B;
                }
                else {
                     if(B != NULL) {
                          B -> parent = A -> parent;
                     }
                     else {
                          A -> parent = NULL;
                     }
                }
           }
      }
      //6.void deleteNode(int value)
      void deleteNode(int value) {
           node*current = search(root, value);
           if(current == NULL) {
                      cout << "Cannot delete." << endl;
           }
           else {
                      if(current -> left == NULL) {
                                 replace_At_Parent(current, current -> right);
                      }
                      else {
                                 if(current -> right == NULL) {
                                            replace_At_Parent(current, current -> left);
                                 }
                                 else {
                                            node*temp = find_min(current -> right);
                                            current -> data = temp -> data;
                                            replace_At_Parent(temp, NULL);
                                            delete temp;
                                 }
                      }
           }
      }
      //7.int count(node*)
      int count() { //dummy function
          return count(root); //sets current = root
      }
      int count(node*current) {
          if(current == NULL) {
                     return 0;
          }
          else {
                     return count(current -> left) + 1 + count(current -> right);
          }
      }
      //8.int rangeSearch(int k1, int k2)
      int rangeSearch(int k1, int k2) { //dummy function
          return rangeSearch(root, k1, k2); //sets current = root
      }
      int rangeSearch(node*current, int k1, int k2) {
          if(current == NULL) {
                     return 0;
          }
          if(current -> data == k2 && current -> data == k1) {
                     return 1;
          }
          if(current -> data <= k2 && current -> data >= k1) {
                     cout << current -> data << ", ";
                     return rangeSearch(current -> left, k1, k2) + 1 + rangeSearch(current -> right, k1, k2);
          }
          else {
                     if(current -> data < k2) {
	        rangeSearch(current -> right, k1, k2);
                     }
                     else {
                                rangeSearch(current -> left, k1, k2);
                     }
          }
      }
      //9.int height(node*)
      int height() { //dummy function
          return height(root); //sets current = root
      }
      int height(node*current) {
          if(current == NULL) {
                     return 0;
          }
          else {
                     int leftheight = height(current -> left);
                     int rightheight = height(current -> right);
                     if(leftheight > rightheight) {
                                   return leftheight + 1;
                     }
                     else {
                                   return rightheight + 1;
                     }
          }
      }
};
//main function
int main() {
    BST NMB48;
    NMB48.insert(5);
    NMB48.insert(2);
    NMB48.insert(8);
    NMB48.insert(1);
    NMB48.insert(6);
    NMB48.insert(4);
    NMB48.insert(7);
    NMB48.insert(3);
    cout << "Binary Search Tree with predefined elements: " << endl;
    NMB48.display();
    cout << "Search for element 3: " << endl;
    cout << NMB48.search(3) -> data << endl;
    cout << NMB48.search(3) << endl;
    cout << "2D display of the tree: " << endl;
    NMB48.print2D();
    cout << endl;
    cout << "Minimum of the subtree of element 2: ";
    NMB48.find_min(2);
    cout << "Number of elements in the tree: " << NMB48.count() << endl;
    NMB48.deleteNode(4);
    cout << "2D display of the tree after deleting element 4: " << endl;
    NMB48.print2D();
    cout << endl;
    cout << "Number of elements in the tree: " << NMB48.count() << endl;
    cout << "Height of the tree: " << NMB48.height() << endl;
    cout << "Elements between elements 2 and 7: " << NMB48.rangeSearch(2,7) << endl;
    return 0;
}
