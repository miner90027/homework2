#include <iostream>
using std::cout;
using std::endl;
void toLower(char* s);

int main() {
	char temp[] = "THESE ARE WORDS & OTHER CHARS TO DEMONSTRATE TO_LOWER().";
	cout << "Original C-style string: " << temp << endl;
	toLower(temp);
	cout << "After running to_lower(): " <<temp << endl;
	return 0;
}

void toLower(char* s){
	int caseDiff = 'a' - 'A';

	for(int i =0; s[i] != '\0'; i++)
	{
		if(s[i] >= 'A' && s[i]<='Z')
		{
			s[i] = s[i] + caseDiff;
		}
	}

}