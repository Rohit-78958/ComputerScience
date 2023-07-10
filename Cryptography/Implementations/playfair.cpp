#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

string get_key(string key){
  string res;
  int x[26],c=1;
  for(int i=0;i<26;i++){
    x[i]=0;
    key+=(char)(97+i);
  }
  cout<<"\nThe key matrix is:\n";
  int idx;
  for(int i=0;i<key.size();i++){
    if (key[i]=='j') continue;
    idx=key[i]-97;
    if(!x[idx]){
      x[idx]=1;
      res+=key[i];
      cout<<key[i]<<" ";
      if(c++%5==0)cout<<endl;
    }
  }
  return res;
}

auto make_table(string key){
  unordered_map<char,pair<int,int>> res;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++) res[key[i*5 + j]] = make_pair(i,j);
  }    
  return res;
}

string encrypt(string plainText, string key){
  string cipher="";///
  plainText += 'x' *(plainText.size()%2);
  auto ret = make_table(key);
  int r1,r2,c1,c2;
  for(int i=0;i<plainText.size()-1;i+=2){
    plainText[i] -= 1*(plainText[i]=='j');  //
    r1 = ret[plainText[i]].first;
    r2 = ret[plainText[i+1]].first;
    c1 = ret[plainText[i]].second;
    c2 = ret[plainText[i+1]].second;

    if(r1 == r2){
      c1 = (c1 + 1)%5;
      c2 = (c2 + 1)%5;

      cipher += key[r1*5 + c1];
      cipher += key[r2*5 + c2];
    } 
    else if(c1 == c2){
      r1 = (r1 + 1)%5;
      r2 = (r2 + 1)%5;

      cipher+= key[r1*5 + c1];
      cipher+= key[r2*5 + c2];
    }
    else{
      cipher += key[r1*5 + c2];
      cipher += key[r2*5 + c1];
    }
  }
  return cipher;
}

int main(){
    string plainText, key;
    cout<<"\nEnter key:";
    cin>>key;
    key =get_key(key);
    cout<<"\nEnter plain text:";
    cin>>plainText;
    string cipherText = encrypt(plainText, key);
    cout<<"\nThe Cipher Text:"<<cipherText;
    return 0;
}
