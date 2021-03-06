#ifndef _BOARD_H
#define _BOARD_H

#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include "Index.h"
#include "play.hpp"

class play;

class Board{
  
  char space =  '.'; //for empty space
  char playerX = 'X'; 
  char playerO =  'O';
  
  
  public:
    int num;//numXnum
    play** mat;
    
    Board(Board&);//copy c'tor
    
    Board (int);
    ~Board();
    void del();
    
    void init();
    friend ostream& operator<<(ostream&, const Board&);
    play& operator[](Index);
    play operator[](Index) const;
    Board& operator=(const Board&);
    Board& operator=(char);
    friend bool operator== (Board const& x, Board const& y);
    friend bool operator!= (Board const& x, Board const& y);
    
};

inline ostream&  operator<<(ostream& out, const Board& a){
    for(int i = 0; i < a.num;i++){
        for(int j = 0; j < a.num;j++){
            out << a.mat [i][j].get_sign();
        }
        out<<endl;
    }
    return out;
}

#endif
