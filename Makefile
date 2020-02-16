SHELL = /bin/sh

GCC_STRICT_FLAGS = -pedantic -ansi -W -Wall -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -O2
OTHER_SOURCE = -I./t
OTHER_INCLUDE =
CPPFLAGS = -g -I. $(OTHER_INCLUDE)
CFLAGS = $(GCC_STRICT_FLAGS) 
LDFLAGS =
LDFLAGS_EFENCE = -L/usr/lib -lefence $(LDFLAGS)
#VALGRIND_FLAGS = --verbose --leak-check=full --undef-value-errors=yes --track-origins=yes
VALGRIND_FLAGS = --leak-check=full --undef-value-errors=yes
STAMPER = stamper

INDENT_FLAGS = -TFILE -Tsize_t -Tuint8_t

.PHONY: check vcheck indent stamp clean

TESTS = t/test
EXAMPLES = ex/ex_1

shuffle.o: shuffle.c shuffle.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ shuffle.c

check: shuffle.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c shuffle.o $(LDFLAGS) ) \
	  && ( t/a.out ); \
	done 

check-examples: shuffle.o
	@for i in $(EXAMPLES); \
	do \
	  echo "--------------------"; \
	  echo "Running example $$i"; \
	  ( $(CC) -g $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o ex/a.out $$i.c shuffle.o $(LDFLAGS) ) \
	  && ( valgrind $(VALGRIND_FLAGS) ex/a.out ); \
	done 

vcheck: shuffle.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC) -g $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c shuffle.o $(LDFLAGS) ) \
	  && ( valgrind $(VALGRIND_FLAGS) t/a.out ); \
	done 

echeck: shuffle.o
	@for i in $(TESTS); \
	do \
	  echo "--------------------"; \
	  echo "Running test $$i"; \
	  ( $(CC)    $(CPPFLAGS) $(OTHER_INCLUDE) $(CFLAGS) $(OTHER_SOURCE) \
		-o t/a.out $$i.c shuffle.o $(LDFLAGS_EFENCE) ) \
	  && ( LD_PRELOAD=libefence.so t/a.out ) ; \
	done 

indent:
	@indent $(INDENT_FLAGS) shuffle.c
	@indent $(INDENT_FLAGS) shuffle.h
	@for i in $(TESTS); \
	do \
	  indent $(INDENT_FLAGS) $$i.c; \
	done

stamp:
	@$(STAMPER) shuffle.c
	@$(STAMPER) shuffle.h

clean:
	@/bin/rm -f shuffle.o *.o *~ *.BAK *.bak core.* a.out
	@/bin/rm -f t/*.o t/*~ t/*.BAK t/*.bak t/core.* t/a.out
	@/bin/rm -f ex/*.o ex/*~ ex/*.BAK ex/*.bak ex/core.* ex/a.out

