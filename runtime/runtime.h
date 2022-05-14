#ifndef RUNTIME_H
#define RUNTIME_H
#include <malloc.h>
#include <string.h>

typedef char* string;

int MAX_MALLOC;
#define new 0
#define $string ^!new?new_string(new):0; 
#define new_string(n) (string)malloc(MAX_MALLOC=n*sizeof(char))
#define ____MALLOC_Err_msg puts("Memory allocation failed");
#define EXIT__FAILURE 1
#define EXIT__SUCCESS 0

#define append_string(des, src) \
des=(string)realloc((string)des, MAX_MALLOC=strlen(des)+strlen(src)+1); \
if(des!=NULL){ strcpy(des+strlen(des), src); }else{____MALLOC_Err_msg; exit(EXIT__FAILURE);}

#define write_string(des, src) \
if(strlen(des)+strlen(src) < MAX_MALLOC){ strcpy(des+strlen(des), src);}else{ \
append_string(des, src); }

#define write_string_lim(des, src) \
if(strlen(des)+strlen(src) < MAX_MALLOC){ strcpy(des+strlen(des), src);} else { \
if(des!=NULL) { puts("Not enough allocated memory"); exit(EXIT__FAILURE);}} 

#define replace_string(des, src) \
des=(string)realloc((string)des, MAX_MALLOC=strlen(src)+1); \
if(des!=NULL){ strcpy(des, src); }else{____MALLOC_Err_msg; exit(EXIT__FAILURE);}

int ____c;
#define slice_string(src, rem) \
____c = 0; while(src[____c]!='\0'){ if(!strncmp(src+____c, rem, strlen(rem))){break;} ____c++;} \
while(src[____c+strlen(rem)]!='\0'){ src[____c]= src[____c+strlen(rem)]; ____c++;} src[____c] = '\0'; \
src = (string)realloc((string)src, MAX_MALLOC=____c+1); if(src==NULL){____MALLOC_Err_msg; exit(EXIT__FAILURE);}

char *ptr;
#define insert_string(src, ins, i) \
____c = i; src = realloc((string)src, MAX_MALLOC=strlen(src)+strlen(ins)+1); \
if(src!=NULL){ptr = realloc((string)ptr,  MAX_MALLOC-____c); \
if(ptr!=NULL){strcpy(ptr, src+____c); strcpy(src+____c, ins); \
strcpy(src+____c+strlen(ins), ptr); \
delete(ptr); ptr=NULL;}else{____MALLOC_Err_msg; exit(EXIT__FAILURE);}}else{____MALLOC_Err_msg; exit(EXIT__FAILURE);}

#define get_string(des) \
____c = 0; while(1){ des[____c] = getchar(); \
if(des[____c] == '\n'){des[____c]='\0'; break;} \
else{____c++;des=realloc((string)des, MAX_MALLOC=____c+1);if(des==NULL){____MALLOC_Err_msg; return EXIT__FAILURE;}}}

#define sizeof_list(s) sizeof(s)/sizeof(s[0])

#define init_list(lname, type) \
if(!strcmp(type,"string")){ \
for(____c = 0; ____c < sizeof_list(lname); ____c++){lname[____c]=new $string;}}

#define delete_list(lname) \
for(____c = 0; ____c < sizeof_list(lname); ____c++){if(lname[____c] != NULL){delete(lname[____c]);}}


#define new_short(n)           (short*)malloc(MAX_MALLOC=n*sizeof(short))
#define new_ushort(n)          (unsigned short*)malloc(MAX_MALLOC=n*sizeof(unsigned short))
#define new_int(n)             (int*)malloc(MAX_MALLOC=n*sizeof(int))
#define new_uint(n)            (unsigned int*)malloc(MAX_MALLOC=n*sizeof(unsigned int))
#define new_long(n)            (long long int*)malloc(MAX_MALLOC=n*sizeof(long long int)) 
#define new_ulong(n)           (unsigned long long int*)malloc(MAX_MALLOC=n*sizeof(unsigned long long int))
#define new_float(n)           (float*)malloc(MAX_MALLOC=n*sizeof(float)) 
#define new_double(n)          (double*)malloc(MAX_MALLOC=n*sizeof(double))
#define new_long_double(n)     (long double*)malloc(MAX_MALLOC=n*sizeof(long double))

#define delete(n) n!=NULL?free(n):puts("null pointer can't be freed");

#endif
