#include <bits/stdc++.h>
#include "openssl/include/openssl/sha.h"
using namespace std;

string sha256(const string str) {
    char buf[2];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::string NewString = "";
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(buf, "%02x", hash[i]);
        NewString = NewString + buf;
    }
        return NewString;
}

int main() {
    srand(time(NULL));
    string key = rand();
    string keyinput = sha256(key);
    //write to file
    ofstream newFile;
    newFile.open("authkey.txt");
    newFile << keyinput;
    newFile.close();
    cout << key;
    return 0;
}

