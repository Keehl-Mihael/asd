//
// Created by siroid on 1/1/19.
//

#ifndef TEST_BUILD_RICHIESTE_H
#define TEST_BUILD_RICHIESTE_H

#include <stack>

template<class T>
class Bilanciate {
public:
    void test(string s);
private:
    std::stack<T> S;
};

template<class T>
void Bilanciate<T>::test(string s) {
    while(!S.empty()){
        S.pop();
    }
    int i =0;
    string error = "";
    while(i < s.size()){
        switch (s[i]){
            case '{':
            case '[':
            case '(':
                S.push(s[i]);
                break;
            case '}':
                if(S.empty() || S.top() != '{'){error =  "} not balanced"; break;}
                if(S.top() == '{') S.pop();
                break;
            case ']':
                if(S.empty() || S.top() != '['){error =  "] not balanced"; break;}
                if(S.top() == '[') S.pop();
                break;
                case ')':
                if(S.empty() || S.top() != '('){error =  ") not balanced"; break;}
                if(S.top() == '(') S.pop();
                break;
        }
        i++;
    }
    if(S.empty()){
        cout << "String balanced" << endl;
    }else{
        if(error == ""){
            cout << "String not balanced " << S.top() << " not balanced" << endl;

        }else{
            cout << "String not balanced " << error << endl;

        }

    }


}

#endif //TEST_BUILD_RICHIESTE_H
