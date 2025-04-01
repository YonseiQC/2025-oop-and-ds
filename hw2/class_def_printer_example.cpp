#include <algorithm>
#include <array>
#include <iostream>
#include <format>

#include "AbstractClassDefPrinter.hpp"

std::string to_camel_case(std::string str) {
	std::string camel;
	std::transform(std::begin(str), std::end(str), 
			std::begin(str), 
			[](char c) {
				return static_cast<char>(std::tolower(c)); 
			});
	bool toUpper = false;

	for (char ch : str) {
		if (ch == '_') {
			toUpper = true; // Next character should be uppercase
		} else {
			if (toUpper) {
				camel += std::toupper(ch);
				toUpper = false;
			} else {
				camel += ch;
			}
		}
	}

	return camel;
}

class JavaClassDefPrinter : public AbstractClassDefPrinter {
private:
	std::string class_begin_statement(const std::string& class_name) const override {
		return std::format("public class {} {{", class_name);
	}

	std::string class_end_statement() const override {
		return std::format("}}");
	}

	std::string variable_decl_statement(const std::pair<DataType, std::string>& variable) const override {
		const auto [data_type, var_name] = variable;
		std::string type;
		switch(data_type) {
		case DataType::INT:
			type = "int";
			break;
		case DataType::FLOAT:
			type = "double";
			break;
		case DataType::STR:
			type = "String";
			break;
		}
		return std::format("public {} {};", type, to_camel_case(var_name));
	}
};


int main() {
	// this is test code
	JavaClassDefPrinter java_class_def_printer;

	ClassDef my_class;
	my_class.class_name = "DriversLicense";
	my_class.variables.emplace_back(DataType::STR, "DRIVER_NAME");
	my_class.variables.emplace_back(DataType::INT, "DRIVER_AGE");
	my_class.variables.emplace_back(DataType::FLOAT, "LEFT_EYE_VISION");
	my_class.variables.emplace_back(DataType::FLOAT, "RIGHT_EYE_VISION");

	std::cout << java_class_def_printer.print_class_def(my_class) << '\n';
	return 0;
}
