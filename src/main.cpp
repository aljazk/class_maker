#include <iostream>
#include <string>
#include <fstream>

std::string toUpper(std::string str){
	std::string u_str;
	for(unsigned int i=0; i<str.size(); i++){
		char c = str[i];
		if (c > 96 && c < 123){
			c -= 32;
		}
		u_str += c;
	}
	return u_str;
}

int main(){
	std::string name_space;
	std::string class_name;
	std::cout << "Enter class name (Namespace::Class): ";
	std::cin >> class_name;
	 std::string::size_type n;
	n = class_name.find("::");
	if((n != std::string::npos)){
		name_space = class_name.substr(0, n);
		class_name = class_name.substr(n+2, class_name.size());
	}
	
	std::string hpp_name;
	hpp_name = class_name + ".hpp";
	std::ofstream myfile (hpp_name.c_str());
	
	if (myfile.is_open()){
		myfile << "#ifndef " << toUpper(class_name) << "_H\n";
		myfile << "#define " << toUpper(class_name) << "_H\n\n";
		if(name_space.size() > 0){
			myfile << "namespace " << name_space << "{\n\n";; 
		}
		myfile << "class " << class_name << "{\n\n";
		myfile << "	public:\n";
		myfile << "		" << class_name << "();\n\n";
		myfile << "};\n\n";
		if(name_space.size() > 0){
			myfile << "}\n\n"; 
		}
		myfile << "#endif";
		myfile.close();
	} else std::cout << "Unable to open file";
	
	std::string cpp_name;
	cpp_name = class_name + ".cpp";
	myfile.open(cpp_name.c_str());
	
	if (myfile.is_open()){
		myfile << "#include \"" << hpp_name << "\"\n\n";
		if(name_space.size() > 0){
			myfile << "using namespace " << name_space << ";\n\n";; 
		}
		myfile << class_name << "::" << class_name << "(){\n\n}";
		myfile.close();
	} else std::cout << "Unable to open file";
	return 0;
}
