#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

char thread1part[100000],thread2part[100000],thread3part[100000],thread4part[100000];
int t1WCount,t2WCount,t3WCount,t4WCount;
char word[100];
char arr[100];
pthread_mutex_t lock;
FILE * file1;

void *thread1Function(void* arg){
    pthread_mutex_lock(&lock);
    file1 = fopen("out.txt","w");
    int i = 0,j = 0,k = 0;
    int flag = -1;
    FILE * file;
    file = fopen("wordlist.txt","r");
    while(fgets(word, sizeof(word), file)){
        ///printf("%s\n",word );
        while(thread1part[i] != '\0'){
            while(i<strlen(thread1part)){
                if(thread1part[i] == ' ' || thread1part[i] == '\0' || thread1part[i] == '\n'){
                    break;
                }

                ////copy word to third array
                arr[j++] = thread1part[i++];
            }
            arr[j] = '\0';
            j = 0;
            /////if word mached, flag turns true
            if(strstr(word,arr)){
                flag = 1;
            }
            i++;
        }
        ////write in file
        if(flag == 1){
            time_t t;
            time(&t);
            fprintf(file1, "%s", word);
            fprintf(file1,"this word hase been found at : %s", ctime(&t));
            fprintf(file1, "thread 1 found this word\n");
            time(&t);
            fprintf(file1, "time of writing in file %s\n",ctime(&t) );
            ///printf("%s found withh thread1\n", word);

        }
        flag = -1;
        k++;
        i = 0;

        k = 0;
    }
    pthread_mutex_unlock(&lock);
    return 0;
}

void *thread2Function(void* arg){
    pthread_mutex_lock(&lock);
    file1 = fopen("out.txt","w");
    int i = 0,j = 0,k = 0;
    int flag = -1;
    FILE * file;
    file = fopen("wordlist.txt","r");
    while(fgets(word, sizeof(word), file)){
        ///printf("%s\n",word );
        while(thread2part[i] != '\0'){
            while(i<strlen(thread2part)){
                if(thread2part[i] == ' ' || thread2part[i] == '\0' || thread2part[i] == '\n'){
                    break;
                }

                ////copy word to third array
                arr[j++] = thread2part[i++];
            }
            arr[j] = '\0';
            j = 0;
            /////if word mached, flag turns true
            if(strstr(word,arr)){
                flag = 1;
            }
            i++;
        }
        ////write in file
        if(flag == 1){
            time_t t;
            time(&t);
            fprintf(file1, "%s", word);
            fprintf(file1,"this word hase been found at : %s", ctime(&t));
            fprintf(file1, "thread 2 found this word\n");
            time(&t);
            fprintf(file1, "time of writing in file %s\n",ctime(&t) );
            ///printf("%s found withh thread1\n", word);

        }
        flag = -1;
        k++;
        i = 0;

        k = 0;
    }
    pthread_mutex_unlock(&lock);
    return 0;
}

void *thread3Function(void* arg){
    pthread_mutex_lock(&lock);
    file1 = fopen("out.txt","w");
    int i = 0,j = 0,k = 0;
    int flag = -1;
    FILE * file;
    file = fopen("wordlist.txt","r");
    while(fgets(word, sizeof(word), file)){
        ///printf("%s\n",word );
        while(thread3part[i] != '\0'){
            while(i<strlen(thread1part)){
                if(thread3part[i] == ' ' || thread3part[i] == '\0' || thread3part[i] == '\n'){
                    break;
                }

                ////copy word to third array
                arr[j++] = thread3part[i++];
            }
            arr[j] = '\0';
            j = 0;
            /////if word mached, flag turns true
            if(strstr(word,arr)){
                flag = 1;
            }
            i++;
        }
        ////write in file
        if(flag == 1){
            time_t t;
            time(&t);
            fprintf(file1, "%s", word);
            fprintf(file1,"this word hase been found at : %s", ctime(&t));
            fprintf(file1, "thread 3 found this word\n");
            time(&t);
            fprintf(file1, "time of writing in file %s\n",ctime(&t) );
            ///printf("%s found withh thread1\n", word);

        }
        flag = -1;
        k++;
        i = 0;

        k = 0;
    }
    pthread_mutex_unlock(&lock);
    return 0;
}

