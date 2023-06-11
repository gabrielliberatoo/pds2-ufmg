#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main(){

map<string, int>mp;
string palavra;
string frase;

string linha;
while (getline(cin, linha)) {
        frase += linha + " ";
    }

    size_t pos = frase.find("\n");
    while (pos != string::npos) {
        frase.replace(pos, 1, " ");
        pos = frase.find("\n", pos+1);
    }

istringstream ss(frase);

while(ss >> palavra){
    mp[palavra]++;
}

string palavrafrequente;

int indicepalavra=0;
    
for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second > indicepalavra) {
            indicepalavra = it->second;
            palavrafrequente = it->first;
        }
}

cout << palavrafrequente << endl;
    return 0;
}