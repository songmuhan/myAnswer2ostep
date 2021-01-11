
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
    if(argc == 1){
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }else{
        FILE *fp;
        char before,next;
        int count = 1;
        for(int i = 1; i < argc; i++){
            fp = fopen(argv[i],"r");
            if(fp == NULL){
                printf("wzip: cannot open file\n");
                exit(1);
            }

            if(i == 1) before = fgetc(fp);
            else{
                next = fgetc(fp);
                if(before != next){
                    fwrite(&count, sizeof(int), 1, stdout);
                    fwrite(&before, sizeof(char), 1, stdout);
                    before = next;
                    count = 1;
                }else{
                    count++;
                }
            }
            while(1) {
                next = fgetc(fp);
                if (next == EOF) {
                    break;
                } else if (before == next) {
                    count++;
                } else {
                    fwrite(&count, sizeof(int), 1, stdout);
                    fwrite(&before, sizeof(char), 1, stdout);
                    before = next;
                    count = 1;
                }
            }

        }
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&before, sizeof(char), 1, stdout);
    }
    return 0;
}