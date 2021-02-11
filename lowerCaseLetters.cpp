#include <iostream>
using std::cout;
using std::endl;
void to_lower(char* s);

int main() {
	char* temp = (char*)"Words on a screen.";
	cout << temp << endl;
	to_lower(temp);
	cout << temp << endl;
	return 0;
}

void to_lower(char* s){
	int caseDiff = 'a' - 'A';

	for(int i =0; s[i] != '\0'; i++)
	{
		if(s[i] >= 'A' && s[i]<='Z')
		{
			s[i] = s[i] + caseDiff;
		}
	}

}