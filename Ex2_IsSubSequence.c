//
//  Is Subsequence
//  https://leetcode.com/problems/is-subsequence/submissions/
//
//

#include <stdio.h>

/*get string's length*/
int getLength(char *str)
{
    int size = 0;
    char *tmp = str;
    while ((*tmp) != '\0') {
        size++;
        tmp++;
    }
    return size;
}


int isSubsequence(char * s, char * t){
    //special cases.
    if ((*s) == '\0') {
        return 1;
    }
    if ((*t == '\0')
            || (getLength(t) < getLength(s))) {
        return 0;
    }

    //pointer to iterate
    char* iterate_s = s;
    char* iterate_t = t;
    //iterate through t string.
    while((*iterate_t) != '\0') {
        if ((*iterate_t) == (*iterate_s)) {
            iterate_s++;
            //we can arrive to the end of s, then s is subsequence of t
            if ((*iterate_s) == '\0') {
                return 1;
            }
        }
        iterate_t++;
    }

    //end of t but not end of s
    return 0;

}

int main(int argc, const char * argv[]) {
    char s[] = "abc";
    char t[] = "ahbgdc";
    printf ("s: %s, t: %s. Check isSequence return %d\n ", s, t, isSubsequence(s, t));
    
    return 1;
}
