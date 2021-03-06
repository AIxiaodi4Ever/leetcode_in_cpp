/*通过递归调用模拟压栈和出栈，
遍历字符串，分为几种情况：

    遇到字母，则保存至缓存中；
    遇到数字，则更新计数值；
    遇到"["，递归调用，将递归调用返回的结果复制N次到结果中；
    遇到"]", 保存当前字符串指针所在的位置，并返回结果。

作者：inumo
链接：https://leetcode-cn.com/problems/decode-string/solution/cyu-yan-di-gui-shi-xian-by-inumo/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#define STR_LEN 5000
char * decodeStringCore(char *s, char **e) {
    char *ret = (char*)malloc(sizeof(char) * STR_LEN);
    char *buf, *end = NULL;
    int count = 0, idx = 0;

    while(*s != '\0') {
        if (isalpha(*s)) {
            ret[idx++] = *s;
        } else if (isdigit(*s)) {
            count = 10 * count + *s - '0';
        } else if (*s == '[') {
            buf = decodeStringCore(s + 1, &end);
            while (count) {
                strcpy(ret + idx, buf);
                idx += strlen(buf);
                count--;
            }
            s = end;
        } else if (*s == ']') {
            *e = s;
            ret[idx] = '\0';
            return ret;
        }
        s++;
    }
    ret[idx] = '\0';
    return ret;
}

char * decodeString(char * s){
    char *end = NULL;
    return decodeStringCore(s, &end);
}
