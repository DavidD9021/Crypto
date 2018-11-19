#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void error(string s){
  std::cout<<s<<"\n";
  exit(0);
}

char CyclicCypher(char c,int shift){
  int ascii_max=126,ascii_min=33,cycle_bound=ascii_max-ascii_min;
  if (shift<0) shift=cycle_bound+shift+1;
  if (shift>cycle_bound) shift=shift%cycle_bound-1;
  if (c<ascii_min||c>ascii_max) error("caracter not allowed");
  int x=c+shift;
  if (x>ascii_max) x=ascii_min+x%ascii_max-1;
  return char(x);
}


string Cypher(string message,int shift){
  string crypted;
  for (int i=0;i<message.size();i++) crypted+=CyclicCypher(message[i],shift);
  return crypted;
}

int main(){
  int shift=1;
  string crypt1=Cypher("coucoujesuisla",shift);
  std::cout<<crypt1<<"\n";
  std::cout<<Cypher(crypt1,-shift)<<"\n";

  return 0;
}
