/*
$ gcc -fPIC -shared vuln.c -o libvuln.so
*/

#include <string.h>
#include <stdint.h>

void fuzzMe(const uint8_t *buffer, uint32_t length)
{
  void (*crashMe)() = NULL;

  if (length < 16)
    return;

    /* Quarksl4bfuzzMe! */
  if (buffer[0] == 'Q')
    if (buffer[1] == 'u')
     if (buffer[2] == 'a')
      if (buffer[3] == 'r')
       if (buffer[4] == 'k')
        if (buffer[5] == 's')
         if (buffer[6] == 'l')
          if (buffer[7] == '4')
           if (buffer[8] == 'b')
            if (buffer[9] == 'f')
             if (buffer[10] == 'u')
              if (buffer[11] == 'z')
               if (buffer[12] == 'z')
                if (buffer[13] == 'M')
                 if (buffer[14] == 'e')
                  if (buffer[15] == '!')
                    crashMe();
}
