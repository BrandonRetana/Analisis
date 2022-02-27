#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;


//------------------------------------------------------------Triplets problem------------------------------------------------------------
int* inefficientTriplets(int aliceArray[], int bobArray[]) {
    int* resultArray = new int[2];

    for (int i = 0; i < 3; i++) {
        if (aliceArray[i] > bobArray[i]) {
            resultArray[0]++;
        }
        if (bobArray[i] > aliceArray[i]) {
            resultArray[1]++;
        }
    } 
return resultArray;  
}

int* efficientTriplets(int aliceArray[], int bobArray[]) {
    int* resultArray = new int[2];

    if (aliceArray[0] != bobArray[0]) {
        resultArray[0]+= ((aliceArray[0]-bobArray[0])/abs(aliceArray[0]-bobArray[0]))+1;    
        resultArray[1]+= ((bobArray[0]-aliceArray[0])/abs(bobArray[0]-aliceArray[0]))+1;
    }
    if (aliceArray[1] != bobArray[1]) {
        resultArray[0]+= ((aliceArray[1]-bobArray[1])/abs(aliceArray[1]-bobArray[1]))+1;
        resultArray[1]+= ((bobArray[1]-aliceArray[1])/abs(bobArray[1]-aliceArray[1]))+1;
    }
    if (aliceArray[2]!=bobArray[2]) {
        resultArray[0]+= ((aliceArray[2]-bobArray[2])/abs(aliceArray[2]-bobArray[2]))+1;
        resultArray[1]+= ((bobArray[2]-aliceArray[2])/abs(bobArray[2]-aliceArray[2]))+1;
    }
    resultArray[0] = resultArray[0]/2;
    resultArray[1] = resultArray[1]/2;

return resultArray;
}

void testTriplets() {
    int aliceArray[3];
    int bobArray[3]; 

    cout<<"Ingrese tres numeros para cada array"<<endl;
    for (int i = 0; i < 3; i++) {
        cin>>aliceArray[i];
    }
    for (int i = 0; i < 3; i++) {
        cin>>bobArray[i];
    }
    
    int* result = inefficientTriplets(aliceArray, bobArray);
    cout<<"Alicia score: "<<result[0]<<" Bob score: "<<result[1]<<endl;

    int* resultTwo = efficientTriplets(aliceArray, bobArray);
    cout<<"Alicia score: "<<resultTwo[0]<<" Bob score: "<<resultTwo[1]<<endl;
}

//------------------------------------------------------------Time Conversion------------------------------------------------------------ 
string inefficientTimeConversion(string s) {
    int timeValue = stoi(s.substr(0,2));
    string partsOfTime = s.substr(3,5);
    if (s[8] == 'A') {
        if (timeValue == 12) {
            timeValue = 0;
        }
    }   else{if (timeValue<12) {
            timeValue+=12;
        }
    }
    string result = "";
    if (timeValue < 10) {
        result+="0";
    }
    result+=to_string(timeValue)+":"+partsOfTime;
return result;
}

string efficientTimeConversion(string s) {
    int timeValue = stoi(s.substr(0,2));
    string partsOfTime = s.substr(3,5);
    if (s[8] == 'A') {
        timeValue = timeValue%12;
    }else {
        timeValue+=12;
    }
    string result = "";
    if (timeValue < 10) {
        result+="0";
    }
    result+=to_string(timeValue)+":"+partsOfTime;
return result;
}

void timeCoversionTest() {
    string time;
    cout<<"Ingrese la hora en formato: hh:mm:ssAM/PM"<<endl;
    cin>>time;
    cout<<inefficientTimeConversion(time)<<endl;
    cout<<efficientTimeConversion(time)<<endl;
}

//------------------------------------------------------------Subarray Division------------------------------------------------------------ 

int inefficientSubarrayDivision(int chocolate[], int n, int m, int d) {
    int counter = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = i; j <= m; j++) {
            if (chocolate[i]+chocolate[j]==d) {
                counter++;
            }
        }
    }
return counter; 
}

int efficientSubarrayDivision(int chcolate[], int n, int m, int d) {
    int inicial = 0;
    int respuesta = 0;
    int suma = 0;
    int control = 1;

    for (int i = 0; i < n; i++) {
        suma += chcolate[inicial];

        if (control == m && suma == d) {
            respuesta+=1;
            suma -= chcolate[inicial];
            inicial +=1;
        }else{ if (control == m) {
            suma -= chcolate[inicial];
            inicial +=1;
        }else {
                control+=1;
            }
        }
    }
    return respuesta;
}


void subarrayDivisionTest() {
    int n;
    int d;
    int m;
    cin>>n;
    int* chocoloate = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>chocoloate[i];
    }
    cin>>m>>d;
    cout<<inefficientSubarrayDivision(chocoloate,n,d,m)<<endl;
    cout<<efficientSubarrayDivision(chocoloate,n,d,m)<<endl;
}

//------------------------------------------------------------The minion game------------------------------------------------------------ 
string minionGame(string word) {
    int kevinScore = 0;
    int stuartScore = 0;
    int size = word.length();
    for (int i = 0; i < size; i++) {
        if (word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U') {
            kevinScore += size-i;
        }
        else {
            stuartScore+=size-i;
        }
    }
    if (kevinScore < stuartScore) {
        return "stuart: "+to_string(stuartScore);
    }
    if (kevinScore > stuartScore) {
        return "kevin: "+to_string(kevinScore);
    }
    if (kevinScore == stuartScore) {
        return "Draw";
    }
return "";
}

void minionGameTest() {
    string word;
    cin>>word;
    cout<<minionGame(word)<<endl;
}

int main () {
    //timeCoversionTest();
    //testTriplets();
    //subarrayDivisionTest();
    //minionGameTest();
return 0;
}
