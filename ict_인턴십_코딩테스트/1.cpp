long getNumber(SinglyLinkedListNode* binary) {
    long dec = 0; // 반환할 10진수 값
    int cnt = 0; // 2진수 자리수
    SinglyLinkedListNode *temp;
    for(temp = binary;temp!=NULL;temp=temp->next) cnt++; // 자리수 확인
    
    for(temp = binary;temp!=NULL;temp=temp->next){
        cnt--;
        dec += (temp->data == 1) ? long(pow(2,cnt)) : 0; // 각 자리수마다 10진수로 변환
    }
    
    return dec;
}