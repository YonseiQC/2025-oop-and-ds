#include <string>
#include <chrono>
#include <iostream>

int main() {
	const auto time_pt_utc = std::chrono::system_clock::now();
	const auto localtime = std::chrono::current_zone()->to_local(time_pt_utc);
	std::cout << std::format("[{:%F %T}]\n", localtime);
	return 0;
}
