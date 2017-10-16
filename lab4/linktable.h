//
//  linktable1.h
//  lab4
//
//  Created by 高旭 on 2017/10/16.
//  Copyright © 2017年 高旭. All rights reserved.
//

#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_
/*Linktable Node  Type*/
typedef struct LinkTableNode
{
    struct LinkTableNode* next;
}tLinkTableNode;
/*Linktable Node  Type*/
typedef struct LinkTable
{
    tLinkTableNode *head;
    int nodeCount;
}tLinkTable;
/*Create a LinkTable*/
tLinkTable* CreateLinkTable(void);
/*Delete a LinkTable*/
int DeleteLinkTable(tLinkTable* pLinkTable);
/*Add a LinkTableNode to LinkTable*/
int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);
/*Delete a LinkTableNode from LinkTable*/
int DelLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);
/*Get LinkTableHead*/
tLinkTableNode* GetLinkTableHead(tLinkTable* pLinkTable);
/*Get next LinkTableNode*/
tLinkTableNode* GetNextLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);
#endif /* linktable_h */

