#include <iostream>
#include <stack>
#include <string>


bool IsBalanced(std::string str){
     std::stack <char> s;
     char x;
     char brack;
     int p;
     for (int position = 0; position < str.length(); ++position) {
        char next = str[position];
        //if the current pointer is on opening bracket the push it on the stack
        if (next=='(' || next =='['|| next=='{'){
                s.push(next);
                p=position+1;
        }
        else if(next!=')'&& next != ']'&& next!= '}'&& next!= '{'&& next != '['&& next!= '(')
            {
                next=NULL;
            }
        else{
          if(s.empty()){
            std::cout<<position+1;
            return false;
          }
          x=s.top();
          if(next!=NULL){
              s.pop();
          }
          if((x=='['&& next!=']')||(x=='('&& next!=')')||(x=='{'&& next!='}'))
          {
            std::cout<<position+1;
            return false;
          }
          // it means there are some unclosed brackets so changed so set their position
          else if(!s.empty()){
            p--;
          }
         }
        }
      if(s.size()>1 ){
        std::cout<<str.length();
      }
      else if(s.size()==1)
      {
          std::cout<<p;
      }
     return s.empty();
}

int main() {
    std::string text;
    getline(std::cin, text);

 if(IsBalanced(text)){
    std::cout<<"Success";
 }
    return 0;
}
