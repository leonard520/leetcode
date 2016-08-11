/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

int lengthOfLongestSubstring(char* s) {
	int dict[256];
	memset(dict, -1, sizeof(dict));
	int max = 0;
	int begin = 0;
	int i = 0;
    while(*s){
    	if(dict[*s] >= begin){
    		if(i - begin > max){
    			max = i - begin;
    		}
    		begin = dict[*s] + 1;
    	} else {
    		if(i - begin + 1 > max){
    			max = i - begin + 1;
    		}
    	}

    	dict[*s] = i;
    	i++;
    	s++;
    }
    
    return max;
}