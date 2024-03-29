#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <semaphore.h>

char thread1part[100000],thread2part[100000],thread3part[100000],thread4part[100000];
int thread1line[100000],thread2line[100000],thread3line[100000],thread4line[100000];
int t1WCount,t2WCount,t3WCount,t4WCount;
char word[100];
char arr[100];
sem_t  mutex;
FILE * file1;
pthread_mutex_t lock;

void *thread1Function(void* arg){
    //pthread_mutex_lock(&lock);
    sem_wait(&mutex);
    //file1 = fopen("semaphoreout.txt","w");
    int i = 0,j = 0;
    int flag = -1;
    FILE * file;
    file = fopen("wordlist.txt","r");
    while(fgets(word, sizeof(word), file)){
        ///printf("%s\n",word );
        while(thread1part[i] != '\0'){
            while(i<strlen(thread1part)){
                if(thread1part[i] == ' ' || thread1part[i] == '\0' || thread1part[i] == '\n' ){
                    break;
                }

                ///printf("%c\n",thread2part[i]);

                ////copy word to third array
                arr[j++] = thread1part[i++];
            }
            arr[j] = '\0';
            j = 0;
            // printf("%s\n", arr);
            // printf("%s", word);
            /////if word mached, flag turns true
            if(strstr(word,arr)){
                flag = 1;
            }
            if(flag == 1){
                time_t t;
                time(&t);
                fprintf(file1, "1-word: %s - time: %s - line : %c\n", word,ctime(&t),thread1line[i]);
                // fprintf(file1,"this word has been found at : %s", ctime(&t));
                // fprintf(file1, "thread 1 found this word\n");
                // time(&t);
                // fprintf(file1, "time of writing in file %s",ctime(&t) );
                // fprintf(file1, "this word is at line number %c\n", thread1line[i]);
                ///printf("%s found withh thread1\n", word);

            }
            // printf("%d\n\n", flag);
            flag = -1;
            i++;
        }
        ////write in file
        
        i = 0;

    }
    sem_post(&mutex);
    //pthread_mutex_unlock(&lock);
    // return 0;
}

void *thread2Function(void* arg){
    sem_wait(&mutex);
    //pthread_mutex_lock(&lock);
    //file1 = fopen("semaphoreout.txt","w");
    int i = 0,j = 0;
    int flag = -1;
    FILE * file;
    file = fopen("wordlist.txt","r");
    while(fgets(word, sizeof(word), file)){
        ///printf("%s\n",word );
        while(thread2part[i] != '\0'){
            while(i<strlen(thread2part)){
                if(thread2part[i] == ' ' || thread2part[i] == '\0' || thread2part[i] == '\n' ){
                    break;
                }

                ///printf("%c\n",thread2part[i]);

                ////copy word to third array
                arr[j++] = thread2part[i++];
            }
            arr[j] = '\0';
            j = 0;
            // printf("%s\n", arr);
            // printf("%s", word);
            /////if word mached, flag turns true
            if(strstr(word,arr)){
                flag = 1;
            }
            if(flag == 1){
                time_t t;
                time(&t);
                fprintf(file1, "2-word: %s - time: %s - line : %c\n", word,ctime(&t),thread2line[i]);
                // fprintf(file1, "%s", word);
                // fprintf(file1,"this word has been found at : %s", ctime(&t));
                // fprintf(file1, "thread 2 found this word\n");
                // time(&t);
                // fprintf(file1, "time of writing in file %s",ctime(&t) );
                // fprintf(file1, "this word is at line number %c\n", thread2line[i]);                
                ///printf("%s found withh thread1\n", word);

            }
            // printf("%d\n\n", flag);
            flag = -1;
            i++;
        }
        ////write in file
        
        i = 0;

    }
    sem_post(&mutex);
    //pthread_mutex_unlock(&lock);
    // return 0;
}

