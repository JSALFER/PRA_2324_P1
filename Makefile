all: testListArray testNode testListLinked

testListArray: testListArray.cpp ListArray.h List.h
	g++ -o testListArray testListArray.cpp ListArray.h

testNode: testNode.cpp Node.h
	g++ -o testNode testNode.cpp Node.h
    
testListLinked: testListLinked.cpp ListLinked.h List.h
	g++ -o testListLinked testListLinked.cpp ListLinked.h

clean: 
	rm -r *.o all

test: all
	./testListArray
	./testListLinked
	./testNode
