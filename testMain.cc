#include "Logger.h"


int main(){

	// create logger
	Logger logger1;
	logger1.configLogger("./test.log", DEBUG);
	// or we can use
	//  Logger logger("./test.log", DEBUG);

	logger1.lerror("this is test error message.");
	logger1.lwarn("this is test warning message.");
	logger1.linfo("this is test info message.");
	logger1.ldebug("this is test debug message.");


	// create Logger
	Logger logger2(DEBUG);
	logger2.lerror("this is test error message to standard out.");
	logger2.lwarn("this is test warning message to standard out.");
	logger2.linfo("this is test info message to standard out.");
	logger2.ldebug("this is test debug message to standard out.");
	return 0;
}

