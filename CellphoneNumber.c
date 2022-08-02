#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MAX_NUM 200 //유지보수를 위한 메크로

typedef struct
{
    char name[30];
    char number[30];
    char address[30];
} User; // 별명은 User

void add(User *ptr, int *num);      //연락처 추가를 위한 함수
void check(User *ptr, int *num);    // 누군가의 연락처를 찾는 함수
void delete (User *ptr, int *num);  // 누군가의 연락처를 지우는 함수
void printall(User *ptr, int *num); // 모든 연락처 출력

int main(void)
{
    int person = 0; //연락처에 있는 인원 수
    User user[MAX_NUM];
    int choice; //메뉴에서 무엇을 선택할지
    char address;
    while (1)
    {
        printf(" -------------------------\n");
        printf("   전화번호부 관리 시스템    \n");
        printf("                        \n");
        printf("    1. 연락처 등록         \n");
        printf("    2. 연락처 확인         \n");
        printf("    3. 연락처 삭제         \n");
        printf("    4. 전체 연락처         \n");
        printf("    5. 종료              \n");
        printf("                        \n");
        printf(" -------------------------\n");
        printf("choice your item : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            add(user, &person);
        }
        if (choice == 2)
        {
            check(user, &person);
        }
        if (choice == 3)
        {
            delete (user, &person);
        }
        if (choice == 4)
        {
            printall(user, &person);
        }
        if (choice == 5)
        {
            printf("\n[exit]\n");
            return 0;
        }
    }
}

void add(User *ptr, int *num)
{
    if (*num < MAX_NUM)
    {
        printf("\n[INSERT] \n");
        printf("INPUT NAME : \n");
        scanf("%s", ptr[*num].name);
        printf("INPUT NUMBER : \n");
        scanf("%s", ptr[*num].number);
        printf("INPUT ADDRESS : \n");
        scanf("%s", ptr[*num].address);
        (*num)++; // 연락처에 있는 사람 수 늘리기
        printf(" SUCCESS !! \n");
    }
    else
    {
        printf(" Data Full \n\n "); // 연락처에 저장 가능한 인원을 넘었을 때
    }
}
void check(User *ptr, int *num)
{
    char name[30];
    int i;

    if (*num > 0)
    {
        printf("Input Name : ");
        scanf("%s", name);

        for (i = 0; i < MAX_NUM; i++)
        {
            if (!strcmp(name, ptr[i].name)) //비교하는 함수 strcmp
            {
                printf("Name:%s\n", ptr[i].name);
                printf("Tel:%s\n", ptr[i].number);
                printf("Address:%s\n", ptr[i].address);
                printf(" Data Found !!\n\n");
            }
        }
        printf("\n\n");
    }
    else
    {
        printf(" No Data \n\n"); //찾는 사람의 연락처가 없을 경우
    }
}

void delete (User *ptr, int *num)
{
    char name[30];
    int i, j;

    if (*num > 0) //연락처가 하나라도 있을 경우
    {
        printf("Input Name : \n");
        scanf("%s", name);

        for (i = 0; i < MAX_NUM; i++)
        {
            if (strcmp(name, ptr[i].name) == 0) // strcmp는 true의 경우 0
            {
                (*num)--; //지웠으니 사람 수 줄이기
                printf(" Data Deleted !!\n\n");
            }
        }
    }
    else //연락처가 하나도 없을 경우
        printf("No Data");
}

void printall(User *ptr, int *num)
{
    int i = 0;

    if (*num > 0) // 한명이라도 있을경우
    {
        for (i = 0; i < *num; i++)
        {
            printf("Name : %s\n", ptr[i].name);
            printf("Number : %s\n", ptr[i].number);
            printf("Address : %s\n", ptr[i].address);
            printf("\n\n");
        }
        printf(" Data Print\n\n");
    }
    else
        printf("No Data\n\n");
}