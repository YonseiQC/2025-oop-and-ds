#include <sstream>
#include <string>
#include <utility>
#include <vector>

enum class DataType {INT, FLOAT, STR};

struct ClassDef {
	std::string class_name;
	std::vector<std::pair<DataType, std::string>> variables;
};

class AbstractClassDefPrinter {
private:
	virtual std::string class_begin_statement(const std::string& class_name) const = 0;
	virtual std::string class_end_statement() const = 0;
	virtual std::string variable_decl_statement(const std::pair<DataType, std::string>& variable) const = 0;

public:
	inline std::string print_class_def(const ClassDef& class_def) {
		std::ostringstream ss;
		ss << class_begin_statement(class_def.class_name) << '\n';
	
		for(const auto& variable: class_def.variables) {
			ss << "\t" << variable_decl_statement(variable) << '\n';
		}

		ss << class_end_statement();

		return ss.str();
	}
};
