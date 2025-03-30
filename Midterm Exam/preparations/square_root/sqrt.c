
#include <assert.h>
#include "sqrt.h"

double SquareRoot(double n)
{
    double l, r, m;

    assert(n>=0.0);

    l = 0;

    r = (n > 1.0) ? n : 1.0; // max(1, n)

    do
    {
      
      m = l + (r-l)/2; // midpoint computation
      
      if (n <= m*m) {r = m; }
      else {l = m;}
    } while (r-l > 1e-5);
    
    return m;

}