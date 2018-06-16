#include <fstream>
#include <time.h>

enum log_level {
	ERROR,
	WARNING,
	INFO,
	DEBUG
};


class Logger {

	private:
		// field
		int log_level;
		std::string log_file_path;
		std::ofstream out_file;
		int log_to_standard_out;

		// method
		void printToFile(std::string message, enum log_level write_level);

	public:
		// method
		Logger();	// constructor
		Logger(std::string log_file_path, enum log_level level);	// constructor
		Logger(enum log_level input_level);	// constructor
		~Logger();	// destructor
		void configLogger(std::string input_log_file_path, enum log_level input_level);
		void configLogger(enum log_level input_level);
		void lerror(std::string message);
		void lwarn(std::string message);
		void linfo(std::string message);
		void ldebug(std::string message);

};
