
long maxInversions(vector<int> arr) {
    long res = 0;
    unsigned int sizeArr = arr.size(); // arr size
    
    if(sizeArr < 3) return 0; // 원소 개수가 3개보다 적으면 무시
    
    bool numi[1000001] = {0,};
    for(int i=0;i<sizeArr-2;i++){
        if(numi[i]) continue;
        bool numj[1000001] = {0,};
        for(int j=i+1;j<sizeArr-1;j++){
            if((arr[i] < arr[j])||(numj[j])) continue;
            numj[j] = true;
            bool numk[1000001] = {0,};
            for(int k=j+1;k<sizeArr;k++){
                if((arr[j] < arr[k])||(numk[k])) continue;
                numk[k] = true;
                res++;
            }
        }
    }
    
    return res;
}

long maxInversions(vector<int> arr) {
    long res = 0; // 반환할 inversion의 개수
    unsigned int sizeArr = arr.size(); // arr size
    
    // p[j](arr[i])를 기준으로 좌, 우의 원소를 탐색
    // p[i](great), p[j](arr[i]), p[k](small)
    // great와 small의 원소 개수를 구한 후 곱해주면 원하는 결과를 얻을 수 있다.
    for (int i=1; i<sizeArr-1; i++) // p[j]를 기준으로 탐색하므로 i = 1부터 시작한다.
    {  
        int small = 0; // p[k]로 가능한 원소들을 카운팅
        for (int j=i+1; j<sizeArr; j++) 
            if (arr[i] > arr[j]) // p[j] > p[k]일 경우 카운팅한다.
                small++;
  
        int great = 0; // p[i]로 가능한 원소들을 카운팅
        for (int j=i-1; j>=0; j--) 
            if (arr[i] < arr[j]) // p[i] > p[j]일 경우 카운팅한다.
                great++;
                
        res += great*small;
    } 
  
    return res; 
}