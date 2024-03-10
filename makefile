myContacts: contactsA2.o createContactA2.o readContactsA2.o searchContactsA2.o
	gcc createContactA2.o contactsA2.o readContactsA2.o searchContactsA2.o -o bin/myContacts
contactsA2.o: src/contactsA2.c include/givenA2.h
	gcc -Wall -std=c99 -c src/contactsA2.c -lm
createContactA2.o: src/createContactA2.c include/givenA2.h
	gcc -Wall -std=c99 -c src/createContactA2.c -lm
readContactsA2.o: src/readContactsA2.c include/givenA2.h
	gcc -Wall -std=c99 -c src/readContactsA2.c -lm
searchContactsA2.o: src/searchContactsA2.c include/givenA2.h
	gcc -Wall -std=c99 -c src/searchContactsA2.c -lm
clean:
	rm *.o bin/myContacts
