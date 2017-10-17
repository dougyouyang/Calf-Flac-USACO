//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;
string text[20000];
int lar=0, start;

int main()
{
    string letter;
    int s=0, size, lar=0;
    int i, j;
    
    while(true){
        getline(cin, text[s++]);
        if(cin.eof())
            break;
        int size2=text[s-1].length();
        for(i=0;i<size2;i++){
            if(isalpha(text[s-1][i]))
                letter+=text[s-1][i];
        }
    }
    
    size=letter.length();
    for(i=0;i<size;i++){
        letter[i]=tolower(letter[i]);
    }
    for(i=0;i<size-1;i++){
        j=1;
        while(i-j>=0 && i+j<size){
            if(letter[i-j]!=letter[i+j])
                break;
            j++;
        }
        if(j*2-1>lar)
            lar=j*2-1, start=i-j;
        if(letter[i]==letter[i+1]){
            j=1;
            while(i-j>=0 && i+j+1<size){
                if(letter[i-j]!=letter[i+j+1])
                    break;
                j++;
            }
            if(j*2>lar)
                lar=j*2, start=i-j;
        }
    }
    
    cout << lar << endl;
    int count=0;
    for(i=0;i<s;i++){
        j=0;
        while(text[i][j]){
            if(count>start && count<=start+lar){
                if(count==start+1){
                    if(!isalpha(text[i][j])){
                        j++;
                        continue;
                    }
                }
                cout << text[i][j];
            }
            if(isalpha(text[i][j]))
                count++;
            j++;
        }
        if(count>start && count<=start+lar){
            if(count!=start+1)
                cout << endl;
        }
    }
    cout << endl;
    
    return 0;
}
