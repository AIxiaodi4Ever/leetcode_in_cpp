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
// ������е�user����ĳ���user���顣
// ˼·��ʹ�������ʾtweet�����·����������ڱ�ͷ��ʹ��user���鱣���û������ע���ˡ�
// User�����userid����ע����followee
// ʹ������ɢ�б�ʾ�������ע��user1��followee[1]=1. tweet�����userid��tweetid��tweet_next��
// ******************************************************************************************
// twitterPostTweet()ʼ�հ����ȷ��������ķ�����ǰ�档
// twitterGetNewsFeed()����tweet�ҳ���������ע���˵����ģ�������newsfeed���顣
// twitterFollow()��ʹuser�����У���Ӧ��userid�У���Ӧfollowee[followeeId]Ϊ1.

// ��Ŀ�����++��*���������ϣ����Խ������ʱ��Ҫ��������++����(*retSize)++��

// ��û�мӿ��ٶȣ��²�ӦΪcalloc��ʱ������˼��ٱ��������ʱ��
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

struct User {
    int userid;
    int followee[MAX_SIZE];
};

struct tweet {
    int userid;
    int tweetid;
    struct tweet *next;
};

// ����User���鱣���û������ע����
typedef struct {
    struct User **user;
    struct tweet *tweet;
} Twitter;

/** Initialize your data structure here. */
Twitter* twitterCreate() 
{
    Twitter *twitter = (Twitter *)malloc(sizeof(Twitter));
    twitter->user = (struct User **)calloc(1024, sizeof(struct User *));
    twitter->tweet = (struct tweet *)malloc(sizeof(struct tweet));
    twitter->tweet->next = NULL;
    return twitter;
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) 
{
    struct tweet *twe = (struct tweet *)malloc(sizeof(struct tweet));
    twe->tweetid = tweetId;
    twe->userid = userId;
    twe->next = obj->tweet->next;     // ��֤���µ�tweet����ǰ��
    obj->tweet->next = twe;
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. 
 * Each item in the news feed must be posted by users who the user 
 * followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) 
{
    struct User *user = obj->user[userId];
    struct tweet *tweet = obj->tweet->next;
    int *newsfeed = (int *)calloc(10, sizeof(int));
    *retSize = 0;
    if (user == NULL)
    {
        while(tweet && *retSize < 10)
        {
            if (tweet->userid == userId)
            {
                newsfeed[(*retSize)++] = tweet->tweetid;
            }
            tweet = tweet->next;
        }
    }
    else
    {
        while (tweet && *retSize < 10)
        {
            if (tweet->userid == userId || user->followee[tweet->userid] == 1)
            {
                // ���ݵ�Ŀ�������Ϲ��ɣ���Ҫ������
                newsfeed[(*retSize)++] = tweet->tweetid;
            }
            tweet = tweet->next;
        }
    }
    
    return newsfeed;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) 
{
    struct User *user = obj->user[followerId];
    if (user == NULL)
    {
        user = (struct User *)malloc(sizeof(struct User));
        user->userid = followerId;
        obj->user[followerId] = user;
    }
        user->followee[followeeId] = 1;

}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) 
{
    struct User *user = obj->user[followerId];
    if (user)           // ������û�û�й�ע�κ��ˣ����������û�������
    {
        user->followee[followeeId] = 0;
    }
}

void twitterFree(Twitter* obj) 
{
    if (obj && obj->user)
        free(obj->user);
    if (obj && obj->tweet)
        free(obj->tweet);
    if (obj)
        free(obj);
}

/**
 * Your Twitter struct will be instantiated and called as such:
 * Twitter* obj = twitterCreate();
 * twitterPostTweet(obj, userId, tweetId);
 
 * int* param_2 = twitterGetNewsFeed(obj, userId, retSize);
 
 * twitterFollow(obj, followerId, followeeId);
 
 * twitterUnfollow(obj, followerId, followeeId);
 
 * twitterFree(obj);
*/