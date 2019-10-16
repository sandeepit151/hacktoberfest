#Represent a node of ternary tree    
class Node:    
    def __init__(self,data):    
        self.data = data;    
        self.left = None;    
        self.middle = None;    
        self.right = None;    
            
class TernaryTreeToDLL:    
    def __init__(self):    
        #Represent the root of ternary tree    
        self.root = None;    
        #Represent the head and tail of the doubly linked list    
        self.head = None;    
        self.tail = None;    
            
    #convertTernaryToDLL() will convert the given ternary tree to corresponding doubly linked list    
    def convertTernaryToDLL(self, node):    
        #Checks whether node is None    
        if(node == None):    
            return;    
                
        #Keep three pointers to all three children    
        left = node.left;    
        middle = node.middle;    
        right = node.right;    
            
        #If list is empty then, add node as head of the list    
        if(self.head == None):    
            #Both head and tail will point to node    
            self.head = self.tail = node;    
            node.middle = None;    
            #head's left will point to None    
            self.head.left = None;    
            #tail's right will point to None, as it is the last node of the list    
            self.tail.right = None;    
        #Otherwise, add node to the end of the list    
        else:    
            #node will be added after tail such that tail's right will point to node    
            self.tail.right = node;    
            #node's left will point to tail    
            node.left = self.tail;    
            node.middle = None;    
            #node will become new tail    
            self.tail = node;    
            #As it is last node, tail's right will point to None    
            self.tail.right = None;    
                
        #Add left child of current node to the list    
        self.convertTernaryToDLL(left);    
        #Then, add middle child of current node to the list    
        self.convertTernaryToDLL(middle);    
        #Then, add right child of current node to the list    
        self.convertTernaryToDLL(right);    
        
    #displayDLL() will print out the nodes of the list    
    def displayDLL(self):    
        #Node current will point to head    
        current = self.head;    
        if(self.head == None):    
            print("List is empty");    
            return;    
        print("Nodes of generated doubly linked list: ");    
        while(current != None):    
            #Prints each node by incrementing pointer.    
            print(current.data),    
            current = current.right;    
                
tree = TernaryTreeToDLL();    
#Add nodes to the ternary tree    
tree.root = Node(5);    
tree.root.left = Node(10);    
tree.root.middle = Node(12);    
tree.root.right = Node(15);    
tree.root.left.left = Node(20);    
tree.root.left.middle = Node(40);    
tree.root.left.right = Node(50);    
tree.root.middle.left = Node(24);    
tree.root.middle.middle = Node(36);    
tree.root.middle.right = Node(48);    
tree.root.right.left = Node(30);    
tree.root.right.middle = Node(45);    
tree.root.right.right = Node(60);    
     
#Converts the given ternary tree to doubly linked list    
tree.convertTernaryToDLL(tree.root);    
     
#Displays the nodes present in the list    
tree.displayDLL();  