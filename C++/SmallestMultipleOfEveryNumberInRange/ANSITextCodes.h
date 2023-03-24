#pragma once
#include <iostream>
#include <iomanip>
#include <string>

std::string reset()
{
	return "\u001b[0m";
}

std::string bold()
{
	return "\u001b[1m";
}
std::string bold(std::string text)
{
	return "\u001b[1m" + text + "\u001b[0m";
}

std::string underline()
{
	return "\u001b[4m";
}
std::string underline(std::string text)
{
	return "\u001b[4m" + text + "\u001b[0m";
}

std::string reverse()
{
	return "\u001b[7m";
}
std::string reverse(std::string text)
{
	return "\u001b[7m" + text + "\u001b[0m";
}

std::string black(bool bright, bool highlight)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[40";
	else
		code = "\u001b[30";
	
	if(bright)
		code += ";1";
	
	code += "m";
	return code;
}
std::string black(bool bright, bool highlight, std::string text)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[40";
	else
		code = "\u001b[30";
	
	if(bright)
		code += ";1";
	
	code += "m";
	
	code += text + "\u001b[0m";
	return code;
}

std::string red(bool bright, bool highlight)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[41";
	else
		code = "\u001b[31";
	
	if(bright)
		code += ";1";
	
	code += "m";
	return code;
}
std::string red(bool bright, bool highlight, std::string text)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[41";
	else
		code = "\u001b[31";
	
	if(bright)
		code += ";1";
	
	code += "m";
	
	code += text + "\u001b[0m";
	return code;
}

std::string green(bool bright, bool highlight)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[42";
	else
		code = "\u001b[32";
	
	if(bright)
		code += ";1";
	
	code += "m";
	return code;
}
std::string green(bool bright, bool highlight, std::string text)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[42";
	else
		code = "\u001b[32";
	
	if(bright)
		code += ";1";
	
	code += "m";
	
	code += text + "\u001b[0m";
	return code;
}

std::string yellow(bool bright, bool highlight)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[43";
	else
		code = "\u001b[33";
	
	if(bright)
		code += ";1";
	
	code += "m";
	return code;
}
std::string yellow(bool bright, bool highlight, std::string text)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[43";
	else
		code = "\u001b[33";
	
	if(bright)
		code += ";1";
	
	code += "m";
	
	code += text + "\u001b[0m";
	return code;
}

std::string blue(bool bright, bool highlight)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[44";
	else
		code = "\u001b[34";
	
	if(bright)
		code += ";1";
	
	code += "m";
	return code;
}
std::string blue(bool bright, bool highlight, std::string text)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[44";
	else
		code = "\u001b[34";
	
	if(bright)
		code += ";1";
	
	code += "m";
	
	code += text + "\u001b[0m";
	return code;
}

std::string magenta(bool bright, bool highlight)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[45";
	else
		code = "\u001b[35";
	
	if(bright)
		code += ";1";
	
	code += "m";
	return code;
}
std::string magenta(bool bright, bool highlight, std::string text)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[45";
	else
		code = "\u001b[35";
	
	if(bright)
		code += ";1";
	
	code += "m";
	
	code += text + "\u001b[0m";
	return code;
}

std::string cyan(bool bright, bool highlight)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[46";
	else
		code = "\u001b[36";
	
	if(bright)
		code += ";1";
	
	code += "m";
	return code;
}
std::string cyan(bool bright, bool highlight, std::string text)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[46";
	else
		code = "\u001b[36";
	
	if(bright)
		code += ";1";
	
	code += "m";
	
	code += text + "\u001b[0m";
	return code;
}

std::string white(bool bright, bool highlight)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[47";
	else
		code = "\u001b[37";
	
	if(bright)
		code += ";1";
	
	code += "m";
	return code;
}
std::string white(bool bright, bool highlight, std::string text)
{
	std::string code = "";
	if(highlight)
		code = "\u001b[47";
	else
		code = "\u001b[37";
	
	if(bright)
		code += ";1";
	
	code += "m";
	
	code += text + "\u001b[0m";
	return code;
}

