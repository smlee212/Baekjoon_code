int perfectSubstring(string s, int k) {
    int res = 0;
    unsigned int sizes = s.size();
    for(unsigned int i=0;i<sizes-k+1;i++){
        int num[10] = {0,};
        int cntNum = 0, cntPerfect = 0;        
        for(unsigned int j=i;j<sizes;j++){
            num[s[j] - '0']++;
            if(num[s[j] - '0'] == 1){ // 해당 숫자가 없었다면            
                cntNum++; // 숫자의 종류를 늘려준다.
                if(k == 1) cntPerfect++; // k == 1일 경우 함께 처리해준다.           
            }
            else if(num[s[j] - '0'] == k){ // 완전한 상태가 됐다면
                cntPerfect++;
            }
            else if(num[s[j] - '0'] > k){ // 완전한 상태에서 벗어났다면
                break;
            }
            
            if(cntNum == cntPerfect){ // 숫자의 개수와 그 숫자들이 완변한 상태일 경우
                res++;
            }
        }
    }    
    
    return res;
}