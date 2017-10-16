//
//  main.c
//  lab4
//
//  Created by 高旭 on 2017/10/16.
//  Copyright © 2017年 高旭. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include"linktable.h"
int Help(void);
int Info(void);
int Exit(void);
int Time(void);
#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10
static time_t t;
typedef struct DataNode
{
    char* cmd;
    char* desc;
    int (*handler)(void);
    tLinkTableNode *next;
}tDataNode;
void InitLinkTable(tLinkTable ** pLinkTable)
{
    *pLinkTable = CreateLinkTable();
    if(pLinkTable == NULL)
    {
        printf("tLinkTable is NULL!\n");
        exit(0);
    }
    tDataNode* node = (tDataNode*)malloc (sizeof(tDataNode));
    node->cmd = "help";
    node->desc = "List all command in this program";
    node->handler = Help;
    AddLinkTableNode(*pLinkTable, (tLinkTableNode*) node);
    node = (tDataNode*)malloc (sizeof(tDataNode));
    node->cmd = "info";
    node->desc = "Show information";
    node->handler = Info;
    AddLinkTableNode(*pLinkTable, (tLinkTableNode*) node);
    node = (tDataNode*)malloc (sizeof(tDataNode));
    node->cmd = "version";
    node->desc = "menu program v1.0";
    node->handler = NULL;
    AddLinkTableNode(*pLinkTable, (tLinkTableNode*) node);
    node = (tDataNode*)malloc (sizeof(tDataNode));
    node->cmd = "exit";
    node->desc = "Exit this program";
    node->handler = Exit;
    AddLinkTableNode(*pLinkTable, (tLinkTableNode*) node);
    node = (tDataNode*)malloc (sizeof(tDataNode));
    node->cmd = "time";
    node->desc = "Output system time";
    node->handler = Time;
    AddLinkTableNode(*pLinkTable, (tLinkTableNode*) node);
}
/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable *pLinkTable, char* cmd)
{
    tDataNode* pDataNode = (tDataNode*) GetLinkTableHead(pLinkTable);
    while(pDataNode != NULL)
    {
        if(strcmp(pDataNode->cmd, cmd) == 0)
        {
            return pDataNode;
        }
        pDataNode = (tDataNode*) GetNextLinkTableNode(pLinkTable, (tLinkTableNode*)pDataNode);
    }
    return NULL;
}
/* show all cmd in linklist */
void ShowAllCmd(tLinkTable *pLinkTable)
{
    printf("Menu List:\n");
    tDataNode* pDataNode = (tDataNode*) GetLinkTableHead(pLinkTable);
    while(pDataNode != NULL)
    {
        printf("\t%s - %s\n", pDataNode->cmd, pDataNode->desc);
        pDataNode = (tDataNode*) GetNextLinkTableNode(pLinkTable, (tLinkTableNode*)pDataNode);
    }
}
/*menu program*/
tLinkTable* head = NULL;
int main()
{
    InitLinkTable(&head);
     /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode* p = FindCmd(head, cmd);
        if(p == NULL)
        {
            printf("This is a wrong cmd!\n");
            continue;
        }
        printf("\t%s - %s\n", p->cmd, p->desc);
        if(p->handler != NULL)
        {
            p->handler();
        }
    }
}
int Help()
{
    ShowAllCmd(head);
    return 0;
}
int Info()
{
    printf("Author:Gao xu\nProgram Version:1.0\n");
    return 0;
}
int Exit()
{
    printf("Program exited\n");
    DeleteLinkTable(head);
    exit(0);
    return 0;
}
int Time()
{
    time_t t;
    time(&t);
    printf("The system time now is: %s\n",ctime(&t));
    return 0;
}
