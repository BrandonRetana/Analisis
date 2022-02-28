#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>
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
        for (int j = i+1; j < m; j++) {
            if (chocolate[i]+chocolate[j]==d) {
                counter++;
            }
        }
    }
return counter; 
}

int efficientSubarrayDivision(int s[], int n, int m, int d) {
    int result = 0; 
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i];
        if (i >= m-1) {
            if (sum == d) {
                result++;
            }
            sum-= s[i-(m-1)];
        }        
    }
    return result;
}


void subarrayDivisionTest() {
    int s[5] = {1, 2, 1, 3, 2};
    int n = 5;
    int m = 2;
    int d = 2;

    cout<<inefficientSubarrayDivision(s,n,m,d)<<endl;
    cout<<efficientSubarrayDivision(s,n,m,d)<<endl;

    int s2[5] = {1, 1, 3, 4, 5};

    cout<<inefficientSubarrayDivision(s2,n,m,d)<<endl;
    cout<<efficientSubarrayDivision(s2,n,m,d)<<endl;
}

//------------------------------------------------------------The minion game------------------------------------------------------------ 
string minionGame(string term) {
    int kevinScore = 0;
    int stuartScore = 0;
    int size = term.length();
    for (int i = 0; i < size; i++) {
        if (term[i]=='A' || term[i]=='E' || term[i]=='I' || term[i]=='O' || term[i]=='U') {
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

//------------------------------------------------------------ Cipher ------------------------------------------------------------ 
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string cipher(int k, int n, string s) {
    vector<char> result(n);
    result[0] = s[0]-48;

    for (int i = 1; i < k; i++) {
        result[i] = s[i-1] ^ s[i];
    }
    char aux;
    for (int i = k; i < n; i++) {
        aux = '0';
        for (int j = i-(k-1); j < i; j++) {
            aux = aux ^ result[j];
        }
        result[i] = aux ^ s[i];
    }
    string final_result = "";
    for (int i = 0; i < n; i++) {
        final_result += result[i]+48;
    }
    return final_result;
}

void cipherTest() {
    int n = 10;
    int k = 3;
    string bin = "1110011011";

    cout<<cipher(k,n,bin)<<endl;
}

//------------------------------------------------------------ Pairs ------------------------------------------------------------ 
int pairs(vector<int> arr, int k) {
    int counter = 0;
    sort(arr.begin(), arr.end());
    unordered_map<int, int> hash;

    for (int i = 0; i < arr.size(); i++) {
        int target = arr[i]-k;
        hash.insert(make_pair(arr[i], target));
        if (hash.find(target) == hash.end()) {
            counter+=0;
        }
        else {
            counter+=1;
        }
        
    }
    return counter;
}

void pairsTest() {
    vector<int> arr1 = {1, 3, 5, 8, 6, 4, 2};
    vector<int> arr2 = {1, 5, 3, 4, 2};

    cout<<pairs(arr1, 2)<<endl;
    cout<<pairs(arr2, 2)<<endl;
}

 
int main () {
    //pairsTest();
    //cipherTest();
    //timeCoversionTest();
    //testTriplets();
    //subarrayDivisionTest();
    //minionGameTest();
return 0;
}
