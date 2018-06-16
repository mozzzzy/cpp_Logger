#include "Logger.h"


int main(){

	//Logger logger("./test.log", DEBUG);
	Logger logger;
	logger.configLogger("./test.log", DEBUG);
	logger.lerror("this is test error message.");

	return 0;
}