std::string customColor(bool highlight, int color)
{
	//implment some form of input checking
	if(color < 0 || color > 255)
	{
		std::cerr<<"Error in using the \u001b[33mcustomColor(bool highlight, \u001b[31mint color\u001b[33m)\u001b[0m method, please make sure that the color value is an integer between 0-255 inclusive"<<std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::string code = "\033[";
	if(highlight)
		code += std::to_string(48);
	else
		code += std::to_string(38);
	code += ";5;" + std::to_string(color) + 'm';
	return code;
}
std::string customColor(bool highlight, int color, std::string text)
{
	//implment some form of input checking
	if(color < 0 || color > 255)
	{
		std::cerr<<"Error in using the \u001b[33mcustomColor(bool highlight, \u001b[31mint color\u001b[33m, std::string text)\u001b[0m method, please make sure that the color value is an integer between 0-255 inclusive"<<std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::string code = "\033[";
	if(highlight)
		code += std::to_string(48);
	else
		code += std::to_string(38);
	code += ";5;" + std::to_string(color) + 'm' + text + "\033[m";
	return code;
}
std::string customColor(bool highlight, int rValue, int gValue, int bValue)
{
	//implment some form of input checking
	bool error = false;
	std::string errorMessage = "Error in using the \u001b[33mcustomColor(bool highlight, ";
	if(rValue < 0 || rValue > 255){
		errorMessage += "\u001b[31mint rValue\u001b[33m";
		error = true;
	}else{
		errorMessage += "int rValue";
	}
	if(gValue < 0 || gValue > 255){
		errorMessage += "\u001b[31m, int gValue\u001b[33m";
		error = true;
	}else{
		errorMessage += ", int gValue";
	}
	if(bValue < 0 || bValue > 255){
		errorMessage += "\u001b[31m, int bValue\u001b[33m";
		error = true;
	}else{
		errorMessage += ", int bValue";
	}
	if(error)
	{
		std::cerr<<errorMessage<<")\u001b[0m method"<<std::endl;
		std::cerr<<"Please make sure that the rValue, gValue, and bValue are all integers between 0-255 inclusive"<<std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	std::string code = "\033[";
	if(highlight)
		code += std::to_string(48);
	else
		code += std::to_string(38);
	code += ";2;" + std::to_string(rValue) + ";" + std::to_string(gValue) + ";" + std::to_string(bValue) + 'm';
	return code;
}
std::string customColor(bool highlight, int rValue, int gValue, int bValue, std::string text)
{
	//implment some form of input checking
	bool error = false;
	std::string errorMessage = "Error in using the \u001b[33mcustomColor(bool highlight, ";
	if(rValue < 0 || rValue > 255){
		errorMessage += "\u001b[31mint rValue\u001b[33m";
		error = true;
	}else{
		errorMessage += "int rValue";
	}
	if(gValue < 0 || gValue > 255){
		errorMessage += "\u001b[31m, int gValue\u001b[33m";
		error = true;
	}else{
		errorMessage += ", int gValue";
	}
	if(bValue < 0 || bValue > 255){
		errorMessage += "\u001b[31m, int bValue\u001b[33m";
		error = true;
	}else{
		errorMessage += ", int bValue";
	}
	if(error)
	{
		std::cerr<<errorMessage<<", std::string text)\u001b[0m method"<<std::endl;
		std::cerr<<"Please make sure that the rValue, gValue, and bValue are all integers between 0-255 inclusive"<<std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	std::string code = "\033[";
	if(highlight)
		code += std::to_string(48);
	else
		code += std::to_string(38);
	code += ";2;" + std::to_string(rValue) + ";" + std::to_string(gValue) + ";" + std::to_string(bValue) + 'm' + text + "\033[m";
	return code;
}

void testANSICodes()
{
	std::cout<<underline()<<std::setw(9)<<"underline"<<" | Code: 'underline()' OR 'underline(std::string text)'"<<reset()<<std::endl;
	std::cout<<bold()<<std::setw(9)<<"bold"<<" | Code: 'bold()' OR 'bold(std::string text)"<<reset()<<std::endl;
	std::cout<<reverse()<<std::setw(9)<<"reverse"<<" | Code: 'reverse()' OR 'reverse(std::string text)"<<reset()<<std::endl;
	
	std::cout<<black(false, false)<<std::setw(14)<<"normal black"<<reset()<<" | "<<black(true, false)<<std::setw(14)<<"bright black"<<reset()<<" | "<<black(false, true)<<std::setw(17)<<"black highlight"<<reset()<<" | "<<black(true, true)<<std::setw(24)<<"bright black highlight"<<reset()<<" | Code: 'black(bool bright, bool highlight)' OR 'black(bool bright, bool highlight, std::string text)'"<<std::endl;
	
	std::cout<<red(false, false)<<std::setw(14)<<"normal red"<<reset()<<" | "<<red(true, false)<<std::setw(14)<<"bright red"<<reset()<<" | "<<red(false, true)<<std::setw(17)<<"red highlight"<<reset()<<" | "<<red(true, true)<<std::setw(24)<<"bright red highlight"<<reset()<<" | "<<red(false, false)<<"Code: 'red(bool bright, bool highlight)' OR 'red(bool bright, bool highlight, std::string text)'"<<reset()<<std::endl;
	
	std::cout<<green(false, false)<<std::setw(14)<<"normal green"<<reset()<<" | "<<green(true, false)<<std::setw(14)<<"bright green"<<reset()<<" | "<<green(false, true)<<std::setw(17)<<"green highlight"<<reset()<<" | "<<green(true, true)<<std::setw(24)<<"bright green highlight"<<reset()<<" | "<<green(false, false)<<"Code: 'green(bool bright, bool highlight)' OR 'green(bool bright, bool highlight, std::string text)'"<<reset()<<std::endl;
	
	std::cout<<yellow(false, false)<<std::setw(14)<<"normal yellow"<<reset()<<" | "<<yellow(true, false)<<std::setw(14)<<"bright yellow"<<reset()<<" | "<<yellow(false, true)<<std::setw(17)<<"yellow highlight"<<reset()<<" | "<<yellow(true, true)<<std::setw(24)<<"bright yellow highlight"<<reset()<<" | "<<yellow(false, false)<<"Code: 'yellow(bool bright, bool highlight)' OR 'yellow(bool bright, bool highlight, std::string text)'"<<reset()<<std::endl;
	
	std::cout<<blue(false, false)<<std::setw(14)<<"normal blue"<<reset()<<" | "<<blue(true, false)<<std::setw(14)<<"bright blue"<<reset()<<" | "<<blue(false, true)<<std::setw(17)<<"blue highlight"<<reset()<<" | "<<blue(true, true)<<std::setw(24)<<"bright blue highlight"<<reset()<<" | "<<blue(false, false)<<"Code: 'blue(bool bright, bool highlight)' OR 'blue(bool bright, bool highlight, std::string text)'"<<reset()<<std::endl;
	
	std::cout<<magenta(false, false)<<std::setw(14)<<"normal magenta"<<reset()<<" | "<<magenta(true, false)<<std::setw(14)<<"bright magenta"<<reset()<<" | "<<magenta(false, true)<<std::setw(17)<<"magenta highlight"<<reset()<<" | "<<magenta(true, true)<<std::setw(24)<<"bright magenta highlight"<<reset()<<" | "<<magenta(false, false)<<"Code: 'magenta(bool bright, bool highlight)'  OR 'magenta(bool bright, bool highlight, std::string text)'"<<reset()<<std::endl;
	
	std::cout<<cyan(false, false)<<std::setw(14)<<"normal cyan"<<reset()<<" | "<<cyan(true, false)<<std::setw(14)<<"bright cyan"<<reset()<<" | "<<cyan(false, true)<<std::setw(17)<<"cyan highlight"<<reset()<<" | "<<cyan(true, true)<<std::setw(24)<<"bright cyan highlight"<<reset()<<" | "<<cyan(false, false)<<"Code: 'cyan(bool bright, bool highlight)' OR 'cyan(bool bright, bool highlight, std::string text)'"<<reset()<<std::endl;
	
	std::cout<<white(false, false)<<std::setw(14)<<"normal white"<<reset()<<" | "<<white(true, false)<<std::setw(14)<<"bright white"<<reset()<<" | "<<white(false, true)<<std::setw(17)<<"white highlight"<<reset()<<" | "<<white(true, true)<<std::setw(24)<<"bright white highlight"<<reset()<<" | "<<white(false, false)<<"Code: 'white(bool bright, bool highlight)' OR 'white(bool bright, bool highlight, std::string text)'"<<reset()<<std::endl<<std::endl;
	
	std::cout<<"Through the use of the cusomeColor method you can use custom colors, as the name suggests, there are 4 uses for this method:"<<std::endl<<"'customColor(bool highlight, int color[0-255])' OR 'customColor(bool highlight, int color[0-255], std::string text)' OR"<<std::endl<<"'customColor(bool highlight, int rValue[0-255], int gValue[0-255], int bValue[0-255])' OR 'customColor(bool highlight, int rValue[0-255], int gValue[0-255], int bValue[0-255], std::string text)'"<<std::endl<<std::endl;
	
	std::cout<<"To return to the default text format use the code: 'reset()'. If this is not used, the format will remain on the last set format for entire output, or until changed."<<std::endl<<"Note: this does not apply to formatting using alternate methods i.e. bold(std::string) will reset automatically"<<std::endl;
}