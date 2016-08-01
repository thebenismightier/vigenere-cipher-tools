#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	//string s = "CRYPTOISSHORTFORCRYPTOGRAPHY";
	string s = "CRYPTOSHORTCRYPTO";
	unordered_map<string, vector<int>> hmap;
	string buf = "";
	int dist = 0;

	cout << s << endl;

	
	for(int i = 0; i < s.length(); i++){// += (buf.length() > 0) ? buf.length()-1 : 1) {
		
		//cout << i << endl;
		buf = "";
		for(int j = i+1; j < s.length(); ++j) {
			if(s[i] == s[j]) {
				buf += s[i++];
				if(dist == 0) {
					dist = j-i-buf.length()+2;
					//cout << "dist: " << dist << endl;
				}
			}	
			else {	
				if(dist > 0){
					if(buf.length() > 1) {
						cout << buf << ' ' << dist << endl;
						if(hmap.count(buf) == 0) {
							hmap[buf] = vector<int>();
						}
						hmap[buf].push_back(dist);
					}
					else {
						//cout << "d: " << dist << " b: " << buf.length() << endl;
					}
					buf = "";
					j = s.length();
				}
				dist = 0;
			}
		}
		// TODO: refactor to get rid of this duplic code
		if(dist >0 && buf.length() > 1) {
			if(hmap.count(buf) == 0) {
				hmap[buf] = vector<int>();
			}	
			hmap[buf].push_back(dist);
		}

	}
	
	for(auto it : hmap) {
		cout << it.first << ": ";
		for(auto it2 : it.second)
			cout << it2 << " ";
		cout << endl;
	}

	return 0;
}
