#include <pthread.h>
#include <stdlib.h>

/* C�����ò���sem_t��û�취ֻ����mutex������
��������h�߳���t2������ӡ���κ��ͷ�t1������O�߳�
O�߳���t1������ӡ���ͷ�t2�����ٵ���һ��h�̵߳�t1���ͷ� */

// #include <pthread.h>�÷���www.xuebuyuan.com/zh-hant/1815855.html

typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t t1;
    pthread_mutex_t t2;
    int i;
} H2O;

H2O* h2oCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    
    // Initialize user defined data here.
    pthread_mutex_init(&obj->t1, NULL);
    pthread_mutex_init(&obj->t2, NULL);
    obj->i = 0;
    return obj;
}

void hydrogen(H2O* obj) {
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    pthread_mutex_lock(&obj->t2);
    releaseHydrogen();
    obj->i++;
    if (obj->i == 2) {
        pthread_mutex_unlock(&obj->t1);
        obj->i = 0;
    }
    else
        pthread_mutex_unlock(&obj->t2);
}

void oxygen(H2O* obj) {
    
    // releaseOxygen() outputs "O". Do not change or remove this line.
    pthread_mutex_lock(&obj->t1);
    releaseOxygen();
    
    pthread_mutex_unlock(&obj->t2);
}

void h2oFree(H2O* obj) {
    // User defined data may be cleaned up here.
    free(obj);
}
