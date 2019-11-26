#include "cedict.h"
#include <algorithm>
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
void cedict::setPinyin(std::string input) {
	this->Pinyin = input;
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