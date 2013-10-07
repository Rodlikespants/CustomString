/*
 * CustomString class uses a char array to store the main String contents.
 */

#include <cstring>

class CustomString {
  public:
    CustomString();
    
    CustomString(const char* str);

    //Initialize with a subset of char* specified by length
    CustomString(const char* str, unsigned int str_len);

    CustomString(const CustomString& rhs);
    CustomString& operator=(const CustomString& rhs);
    ~CustomString();

    //Returns the number of chars in the string
    unsigned int Length() const;

    //Brackets operator for accessing at array index
    const char& operator[](unsigned int pos) const;

    //Brackets operator for changing values at array index
    char& operator[](unsigned int pos);
 
    //Utility function for the main, copy buf_size characters from this string to buf
    //Null termination not guaranteed based on buf_size   
    void CopyToCharBuf(char* buf, unsigned int buf_size) const;

    //Wrapper for strcmp
    //Compares two Strings, returns 0 if equal
    //Returns a value < 0 if s < str
    //Returns a value > 0 if s > str
    int StrCompare(const CustomString& str);

    //Wrapper for strcmp
    int StrCompare(const char* str);

    //Wrapper for strncmp
    int StrNCompare(const CustomString& str, unsigned int num);

    //Wrapper for strncmp
    int StrNCompare(const char* str, unsigned int num);

    //Display string
    void Print() const;

  private:
    char* s;

};
