#include "play.hpp"
#include "Exceptions.hpp"
#include <iostream>


play :: play(){
    this-> sign = '.';
}

play :: play(char sign){
    if (sign != 'X' && sign != 'O' && sign != '.'){
        IllegalCharException ch;
        ch.set_t(sign);
        throw ch;
    }
    this-> sign = sign;
}

play :: play(play& other){
    this-> sign = other.get_sign();
}
        
char play :: get_sign(){
    return this -> sign;
}
void play :: set_sign(char sign){
    if (sign != 'X' && sign != 'O' && sign != '.'){
        IllegalCharException ch;
        ch.set_t(sign);
        throw ch;
    }
    else
        this-> sign = sign;
}

play& play ::  operator = (char s){
    this-> set_sign(s);
    return *this;
}

play& play :: operator = (play& other){
    this->set_sign(other.sign);
    return *this;
}

bool play::operator==(char c1) const {
    return sign==c1;
}

bool play::operator!=(char c1) const {
    return sign!=c1;
}
    
bool play::operator==(const play &c1) const {
    return sign==c1.sign;
}
    
bool play::operator!=(const play &c1) const {
    return sign!=c1.sign;
}
