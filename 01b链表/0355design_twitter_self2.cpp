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
// 把题解中的user链表改成了user数组。
// 思路：使用链表表示tweet，最新发布的推文在表头，使用user数组保存用户及其关注的人。
// User里包含userid、关注的人followee
// 使用数组散列表示，如果关注了user1则followee[1]=1. tweet里包含userid、tweetid与tweet_next。
// ******************************************************************************************
// twitterPostTweet()始终把最先发布的推文放在最前面。
// twitterGetNewsFeed()遍历tweet找出他及他关注的人的推文，并放入newsfeed数组。
// twitterFollow()，使user数组中，对应的userid中，对应followee[followeeId]为1.

// 单目运算符++与*自右向左结合，所以解除引用时需要加括号再++，如(*retSize)++。

// 并没有加快速度，猜测应为calloc的时间抵消了减少遍历链表的时间
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

// 改用User数组保存用户及其关注的人
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
    twe->next = obj->tweet->next;     // 保证最新的tweet在最前面
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
    if (user)           // 如果该用户没有关注任何人，则他不在用户链表中
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