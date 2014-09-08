#include <stdio.h>

void lpr_print (char *the_text)
{
  FILE *printer;

  printer = popen ("lpr", "w");
  fprintf (printer, the_text);
  pclose (printer);
}
