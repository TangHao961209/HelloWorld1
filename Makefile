PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
#
#OBJS = HelloWorld.o
#CFLAGS=-DTEST_ADD -DCat_ADD
#ifeq ($(BUILD_MODE),debug)
#	CFLAGS += -g
#else ifeq ($(BUILD_MODE),run)
#	CFLAGS += -O2
#else
#	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
#endif
#
#all:	HelloWorld
#
#HelloWorld:	$(OBJS)
#	$(CXX) -o $@ $^
#
#%.o:	$(PROJECT_ROOT)%.cpp 
#	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<
#
#%.o:	$(PROJECT_ROOT)%.c
#	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
#
#clean:
#	rm -fr HelloWorld $(OBJS)


OBJS = HelloWorld.o   pthread_test.o

CFLAGS=-DTEST_ADD -DCat_ADD
ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else
	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif
    CFLAGS +=  -fpermissive

HelloWorld:	$(OBJS)
	$(CXX) -o $@ $^ -lpthread
$(OBJS):%.o: $(PROJECT_ROOT)%.cpp  $(PROJECT_ROOT)%.h 	
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<  -lpthread
clean:
	rm -fr HelloWorld $(OBJS)	

