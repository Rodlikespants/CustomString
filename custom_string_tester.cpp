#include "custom_string.h"
#include <cstring>
#include <iostream>

using namespace std;

static void test(const char *test_name,bool test_result);

static const char *s_hello_world = "Hello, World!";
static const unsigned int s_hello_world_len = strlen(s_hello_world);

int main() {
  {
    CustomString s;
    test("Test 1",s.Length() == 0);
    cout << "CustomString() prints: \"";
    s.Print();
    cout << "\"" << endl;
  }
  {
    CustomString s(s_hello_world);
    test("Test 2",s.Length() == s_hello_world_len);
    char buf[100];
    s.CopyToCharBuf(buf,100);
    test("Test 3",strcmp(buf,s_hello_world) == 0);
    cout << "CustomString(const char*) prints: \"";
    s.Print();
    cout << "\"" << endl;
  }
  {
    CustomString s(s_hello_world,5);
    test("Test 4",s.Length() == 5);
    char buf[100];
    s.CopyToCharBuf(buf,100);
    test("Test 5",strcmp(buf,"Hello") == 0);
    cout << "CustomString(const char*,unsigned int) prints: \"";
    s.Print();
    cout << "\"" << endl;
  }
  {
    CustomString s1(s_hello_world);
    test("Test 6",s1.Length() == s_hello_world_len);
    CustomString s2(s1);
    test("Test 7",s1.Length() == s2.Length());
    char buf[100];
    s2.CopyToCharBuf(buf,100);
    test("Test 8",strcmp(buf,s_hello_world) == 0);
    cout << "CustomString(const CustomString&) prints: \"";
    s2.Print();
    cout << "\"" << endl;
  }
  {
    CustomString s1(s_hello_world);
    test("Test 9",s1.Length() == s_hello_world_len);
    CustomString s2;
    s2 = s1;
    test("Test 10",s1.Length() == s2.Length());
    char buf[100];
    s2.CopyToCharBuf(buf,100);
    test("Test 11",strcmp(buf,s_hello_world) == 0);
    cout << "operator=(const CustomString&) prints: \"";
    s2.Print();
    cout << "\"" << endl;
  } {
    CustomString s("HELLO");
    char buf[100];
    memset(buf,'X',sizeof(buf));
    s.CopyToCharBuf(buf,3);
    test("Test 12",((buf[0]=='H') && (buf[1]=='E') && (buf[2]=='L') && (buf[3]=='X')));
    memset(buf,'X',sizeof(buf));
    s.CopyToCharBuf(buf,5);
    test("Test 13",((buf[6]=='X') && (!strncmp(buf,"HELLO",5))));
  }
  {
    CustomString s("Hello");
    s = s;
    char buf[100];
    s.CopyToCharBuf(buf,100);
    test("Test 14",strcmp(buf,"Hello") == 0);
    cout << "Self-assignment test prints: \"";
    s.Print();
    cout << "\"" << endl;
  }

  return(0);
}

void test(const char *test_name,bool test_result) {
  if(test_result)
    cout << test_name << "  [32mOK[0m" << endl;
  else
    cout << test_name << "  [31mFAILED[0m" << endl;
}
