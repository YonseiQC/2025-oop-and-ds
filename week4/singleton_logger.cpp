#include <fstream>
#include <chrono>
#include <format>

class Logger {
private:
	std::ofstream fout_;
	Logger() : fout_("log.txt") {

	}
	~Logger() {
		fout_.close();
	}
public:
	static Logger& get_instance() {
		static Logger logger;
		return logger;
	}

	void print_message(const std::string& message) {
		const auto time_pt_utc = std::chrono::system_clock::now();
		const auto localtime = std::chrono::current_zone()->to_local(time_pt_utc);
		std::string datetime = std::format("[{:%F %T}]\n", localtime);
		fout_ << datetime << message << "\n";
	}
};

int main() {
	Logger& logger = Logger::get_instance();

	logger.print_message("Program started.");
	logger.print_message("Program ended.");
	return 0;
}
