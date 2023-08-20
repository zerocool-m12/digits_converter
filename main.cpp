#include<iostream>
#include<bitset>
#include<cstring>
#include<limits>
#include<cstdint>
#include<string>
#include<algorithm>
#include<functional>
void bin_dec();
void dec_bin();
int main(){
  std::cout<<"Please choose from the menu:"<<std::endl;
  char ans;
  std::cout<<"a. Decimal to Binary"<<std::endl;
  std::cout<<"b. Binary to Decimal"<<std::endl;
  while(true){
    ans = std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    switch(ans){
      case 'a': case 'A':
        dec_bin();
        break;
      case 'b': case 'B':
        bin_dec();
        break;
     default: 
        std::cerr<<"Invalide choice!"<<std::endl;
        continue;
        } 
    break;
    }
  if(std::cin.peek()!=0)
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::cout<<"Please press any key to close this window..."<<std::endl;
  std::cin.get();
  return EXIT_SUCCESS;
}
void dec_bin(){
  start:
  std::cout<<"Please enter a decimal number:"<<std::endl;
  std::int32_t num = 0;
  while(true){
    std::cin>>num;
    if(std::cin.fail()){
      std::cerr<<"Invalid decimal number! Please enter a valid number:"<<std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      }
    else break;
    }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::bitset<8>x(num);
  std::cout<<"The number in binary is: ["<<x<<"]"<<std::endl;
  std::cout<<"Do you want to convert another number? [y/n]"<<std::endl;
  char ans;
  while(true){
    ans = std::cin.get();
    switch(ans){
      case 'y': case 'Y':
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        goto start;
        break;
      case 'n': case 'N':
        return;
        break;
      default:  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cerr<<"Invalid choice!"<<std::endl;
        continue;
        } 
     break;
     }
  }
void bin_dec(){
  start:
  std::cout<<"Please enter a binary number:"<<std::endl;
  std::cin.ignore();
  std::string bin;
  std::function<bool(const char)>verify = [](const char x){return x != '0' and x != '1';};
  while(true){
    std::getline(std::cin,bin);
    if(std::any_of(bin.begin(),bin.end(),verify) == true){
      std::cerr<<"Invalid binary number! Please enter a valid binary number!"<<std::endl;
      bin.clear();
      } else break;}
  int num;
  char*ptr;
  num = strtol(bin.c_str(),&ptr,2);
  std::cout<<"The number is: ["<<num<<"]."<<std::endl;
  std::cout<<"Do you want to convert another number? [y/n]"<<std::endl;
  char ans;
  while(true){
    ans = std::cin.get();
    switch(ans){
      case 'y': case 'Y':
       goto start;
       break;
      case 'n': case 'N':
       return; 
       break;
      default: 
       std::cerr<<"Invalid choice!"<<std::endl;
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
       continue;
      }
    break;
  }
 }
