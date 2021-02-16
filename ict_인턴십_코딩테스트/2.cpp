vector<string> funWithAnagrams(vector<string> text) {
    vector<string> res; // 반환 벡터
    vector<vector<string>> sortedAnagram(1001); // 정렬된 아나그램(행은 text의 길이, 열은 해당 길이의 문자)
    
    unsigned int cntText = text.size(); // text의 총 개수    
    for(unsigned int i=0;i<cntText;i++){        
        string str = text[i]; // 비교할 문자
        unsigned int sizeStr = str.size(); // 비교할 문자의 길이
        bool check = false; 
        
        sort(str.begin(), str.end());
        
        if(!sortedAnagram[sizeStr].empty()){ // text의 길이와 동일한 문자가 있다면 anagram인지 확인해야 한다.
            string strA; // 정렬된 아나그램            
            unsigned int sizeAna = sortedAnagram[sizeStr].size(); // text의 길이와 동일한 아나그램의 개수
            for(unsigned int index = 0;index<sizeAna;index++){ // 길이가 같은 모든 정렬된 아나그램에 대해 비교한다.
                strA = sortedAnagram[sizeStr][index];
                if(str==strA){ // 비교할 문자가 정렬된 아나그램과 같은지 확인한다.
                    check = true;
                    break;
                }
            }
        }
        if(check) continue; 
        
        // 비교할 문자가 정렬된 아나그램과 같지 않다면 새로운 문자이므로 추가해준다.
        res.push_back(text[i]); // 결과 벡터에는 원형 그대로 추가한다. 
        sortedAnagram[sizeStr].push_back(str);      
    }
    sort(res.begin(), res.end());
    return res;
}