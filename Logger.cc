#include <iostream>
#include "Logger.h"


// configure Logger. this configure method is used when we want to write log messages to log file.
void Logger::configLogger(std::string input_log_file_path, enum log_level input_level) {
	// set log file path
	log_file_path = input_log_file_path;
	// set log level
	log_level = input_level;

	if(log_file_path != ""){
		// open log file
		out_file.open(log_file_path, std::ios::out|std::ios::app);
		log_to_standard_out = 0;	// write log message to log file, not standard out.
	}else{
		// if log_file_path == "", log message is wrote to standard out
		log_to_standard_out = 1;
	}
}

// configure Logger. this configure method is used when we want to write log messages to standard output.
void Logger::configLogger(enum log_level input_level) {
	// set log level
	log_level = input_level;

	// if log_file_path == "", log message is wrote to standard out
	log_to_standard_out = 1;

}


// constructor
Logger::Logger() {}


// constructor when write to log file.
Logger::Logger(std::string input_log_file_path, enum log_level input_level) {
	configLogger(input_log_file_path, input_level);
}


// constructor when write to standard out.
Logger::Logger(enum log_level input_level) {
	configLogger("", input_level);
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
			if (log_to_standard_out != 1){
				out_file << datetime << " [ERROR] " + message << std::endl;
			}else{
				std::cout << datetime << " [ERROR] " + message << std::endl;
			}

		} else if (write_level == WARNING) {
			if (log_to_standard_out != 1){
				out_file << datetime << " [WARNING] " + message << std::endl;
			}else{
				std::cout << datetime << " [WARNING] " + message << std::endl;
			}

		} else if (write_level == INFO) {
			if (log_to_standard_out != 1){
				out_file << datetime << " [INFO] " + message << std::endl;
			}else{
				std::cout << datetime << " [INFO] " + message << std::endl;
			}

		} else if (write_level == DEBUG) {
			if (log_to_standard_out != 1){
				out_file << datetime << " [DEBUG] " + message << std::endl;
			}else{
				std::cout << datetime << " [DEBUG] " + message << std::endl;
			}
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
