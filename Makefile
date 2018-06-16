SOURCE = Logger.cc testMain.cc
EXEC = testMain.exe
LOG = test.log
LOGEXIST = $(shell ls | grep ${LOG})


$(EXEC): $(SOURCE)
	g++ -o $(EXEC) $(SOURCE)

clean:
	rm $(EXEC) $(LOGEXIST)

remake: clean $(EXEC)
