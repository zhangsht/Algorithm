LinkedListNode* reverseLinkedList(LinkedListNode* head){
    ListNode* pNode = head;  
    ListNode* pPrev = NULL;  

    while (pNode != NULL){  
        ListNode* pNext = pNode->m_pNext;    //保存下一个节点的值
        pNode->m_pNext = pPrev;    //把当前pNode的下一个节点指向pPrev  
        pPrev = pNode;    //此时pPrev向后移动指向此时的pNode
        pNode = pNext;    //而pNode也向后移动，指向刚才保存的pNext;  
    }  
    return pPrev;
}