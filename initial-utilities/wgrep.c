#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lineMatch(char* line,char *target){
    int i  = 0;
    while(line[i] != '\0'){
        int flag = 0;
        for(int j = 0 ;target[j] != '\0'; j++){
            if(line[i+j] == target[j]){
                flag = 1;
                continue;
            }else{
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            return 1;
        }
        i ++;
    }
    return 0;
}

int fileMatch(char*filename,char*target){
    FILE *fp;
    fp = fopen(filename,"r");
    if(fp == NULL){
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    char *buffer;
    size_t bufsize = 1024;
    buffer = (char *)malloc(bufsize*sizeof(char));
  
    while(getline(&buffer,&bufsize,fp) > 0){
        if(lineMatch(buffer,target)){
            printf("%s",buffer);
        }
    }
    fclose(fp);
    return 0;
}




int main(int argc, char* argv[]){
    if(argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }else if(argc == 2){
        char *buffer;
        size_t bufsize = 1024;
        buffer = (char*)malloc(bufsize*sizeof(char));
        while(fgets(buffer,bufsize,stdin)){
            if(lineMatch(buffer,argv[1])){
                printf("%s",buffer);
            }
        }
    }else{
        for(int i = 2; i < argc; i++){
            fileMatch(argv[i],argv[1]);
        }
    }
    return 0;


}