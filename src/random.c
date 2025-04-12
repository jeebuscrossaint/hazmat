#include "random.h"
#include "hazmat.h"

char* genrand(int len) {
        int tr_exists = system("which tr > /dev/null");
        int head_exists = system("which head > /dev/null");
        if (tr_exists != 0) {
                printf("Binary program 'tr' not found. OS Error code: %d \n", tr_exists);
                return NULL;
        }
        if (head_exists != 0) {
                printf("Binary program 'head' not found. OS Error code: %d \n", head_exists);
                return NULL;
        }

       // Allocate buffer for the random string (+1 for null terminator)
       char *result = malloc(len + 1);
       if (!result) {
               return NULL;
       }

       char cmd[128];
       /* following shell code taken from https://security.stackexchange.com/questions/183948/unix-command-to-generate-cryptographically-secure-random-string */
       snprintf(cmd, sizeof(cmd), "LC_ALL=C tr -dc '[:alnum:]' < /dev/urandom | head -c %d", len);
       // Open a pipe to read the command output
       FILE* pipe = popen(cmd, "r");
       if (!pipe) {
               free(result);
               return NULL;
       }

       // read the output into our buffer
       size_t bytes_read = fread(result, 1, len, pipe);
       result[bytes_read] = '\0'; // Null terminate the string.

       pclose(pipe);

       return result;
}
