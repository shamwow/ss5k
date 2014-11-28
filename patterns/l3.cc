#include <iostream>
#include <string>
#include "l3.h"
#include "../grid.h"

using namespace std;

/*
    x
    x
  xxx

*/

L3Pattern::L3Pattern(int p):Pattern(p){}

vector<Square*> L3Pattern::check(int r, int c, const Grid& g) {
  Square* start = g.getSquare(r, c);
  vector<Square*> output;
  
  if(!start){
    return output;
  }

  string color = start->getColor();
  /*
      o
      x
    xxx
  */
  if(g.getSquare(r+1, c, color) && g.getSquare(r+2, c, color) && g.getSquare(r+2, c-1, color) && g.getSquare(r+2, c-2, color)){
    output.push_back(start);
    output.push_back(g.getSquare(r+1, c, color));
    output.push_back(g.getSquare(r+2, c, color));
    output.push_back(g.getSquare(r+2, c-1, color));
    output.push_back(g.getSquare(r+2, c-2, color));
  }
  /*
      x
      o
    xxx
  */
  else if(g.getSquare(r-1, c, color) && g.getSquare(r+1, c, color) && g.getSquare(r+1, c-1, color) && g.getSquare(r+1, c-2, color)){
    output.push_back(start);
    output.push_back(g.getSquare(r-1, c, color));
    output.push_back(g.getSquare(r+1, c, color));
    output.push_back(g.getSquare(r+1, c-1, color));
    output.push_back(g.getSquare(r+1, c-2, color));
  }
  /*
      x
      x
    xxo
  */
  else if(g.getSquare(r-1, c, color) && g.getSquare(r-2, c, color) && g.getSquare(r, c-1, color) && g.getSquare(r, c-2, color)){
    output.push_back(start);
    output.push_back(g.getSquare(r-2, c, color));
    output.push_back(g.getSquare(r-1, c, color));
    output.push_back(g.getSquare(r, c-1, color));
    output.push_back(g.getSquare(r, c-2, color));
  }
  /*
      x
      x
    xox
  */
  else if(g.getSquare(r, c-1, color) && g.getSquare(r, c+1, color) && g.getSquare(r-1, c+1, color) && g.getSquare(r-2, c+1, color)){
    output.push_back(start);
    output.push_back(g.getSquare(r, c-1, color));
    output.push_back(g.getSquare(r, c+1, color));
    output.push_back(g.getSquare(r-1, c+1, color));
    output.push_back(g.getSquare(r-2, c+1, color));
  }
  /*
      x
      x
    oxx
  */
  else if(g.getSquare(r, c+1, color) && g.getSquare(r, c+2, color) && g.getSquare(r-1, c+2, color) && g.getSquare(r-2, c+2, color)){
    output.push_back(start);
    output.push_back(g.getSquare(r, c+1, color));
    output.push_back(g.getSquare(r, c+2, color));
    output.push_back(g.getSquare(r-1, c+2, color));
    output.push_back(g.getSquare(r-2, c+2, color));
  }
  
  return output;
}


// input expected to ne left-top most element
pair<int, int> L3Pattern::newPos(int r, int c){
  return make_pair(r+2, c);
}

string L3Pattern::newType(){
  return "unstable";
}

Pattern* L3Pattern::copy(){
  L3Pattern* copy = new L3Pattern(priority);
  return copy;
}