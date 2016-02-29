#include <stdio.h>

int main() {
    const char *str1 = "abc";
    typedef char *String;
    const String str2 = "def";

//    printf("%d\n", ++str1);             
//    ++str2;           illegal because str2 is const?
//    *str1 = 'A';      illegal because str1 is const?
//    *str2 = 'B';
//    print("%c\n", *str2);
}
