#ifndef UTILS_H
#define UTILS_H

#include<vector>
#include<string>

namespace Utils{
class StringHelper{
public:
static std::string join(const std::vector<std::string>&items,const std::string&delimiter);
static std::vector<std::string>split(const std::string&text,char delimiter);
static std::string trim(const std::string&text);
};

template<typename T>
class Calculator{
public:
T add(T a,T b){return a+b;}
T multiply(T a,T b){return a*b;}
T power(T base,int exponent){
T result=1;
for(int i=0;i<exponent;++i){
result*=base;
}
return result;
}
};
}

#endif
