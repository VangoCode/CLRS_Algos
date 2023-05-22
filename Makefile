all :
	+$(MAKE) -C DynamicArray
	+$(MAKE) -C Heap
	+$(MAKE) -C PriorityQueue

clean:
	+$(MAKE) -C DynamicArray clean
	+$(MAKE) -C Heap clean
	+$(MAKE) -C PriorityQueue clean