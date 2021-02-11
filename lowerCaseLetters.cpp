#include <iostream>
using std::cout;
using std::endl;
void to_lower(char* s);

int main() {
	cout << "Hello, Program 3!" << endl;
	to_lower("greetings");
	return 0;
}

void to_lower(char* s){
	for(int i =0; s[i] != '\0'; i++)
	{
		cout << s[i];
	}

	/*
	int i = 0;
	while(s[i] != '\0')
	{

	}*/
}