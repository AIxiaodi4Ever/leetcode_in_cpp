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

// 思路：使用两个链表分别表示user和tweet，只有在user关注了其他user时才将其加入链表，并且在表头位置
// tweet同理，将最先发布的tweet放在表头。User里包含userid、关注的人followee及user-next，followee
// 使用数组散列表示，如果关注了user1则followee[1]=1. tweet里包含userid、tweetid与tweet_next。
// ******************************************************************************************
// twitterPostTweet()始终把最先发布的推文放在最前面。
// twitterGetNewsFeed()先遍历user链表查询该用户是否有关注的人，若没有则遍历tweet找出他的所以推文，
// 并按顺序放入Int数组，如果存在关注的人，则遍历tweet找出他及他关注的人的推文。
// twitterFollow()，先变量user链表，如果在链表中，则使其对应的followee为1。如果不在，先将其加入
// 链表头，再使其对应的followee为1。

// 单目运算符++与*自右向左结合，所以解除引用时需要加括号再++，如(*retSize)++。
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

struct User {
    int userid;
    int followee[MAX_SIZE];
    struct User *next;
};

struct tweet {
    int userid;
    int tweetid;
    struct tweet *next;
};

typedef struct {
    struct User *user;
    struct tweet *tweet;
} Twitter;

/** Initialize your data structure here. */
Twitter* twitterCreate() 
{
    Twitter *twitter = (Twitter *)malloc(sizeof(Twitter));
    twitter->user = (struct User *)malloc(sizeof(struct User));
    twitter->user->next = NULL;
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
    twe->next = obj->tweet->next;     // 保证最新的tweet在最前面
    obj->tweet->next = twe;
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. 
 * Each item in the news feed must be posted by users who the user 
 * followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) 
{
    struct User *user = obj->user->next;
    struct tweet *tweet = obj->tweet->next;
    int *newsfeed = (int *)calloc(10, sizeof(int));
    *retSize = 0;
    // 查询用户是否有关注的人
    while(user && user->userid != userId)
    {
        user = user->next;
    }
    if (user == NULL)   // 没有，查找所有他自己的推文
    {
        while (tweet && *retSize < 10)
        {
            if (tweet->userid == userId)
            {
                newsfeed[(*retSize)++] = tweet->tweetid;
            }
            tweet = tweet->next;
        }
    }
    else                // 存在，查找所以他以及他关注的人的推文
    {
        while (tweet && *retSize < 10)
        {
            if (tweet->userid == userId || user->followee[tweet->userid] == 1)
            {
                // 根据单目运算符结合规律，需要加括号
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
    struct User *user = obj->user->next;
    while (user && user->userid != followerId)
    {
        user = user->next;
    }
    if (user == NULL)           // 用户不在链表中，创建新user，使followee为1，并将其添加至表头
    {
        struct User *u = (struct User *)malloc(sizeof(struct User));
        u->userid = followerId;
        u->followee[followeeId] = 1;
        u->next = obj->user->next;
        obj->user->next = u;
    }
    else                        // 存在，使对应的followee为1
    {
        user->followee[followeeId] = 1;
    }
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) 
{
    struct User *user = obj->user->next;
    while (user && user->userid != followerId)
    {
        user = user->next;
    }
    if (user)       // 如果该用户没有关注任何人，则他不在用户链表中
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