void *thread4Function(void* arg){
    pthread_mutex_lock(&lock);
    file1 = fopen("out.txt","w");
    int i = 0,j = 0,k = 0;
    int flag = -1;
    FILE * file;
    file = fopen("wordlist.txt","r");
    while(fgets(word, sizeof(word), file)){
        ///printf("%s\n",word );
        while(thread4part[i] != '\0'){
            while(i<strlen(thread4part)){
                if(thread4part[i] == ' ' || thread4part[i] == '\0' || thread4part[i] == '\n'){
                    break;
                }

                ////copy word to third array
                arr[j++] = thread4part[i++];
            }
            arr[j] = '\0';
            j = 0;
            /////if word mached, flag turns true
            if(strstr(word,arr)){
                flag = 1;
            }
            i++;
        }
        ////write in file
        if(flag == 1){
            time_t t;
            time(&t);
            fprintf(file1, "%s", word);
            fprintf(file1,"this word hase been found at : %s", ctime(&t));
            fprintf(file1, "thread 4 found this word\n");
            time(&t);
            fprintf(file1, "time of writing in file %s\n",ctime(&t) );
            ///printf("%s found withh thread1\n", word);

        }
        flag = -1;
        k++;
        i = 0;

        k = 0;
    }
    pthread_mutex_unlock(&lock);
    return 0;
}


int wordCount(){
    FILE * file;
    int count = 0;
    file = fopen("text.txt","r");
    char ch;
    while((ch = fgetc(file)) !=  EOF){
        if (ch == ' ' || ch == '\n')
            count++;
    }
    fclose(file);
    return count;
}

void threadpartstring(char arr1[], char arr2[], char arr3[], char arr4[], int count1, int count2, int count3, int count4){
    FILE * file;
    file = fopen("text.txt","r");
    int n = 0;
    char ch;
    int i = 0, j = 0;
    ////thread1part
    while(i < count1){
        ch = fgetc(file);
        arr1[j] = ch;
        if(ch == ' ' || ch == '\n')
            i++;
        j++;
    }
    ////thread2part
    i = 0;
    j = 0;
    while(i < count2){
        ch = fgetc(file);
        arr2[j] = ch;
        if(ch == ' ' || ch == '\n')
            i++;
        j++;
    }
    ////thread3part
    i = 0;
    j = 0;
    while(i < count3){
        ch = fgetc(file);
        arr3[j] = ch;
        if(ch == ' ' || ch == '\n')
            i++;
        j++;
    }
    ////thread4part
    i = 0;
    j = 0;
    while(i < count4){
        ch = fgetc(file);
        arr4[j] = ch;
        if(ch == ' ' || ch == '\n')
            i++;
        j++;
    }
    fclose(file);
}



int main(){

    int count;
    count = wordCount();
    pthread_t tid1,tid2,tid3,tid4;

    t1WCount = count/4;
    t2WCount = count/4;
    t3WCount = count/4;
    t4WCount = count - (3*count/4);

    threadpartstring(thread1part,thread2part,thread3part,thread4part,t1WCount,t2WCount,t3WCount,t4WCount);
    printf("%s\n", thread1part);
    printf("%s\n", thread2part);
    printf("%s\n", thread3part);
    printf("%s\n", thread4part);

    ///file1 = fopen("out.txt","w");

    pthread_create(&tid1,NULL,thread1Function,NULL);
    pthread_create(&tid2,NULL,thread2Function,NULL);
    pthread_create(&tid3,NULL,thread3Function,NULL);
    pthread_create(&tid4,NULL,thread4Function,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);

    return 0;
}