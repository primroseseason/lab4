//
//  linktable.c
//  lab4
//
//  Created by 高旭 on 2017/10/16.
//  Copyright © 2017年 高旭. All rights reserved.
//

#include"linktable.h"
#include<stdlib.h>
tLinkTable* CreateLinkTable()
{
    tLinkTable* linkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    linkTable->head = NULL;
    linkTable->nodeCount = 0;
    return linkTable;
}
int DeleteLinkTable(tLinkTable* pLinkTable)
{
    tLinkTableNode* p;
    tLinkTableNode* q;
    p = pLinkTable->head;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    free(pLinkTable);
    return 1;
}
int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    tLinkTableNode* p = pLinkTable->head;
    pLinkTable->head = pNode;
    pNode->next = p;
    pLinkTable->nodeCount++;
    return 1;
}
int DelLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    tLinkTableNode* p;
    tLinkTableNode* q;
    if(pLinkTable->head == pNode)
    {
        q = pNode;
        pLinkTable->head = pNode->next;
        free(pNode);
        return 0;
    }
    else
    {
        p = pLinkTable->head;
        while(p->next != NULL && p->next != pNode)
        {
            p = p->next;
        }
        if(p == NULL)
        {
            return 0;
        }
        else
        {
            q = p->next;
            p->next = q->next;
            free(q);
            return 1;
        }
    }
}
tLinkTableNode* GetLinkTableHead(tLinkTable* pLinkTable)
{
    return pLinkTable->head;
}
tLinkTableNode* GetNextLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    tLinkTableNode* p = pLinkTable->head;
    while(p != NULL && p != pNode)
    {
        p = p->next;
    }
    if(p != NULL)
    {
        return p->next;
    }
    return NULL;
}

