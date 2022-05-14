#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "runtime.h"


int main(void)
{
   //Example
   string var = new $string;
   write_string(var, "Hello Github!");
   puts(var);
   delete(var);
   return 0;
}
