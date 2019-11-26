#include "cedict.h"
#include <algorithm>
#include <sstream>
#include <iterator>
#include <regex>
// Look for u values replace u: with ü
cedict::cedict() {
	this->Traditional = "";
	this->Simplified = "";
	this->PinyinNumbered = "";
	this->Pinyin = "";
	
}

cedict::cedict(std::string Traditional, std::string Simplified, std::string PinyinNumbered, std::string Pinyin) {

	this->Traditional = Traditional;
	this->Simplified = Simplified;
	this->PinyinNumbered = PinyinNumbered;
	this->Pinyin = Pinyin;
	

};

cedict::cedict(const cedict& c2) {
	Traditional = c2.Traditional;
	Simplified = c2.Simplified;
	PinyinNumbered = c2.PinyinNumbered;
	Pinyin = c2.Pinyin;
	//Definition = c2.Definition;
}

std::string cedict::getTraditional() {
	return this->Traditional;
}
int cedict::getId() {
	return this->Id;
}
std::string cedict::getSimplified() {
	return this->Simplified;
}
std::string cedict::getPinyin() {
	return this->Pinyin;
}
std::string cedict::getPinyinNumbered() {
	return this->PinyinNumbered;
}
std::vector<std::string> cedict::getDefinitions() {
	return this->Definitions;
}

void cedict::setId(int input) {
	this->Id = input;
}

void cedict::setTraditional(std::string input) {
	this->Traditional = input;
}

void cedict::setSimplified(std::string input) {
	this->Simplified = input;
}

void cedict::setPinyinNumbered(std::string input) {
	this->PinyinNumbered = input;
}
void cedict::addDefinition(std::string input) {
	this->Definitions.push_back(input);
}

void cedict::setBasicPinyin(std::string str){
	str.erase(std::remove(str.begin(), str.end(), '1'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '2'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '3'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '4'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '5'), str.end());
	this->BasicPinyin = str;

}
std::string cedict::getBasicPinyin(){
	return this->BasicPinyin;
}

void cedict::setPinyin(std::string input) {

	std::istringstream iss(input);
	std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},std::istream_iterator<std::string>{}};

	for(auto it = tokens.begin(); it < tokens.end(); ++it){
		std::cout<<"token:"<<*it<<std::endl;
	}

	this->Pinyin = input;
}

std::string cedict::convertToTones(std::string input){
	std::string atones[5] = {"ā", "á", "ǎ", "à", "a"};
	std::string etones [5] = {"ē", "é", "ě", "è", "e"};
	std::string itones [5] = {"ī", "í", "ǐ", "ì", "i"};
	std::string otones [5] = {"ō", "ó", "ǒ", "ò", "o"};
	std::string udottones [5] = {"ǖ", "ǘ", "ǚ", "ǜ", "ü"};

	// Look for u values replace u: with ü
	std::regex_replace(input, std::regex("u:"), "ü");

//replace a or e with its tone because thats one of the easiest
	//A and e trump all other vowels and always take the tone mark.
	// There are no Mandarin syllables in Hanyu Pinyin that contain both a and e.


	if((input.find("a") != std::string::npos) || (input.find("A") != std::string::npos) || (input.find("e") != std::string::npos) || (input.find("E") != std::string::npos) ) {


	}
	//In the combination ou, o takes the mark.
	else if ((input.find("ou") != std::string::npos) || (input.find("Ou") != std::string::npos)){

	}

	//Last case, we have to assign the tone mark to the last vowel of the word
	//We will just loop through to find the last vowel and replace it.
    //TODO

}