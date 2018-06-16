#include "Logger.h"


int main(){

	// create logger
	Logger logger1;
	logger1.configLogger("./test.log", DEBUG);
	// or we can use
	//  Logger logger("./test.log", DEBUG);

	logger1.lerror("this is test error message.");


	// create Logger
	Logger logger2(DEBUG);
	logger2.lerror("this is test error message to standard out.");
	return 0;
}

