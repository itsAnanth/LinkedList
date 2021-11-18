class Node:
    def __init__(self, value) -> None:
        self.data = value if (value) else None
        self.next = None
        
class LinkedList:
    def __init__(self) -> None:
        self.head = None
        
    def push(self, value):
        node = Node(value)
        if not self.head: 
            self.head = node
        else:
            temp = self.head
            while temp.next != None:
                temp = temp.next
            temp.next = node
            
    def print(self):
        current = self.head
        while current != None:
            print(f'{current.data}')
            current = current.next

    def unshift(self, value):
        node = Node(value)
        if not self.head: self.head = node
        else:
            node.next = self.head
            self.head = node
            
    def toList(self):
        list = []
        current = self.head
        while current != None:
            list.append(current.data)
            current = current.next
        return list
    
    def reverse(self):
        current = self.head
        previous = None
        temp = None
        while current != None:
            temp = current.next
            current.next = previous
            previous = current
            current = temp
        self.head = previous 
            
list = LinkedList()
for i in [10, 2, 6]: list.push(i)
list.unshift(1)
print(list.toList())
list.reverse()
print(list.toList())
