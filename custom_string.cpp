#include "custom_string.h"
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

CustomString::CustomString() : s(new char[1]) {
  s[0] = '\0';
}

CustomString::CustomString(const char* str) : s(new char[strlen(str)+1]) {
  //C function, copy contents of str to s
  //In certain circumstances we could have a buffer overflow, but if we are limited
  //to strcopy or strncopy, both have the same method of checking for string null termination
  //so they are equal risk
  strcpy(s,str);
}

CustomString::CustomString(const char* str, unsigned int str_len) : s(new char[str_len+1]) {
  strncpy(s,str,str_len);
  //Null termination not guaranteed, check here for it
  if(s[str_len] != '\0')
    s[str_len] = '\0';
}

//rhs needs to be a reference or we will have infinite recursive call to copy constructor
CustomString::CustomString(const CustomString& rhs) : s(new char[strlen(rhs.s) + 1]) {
  strcpy(s, rhs.s);
}

CustomString& CustomString::operator=(const CustomString& rhs) {
  // Swap copy to elegantly handle the self-assignment possibility of RHS
  CustomString temp(rhs);
  swap(s, temp.s);

  return *this;
}

const char& CustomString::operator[](unsigned int pos) const {
  return s[pos];
}

char& CustomString::operator[](unsigned int pos) {
  return s[pos];
}


unsigned int CustomString::Length() const {
  return strlen(this->s);
}

CustomString::~CustomString() {
  delete[] s;
  s = 0;
}

void CustomString::CopyToCharBuf(char* buf, unsigned int buf_size) const {
  strncpy(buf,s,buf_size);
}

int CustomString::StrCompare(const CustomString& str) {
  return StrCompare(str.s);
}

int CustomString::StrCompare(const char* str) {
  return strcmp(s,str);
}

int CustomString::StrNCompare(const CustomString& str, unsigned int num) {
  return StrNCompare(str.s, num);
}

int CustomString::StrNCompare(const char* str, unsigned int num) {
  return strncmp(s, str, num);
}

void CustomString::Print() const {
  cout << s << endl;
}

