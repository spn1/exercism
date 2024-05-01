#include <string>

namespace log_line {
    std::string message(std::string line) {
        return line.substr(line.find(" ") + 1);
    }

    std::string log_level(std::string line) {
        // "[ERROR]: Disk full"
        const int start = line.find("[");
        const int end = line.find("]");
        return line.substr(start + 1, end - (start + 1));
    }

    std::string reformat(std::string line) {
        const int start = line.find("[");
        const int end = line.find("]");
        const int message_start = line.find(" ");
        const std::string message = line.substr(message_start + 1);
        const std::string level = line.substr(start + 1, end - (start + 1));
        const std::string reformatted_line = message + " (" + level + ")";

        return reformatted_line;
    }
}
