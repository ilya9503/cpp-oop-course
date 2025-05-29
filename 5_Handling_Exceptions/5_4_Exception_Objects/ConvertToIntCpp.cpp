#include <iostream>
#include <string>

class ExceptionConvert{
private:
	std::string msg;
public:
	ExceptionConvert(std::string s): msg(s)
	{	}
	const std::string& to_msg(){
		return msg;
	}
};

class ConvertToInt{
private:
	std::string match{"0123456789+-."}; 
	void check(std::string &s){
		for(char ch : s)
			if(match.find(ch) == std::string::npos)
				throw std::exception() ;
	}
public:
	int operator()(std::string s){
		int n{};
		try{
			check(s);
			n = std::stoi(s); 
		}
		catch(...){
			throw ExceptionConvert("Conversion error");
		}
		return n;
	}
};

int main()
{
    std::string digit;
    getline(std::cin, digit);

    const char* str = digit.c_str(); // массив символов char с прочитанной строкой

	ConvertToInt str_to_int;
	try{
		std::cout << str_to_int(digit);
	}
	catch(ExceptionConvert &ex){
		std::cout << ex.to_msg();
	}

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}