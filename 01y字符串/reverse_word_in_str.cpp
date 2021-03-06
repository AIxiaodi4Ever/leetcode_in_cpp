void reverse(char *s, int start, int end) {
    char temp;
    while (start < end) {
        temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

void trimSpace(char *s, int start) {
    // ���м����Ŀո��Ƶ����ͬʱ���ַ���������\0��ǰ��һ��
    do {
        s[start] = s[start+1];
        start++;
    } while (s[start]);  // ���ַ���������ֹͣ
}

char * reverseWords(char * s){
    // 1.����ǰ�����ո�
    while (*s == ' ') s++;
    // 2.��������Ŀո��ҳ���-1
    int len = strlen(s) - 1;
    if (len < 0) return s;
    while (s[len] == ' ') {
        s[len] = '\0';
        len--;
    }
    reverse(s, 0, len);  // ���巭ת

    // 3.�����м����ո񲢷�ת�ֲ�
    int i, idx = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {  // �����ո��ʾ���ʽ���
            reverse(s, idx, i - 1);  // ע������[idx,i-1]�ǵ���
            // ׼��ɾ���ڶ����ո�
            while (s[i+1] && s[i+1] == ' ') {
                trimSpace(s, i + 1);
                len--;  // �޸��ַ����鳤��
            }
            idx = i + 1;  // ���idx�Ƶ��µĵ��ʿ�ͷ����
        }
    }
    // ������󵥴�
    reverse(s, idx, len);
    return s;
}