void *thread3Function(void* arg){
    sem_wait(&mutex);
    //pthread_mutex_lock(&lock);
    //file1 = fopen("semaphoreout.txt","w");
    int i = 0,j = 0;
    int flag = -1;
    FILE * file;
    file = fopen("wordlist.txt","r");
    while(fgets(word, sizeof(word), file)){
        ///printf("%s\n",word );
        while(thread3part[i] != '\0'){
            while(i<strlen(thread3part)){
                if(thread3part[i] == ' ' || thread3part[i] == '\0' || thread3part[i] == '\n' ){
                    break;
                }

                ///printf("%c\n",thread2part[i]);

                ////copy word to third array
                arr[j++] = thread3part[i++];
            }
            arr[j] = '\0';
            j = 0;
            // printf("%s\n", arr);
            // printf("%s", word);
            /////if word mached, flag turns true
            if(strstr(word,arr)){
                flag = 1;
            }
            if(flag == 1){
                time_t t;
                time(&t);
                fprintf(file1, "3-word: %s - time: %s - line : %c\n", word,ctime(&t),thread3line[i]);
                // fprintf(file1, "%s", word);
                // fprintf(file1,"this word has been found at : %s", ctime(&t));
                // fprintf(file1, "thread 3 found this word\n");
                // time(&t);
                // fprintf(file1, "time of writing in file %s",ctime(&t) );
                // fprintf(file1, "this word is at line number %c\n", thread3line[i]);                ///printf("%s found withh thread1\n", word);

            }
            // printf("%d\n\n", flag);
            flag = -1;
            i++;
        }
        ////write in file
        
        i = 0;

    }
    sem_post(&mutex);
    //pthread_mutex_unlock(&lock);
    
}

void *thread4Function(void* arg){
    sem_wait(&mutex);
    //pthread_mutex_lock(&lock);
    //file1 = fopen("semaphoreout.txt","w");
    int i = 0,j = 0;
    int flag = -1;
    FILE * file;
    file = fopen("wordlist.txt","r");
    while(fgets(word, sizeof(word), file)){
        ///printf("%s\n",word );
        while(thread4part[i] != '\0'){
            while(i<strlen(thread4part)){
                if(thread4part[i] == ' ' || thread4part[i] == '\0' || thread4part[i] == '\n' ){
                    break;
                }

                ///printf("%c\n",thread2part[i]);

                ////copy word to third array
                arr[j++] = thread4part[i++];
            }
            arr[j] = '\0';
            j = 0;
            // printf("%s\n", arr);
            // printf("%s", word);
            /////if word mached, flag turns true
            if(strstr(word,arr)){
                flag = 1;
            }
            if(flag == 1){
                time_t t;
                time(&t);
                fprintf(file1, "4-word: %s - time: %s - line : %c\n", word,ctime(&t),thread4line[i]);
                // fprintf(file1, "%s", word);
                // fprintf(file1,"this word has been found at : %s", ctime(&t));
                // fprintf(file1, "thread 4 found this word\n");
                // time(&t);
                // fprintf(file1, "time of writing in file %s",ctime(&t) );
                // fprintf(file1, "this word is at line number %c\n", thread4line[i]);                ///printf("%s found withh thread1\n", word);

            }
            //printf("%d\n\n", flag);
            flag = -1;
            i++;
        }
        ////write in file
        
        i = 0;

    }
    //sem_post(&mutex);
    pthread_mutex_unlock(&lock);
    
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
    int line = 1;
    ////thread1part
    while(i < count1){
        ch = fgetc(file);
        arr1[j] = ch;
        if(ch == ' ' || ch == '\n')
            i++;
        if(ch == '\n'){
            line++;
            ///printf("%d\n",line);
        }
        thread1line[j] = line + '0';
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
        if(ch == '\n'){
            line++;
            ///printf("%d\n",line);
        }
        thread2line[j] = line + '0';
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
        if(ch == '\n'){
            line++;
            ///printf("%d\n",line);
        }
        thread3line[j] = line + '0';
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
        if(ch == '\n'){
            line++;
            ///printf("%d\n",line);
        }
        thread4line[j] = line + '0';
        j++;
    }
    fclose(file);
}

// int my_strcmp(const char *a, const char *b)
// {
//     while (*a && *a == *b) { 
//         ++a;
//         ++b;
//     }
//     return (int)(unsigned char)(*a) - (int)(unsigned char)(*b);
// }


int main(){

    int count;
    count = wordCount();
    pthread_t tid1,tid2,tid3,tid4;

    t1WCount = count/4;
    t2WCount = count/4;
    t3WCount = count/4;
    t4WCount = count - (3*count/4);

    sem_init(&mutex,0,1);


    threadpartstring(thread1part,thread2part,thread3part,thread4part,t1WCount,t2WCount,t3WCount,t4WCount);
    // printf("1111%s\n", thread1part);
    // printf("2222%s\n", thread2part);
    // printf("3333%s\n", thread3part);
    // printf("4444%s\n", thread4part);

    file1 = fopen("semaphoreout.txt","w");

    pthread_create(&tid1,NULL,thread1Function,NULL);
    ///sleep(1);
    pthread_create(&tid2,NULL,thread2Function,NULL);
    ///sleep(1);
    pthread_create(&tid3,NULL,thread3Function,NULL);
    ///sleep(1);
    pthread_create(&tid4,NULL,thread4Function,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);

    fclose(file1);
    return 0;
}