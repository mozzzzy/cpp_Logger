#include "Logger.h"


// configure Logger
void Logger::configLogger(std::string input_log_file_path, enum log_level input_level) {
	// set log file path
	log_file_path = input_log_file_path;
	// set log level
	log_level = input_level;
	// open log file
	out_file.open(log_file_path, std::ios::out|std::ios::app);
}


// constructor
Logger::Logger() {}


// constructor
Logger::Logger(std::string input_log_file_path, enum log_level input_level) {
	configLogger(input_log_file_path, input_level);
}


// destructor
Logger::~Logger() {
	out_file.close();	
}


// base method to write message to file.
// this method is used by lerror(log error), lwarn(log warning), linfo(log info), ldebug(log debug) function.
//   std::string message : log message.
//   enum log_level write_level : write level of this log message.
void Logger::printToFile(std::string message, enum log_level write_level) {
	if (log_level > write_level ) {	// if enable to write

		// get timestamp
		time_t timer;
		struct tm* tm;
		int size = 20;
		char datetime[size];
		timer = time(NULL);
		tm = localtime(&timer);
		strftime(datetime, size, "%Y-%m-%d %H:%M:%S",tm );
		
		// write log message to file with timestamp and log level 
		if (write_level == ERROR) {
			out_file << datetime << " [ERROR] " + message << std::endl;
		} else if (write_level == WARNING) {
			out_file << datetime << " [WARNING] " + message << std::endl;
		} else if (write_level == INFO) {
			out_file << datetime << " [INFO] " + message << std::endl;
		} else if (write_level == DEBUG) {
			out_file << datetime << " [DEBUG] " + message << std::endl;
		}
	}
}


void Logger::lerror(std::string message) {
	printToFile(message, ERROR);
}


void Logger::lwarn(std::string message) {
	printToFile(message, WARNING);
}


void Logger::linfo(std::string message) {
	printToFile(message, INFO);
}


void Logger::ldebug(std::string message) {
	printToFile(message, DEBUG);
}
