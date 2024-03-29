#include "unstable.h"
#include "../grid.h"
#include "../display/window.h"

using namespace std;

UnstableSquare::UnstableSquare(int r, int c, string color):Square(r, c, color, "unstable"){}

void UnstableSquare::remove(int count){
  if(count == 4){
    return grid->removeRect(r-2, c-2, 5, 5);
  }
  return grid->removeRect(r-1, c-1, 3, 3);
  
}

void UnstableSquare::draw(Xwindow *window, int x, int y) {
   
    int height = Settings::SQUARE_HEIGHT; // save us some typing
    int width = Settings::SQUARE_WIDTH;

    int ribbon_height = height / 5;
    int ribbon_width = width / 5;

    window->fillRectangle(x, y, width, height,
        1);

    window->fillRectangle(x+ribbon_width, y, width - ribbon_width*2, height, getColorInt());
    window->fillRectangle(x, y+ribbon_height, width, height- ribbon_height*2, getColorInt());
    

    window->drawString(x + (width / 2) - 5, y + (height / 2) + 5, "US", 1);
}
