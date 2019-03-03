class Node:
	def __init__(self, _value=None, _next=None):
		self.value = _value
		self.next = _next
	
class List:
    def __init__(self, _head=None):
		self.head = _head
		self.length = self.calc_length()
		
    def calc_length(self):
		cnt = 0
		pos = self.head
		while pos != None:
			cnt += 1
			pos = pos.next
		return cnt

    def print_lst(self, sep=' '):
	    print("[", end='')
	    if not self.head == None:
			pos = self.head
			while pos.next != None:
				print(pos.value, end=sep)
				pos = pos.next
			print(pos.value, end='')
		print("]", end='')		

#main code
lst = List(Node(2, Node(5, Node(8))))
lst.print_lst(' ')
print("\nThe length is", lst.length)