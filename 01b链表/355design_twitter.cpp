// leetcode:355
/* 
    Design a simplified version of Twitter where users can post tweets, follow/unfollow another user 
 and is able to see the 10 most recent tweets in the user's news feed. Your design should support 
 the following methods:

        1.postTweet(userId, tweetId): Compose a new tweet.
        2.getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in 
    the news feed must be posted by users who the user followed or by the user herself. Tweets must be 
    ordered from most recent to least recent.
        3.follow(followerId, followeeId): Follower follows a followee.
        4.unfollow(followerId, followeeId): Follower unfollows a followee.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

struct User {
  int id;                  //�û�id
  int followee[MAX_SIZE];  //���������ɢ�У��±�Ϊ��ע���û�id��Ԫ��ֵ��1Ϊ��ע��0Ϊδ��ע��
  struct User* next;
};

struct Tweet {
  int userId;   //�û�id
  int tweetId;  //����id
  struct Tweet* next;
};

typedef struct {
  struct User* user;
  struct Tweet* tweet;
} Twitter;

/** Initialize your data structure here. */
Twitter* twitterCreate() {
  Twitter* twitter = (Twitter*)malloc(sizeof(Twitter));
  twitter->user = (struct User*)malloc(sizeof(struct User));
  twitter->user->next = NULL;
  twitter->tweet = (struct Tweet*)malloc(sizeof(struct Tweet));
  twitter->tweet->next = NULL; 
  return twitter;
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
  struct Tweet* tweet = (struct Tweet*)malloc(sizeof(struct Tweet));
  tweet->userId = userId;
  tweet->tweetId = tweetId;
  tweet->next = obj->tweet->next;  //ͷ�巨,��֤��󷢲�����������ǰ��
  obj->tweet->next = tweet;
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
  int* ret = (int*)calloc(10, sizeof(int));
  *retSize = 0;
  struct Tweet* tweet = obj->tweet->next;
  struct User* user = obj->user->next;
  while (user && user->id != userId) user = user->next;  //�����û����
  if (user == NULL) {                                    //δ�ҵ�����ǰ�û�δ��ע�κ��û�
    while (tweet && *retSize < 10) {
      if (tweet->userId == userId)  //�û��Լ���������
        ret[(*retSize)++] = tweet->tweetId;
      tweet = tweet->next;
    }
    return ret;
  }
  while (tweet && *retSize < 10) {
    if (tweet->userId == userId || user->followee[tweet->userId] == 1)  //�û��Լ����û���ע���˵�����
      ret[(*retSize)++] = tweet->tweetId;
    tweet = tweet->next;
  }
  return ret;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) {
  struct User* u = obj->user;
  while (u->next && u->id != followerId) u = u->next;  //�û��������Ƿ���ڵ�ǰ�û�
  if (u->id == followerId)                             //���ڣ�����ע���û�idɢ�е������У���ע(1)
    u->followee[followeeId] = 1;
  else {  //�����ڣ��½��û���㣬��ע(1)��ͷ�巨�����û�����
    struct User* user = (struct User*)malloc(sizeof(struct User));
    user->id = followerId;
    user->followee[followeeId] = 1;
    user->next = obj->user->next;
    obj->user->next = user;
  }
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
  struct User* u = obj->user;
  while (u->next && u->id != followerId) u = u->next;  //�û��������Ƿ���ڵ�ǰ�û�
  if (u->id == followerId)                             //���ڣ�ȡ����ע(0)
    u->followee[followeeId] = 0;
}

void twitterFree(Twitter* obj) {
  if (obj && obj->user) free(obj->user);
  if (obj && obj->tweet) free(obj->tweet);
  if (obj) free(obj);
}
