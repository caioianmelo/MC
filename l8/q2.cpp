#include <iostream>
#include <string>

using namespace std;

int main() {
	string s, m;
	int i, b = 0, e, szm = 0, l;
	bool t;

	getline(cin, s);
	l = s.size();

	for(i = 0; i <= l; ++i) {
		if(s[i] == ' ' || i == l)	{
			e= i-b;
			if( e > szm ) {
				m = s.substr(b, e);
				szm = e;
			}
			b = i+1;
		}
	}

	cout << m << endl;

	return 0;
} 
