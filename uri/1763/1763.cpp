#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, string> dic;
	string word;

	dic["brasil"] =	"Feliz Natal!";
	dic["alemanha"] = "Frohliche Weihnachten!";
	dic["austria"] = "Frohe Weihnacht!";
	dic["coreia"] = "Chuk Sung Tan!";
	dic["espanha"] = "Feliz Navidad!";
	dic["grecia"] = "Kala Christougena!";
	dic["estados-unidos"] = "Merry Christmas!";
	dic["inglaterra"] = "Merry Christmas!";
	dic["australia"] = "Merry Christmas!";
	dic["portugal"] = "Feliz Natal!";
	dic["suecia"] = "God Jul!";
	dic["turquia"] = "Mutlu Noeller";
	dic["argentina"] = "Feliz Navidad!";
	dic["chile"] = "Feliz Navidad!";
	dic["mexico"] = "Feliz Navidad!";
	dic["antardida"] = "Merry Christmas!";
	dic["canada"] = "Merry Christmas!";
	dic["irlanda"] = "Nollaig Shona Dhuit!";
	dic["belgica"] = "Zalig Kerstfeest!";
	dic["italia"] = "Buon Natale!";
	dic["libia"] = "Buon Natale!";
	dic["siria"] = "Milad Mubarak!";
	dic["marrocos"] = "Milad Mubarak!";
	dic["japao"] = "Merii Kurisumasu!";

	while(cin >> word) {

		string r = dic[word];

		if(r != "")
			cout << r << '\n';
		else
			cout << "--- NOT FOUND ---\n";
	}
	return 0;
}