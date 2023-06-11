#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string palavra;
    cout << "Digite a palavra: ";
    cin >> palavra;

    int vogais[5] = {0};

    for(size_t i = 0; i < palavra.length();i++){
        if(palavra[i]=='a'){
            vogais[0]++;
        }
        if(palavra[i]=='e'){
            vogais[1]++;
        }
        if(palavra[i]=='i'){
            vogais[2]++;
        }
        if(palavra[i]=='o'){
            vogais[3]++;
        }
        if(palavra[i]=='u'){
            vogais[4]++;
        }
    }

    if(vogais[0]!=0){
        cout << "a " << vogais[0] << endl;
    }

    if(vogais[1]!=0){
        cout << "e " << vogais[1] << endl;
    }

    if(vogais[2]!=0){
        cout << "i " << vogais[2] << endl;
    }


    if(vogais[3]!=0){
        cout << "o " << vogais[3] << endl;
    }

    if(vogais[4]!=0){
        cout << "u " << vogais[4] << endl;
    }
    
    
    
    return 0;
}