#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    
  int dx, dy;
  dx = x1 - x0;
  dy = y1 - y0;

  //1 or 5
  if ( abs(dx) >= abs(dy) ) {
    //1
    if ( dx > 0 )
      oct_1( x0, y0, x1, y1, s, c );
    //5
    else
      oct_1( x1, y1, x0, y0, s, c );
  }
  //2 or 6
  else if ( abs(dx) < abs(dy) ) {
    //2
    if ( dy > 0 )
      oct_2( x0, y0, x1, y1, s, c );
    //6
    else 
     oct_2( x1, y1, x0, y0, s, c );
 }
  //3 or 7
 else if ( abs(dx) <= abs(dy) ) {
   //3
   if ( dx < 0 )
     oct_3( x0, y0, x1, y1, s, c );
   //7
   else
     oct_3( x1, y1, x0, y0, s, c );
 }
  //4 or 8
 else {
   //4
   if ( dx < 0 )
     oct_4( x0, y0, x1, y1, s, c );
   //8
   else 
     oct_4( x1, y1, x0, y0, s, c );
 }
  
}

void oct_1( int x0, int y0, int x1, int y1, screen s, color c ) {

  int x, y, dx, dy, A, B, d;
  x = x0;
  y = y0;
  dx = abs(x1 - x0);
  dy = abs(y1 - y0);
  A = dy;
  B = -1 * dx;
  d = 2*A + B;

  while ( x <= x1 ) {

    plot( s, c, x, y );
    if ( d > 0 ) {
      
      y += 1;
      d += 2*B;
    
    }

    x += 1;
    d += 2*A;
 
  }

}

void oct_2( int x0, int y0, int x1, int y1, screen s, color c ) {

  int x, y, dx, dy, A, B, d;
  x = x0;
  y = y0;
  dx = abs(x1 - x0);
  dy = abs(y1 - y0);
  A = dy;
  B = -1 * dx;
  d = A + 2*B;

  while ( y <= y1 ) {

    plot( s, c, x, y );
    if ( d < 0 ) {

      x += 1;
      d += 2*A;

    }

    y += 1;
    d += 2*B;

  }

}

void oct_3( int x0, int y0, int x1, int y1, screen s, color c ) {

  int x, y, dx, dy, A, B, d;
  x = x0;
  y = y0;
  dx = abs(x1 - x0);
  dy = abs(y1 - y0);
  A = dy;
  B = -1 * dx;
  d = 2*A + B;

  while ( y <= y1 ) {
    
    plot( s, c, x, y );
    if ( d < 0 ) {

      x -= 1;
      d += 2*A;

    }

    y += 1;
    d += 2*B;
    
  }
  
}

void oct_4( int x0, int y0, int x1, int y1, screen s, color c ) {

  int x, y, dx, dy, A, B, d;
  x = x0;
  y = y0;
  dx = abs(x1 - x0);
  dy = abs(y1 - y0);
  A = dy;
  B = -1 * dx;
  d = A + 2*B;

  while ( y <= y1 ) {

    plot( s, c, x, y );
    if ( d > 0 ) {
      
      y += 1;
      d += 2*B;

    }

    x -= 1;
    d += 2*A;

  }

}
