#include <iostream>
#include <fcntl.h>
#include <unistd.h>
//Use Cygwin compiler for headers
using namespace std;

int main(int argc, char * argv []){
if (argc < 2) {
cout << "myUtility executed" << endl;
return 0;
}
if (argc > 5) {
cerr << "Error: More than 4 arguments" <<endl;
return 1;
}
unordered_map<char, bool>flags = { {'a',true }, {'b',true}, {'c',true},
{'d',true} };
//map tracks which characters exist and which have been seen during runtime
//more efficient but lengthy solution could use 1 array
char submitted[4] = "";//tracks order characters inputted
int paramCnt = 0; //prevents more than 4 letters and tracks submitted letter
for (int i = 1; i < argc; ++i) {
//precondition: do arguments exist and do we have less than 4 parameters
//post: if so, read each argument,
const char* arg = argv[i];
const int length = strlen(arg);
if (length < 2 || arg[0] != '-') {
//pre: does the arg NOT begin with a hyphen
//post: if so, return with error
cerr << "Error: No hyphen or missing characters" << endl;
return 1;
}
for (int j = 1; j < length; ++j) {
//pre: does more than one character exis and is the first letter '-'
(hyphen)
//post: read the letters/flags
const char letter = arg[j];
if (flags[letter]) {
//precondition:is the letter given supported and is it un-used?
//postcondition: if so, remove its availability, save the
letter, increase paramCnt
flags[letter] = false;
submitted[paramCnt] = letter;
++paramCnt;
}
else {
cerr << "Error: Repeated letters or invalid letters" << endl;
return 1;
}
}
}
//ostream output
cout << "myUtility executed with option";
if (paramCnt == 1) {
cout << " "<< submitted[0];
}
else {
cout << "s " << submitted[0];
int i = 1;
do {//prevents redundant check
cout << " and " << submitted[i];//could leave "and" for final option
++i;
} while (i < paramCnt);//gets all letters/flags submitted
}
cout << endl;
//string concat output. no "options" string
/*
string result = "myUtility executed with ";
result[24] = submitted[0];
for (int i = 1, j=25; i < paramCnt; ++i){ //creates string
string extention = " and ";
extention[5] = submitted[i];
int z = 0;
while (z < 6 ) {
result[j + z] = extention[z];
z++;
}
j += z;
}
cout << result << endl;
cout << "end: " << result<< endl;
*/
return 0;
}
