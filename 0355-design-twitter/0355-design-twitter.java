class Twitter {
    class Tweet{
        int Id;
        int time;

        Tweet(int Id, int time){
            this.Id = Id;
            this.time = time;
        }
    }
   class User{
    int userId;
    List<Tweet>tweets;
    HashSet<Integer>followers;

    User(int userId){
      this.userId = userId;
      tweets = new LinkedList<>();
      followers = new HashSet<>();
    }

    void addTweet(Tweet t){
        tweets.add(0,t);
        return;
    }

    void addFollower(int FollwerId){
       followers.add(FollwerId);
       return;
    }
    void removeFollower(int FollwerId){
  followers.remove(FollwerId);
       return;
    }
   }
    Map<Integer, User>userMap;
    int tweetTime;                                  
    public Twitter() {
        this.tweetTime = 0;
        this.userMap  = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        this.tweetTime++;
        if(userMap.containsKey(userId) == false){
            userMap.put(userId,new User(userId));
        }
        User u = userMap.get(userId);
        Tweet t = new Tweet(tweetId,this.tweetTime);
        u.addTweet(t);
    }
    
    public List<Integer> getNewsFeed(int userId) {
          if(userMap.containsKey(userId) == false){
             return new ArrayList<>();
          }
          List<Integer>ans= new ArrayList<>();
         PriorityQueue<Tweet> pq = new PriorityQueue<>((a,b)->{
            return b.time - a.time;
         });

         User u = userMap.get(userId);
         // push top 10 tweets from the user
         int cnt = 1;
         for(Tweet tweet : u.tweets){
             pq.add(tweet);
             cnt++;
             if(cnt>10)break;
         }

         for(int followerId : u.followers){
             cnt = 1;
           for(Tweet tweets : userMap.get(followerId).tweets){
             pq.add(tweets);
             cnt++;
             if(cnt>10)break;
           }
         }
        cnt = 0;
         while(cnt<10 && pq.size() > 0){
           ans.add(pq.peek().Id);
           pq.poll();
           cnt++;
         }
         return ans;

    }
    
    public void follow(int followerId, int followeeId) {
         if(!userMap.containsKey(followerId)){
            User u = new User(followerId);
            userMap.put(followerId,u);
         }
         if(!userMap.containsKey(followeeId)){
            User u = new User(followeeId);
             userMap.put(followeeId, u);
         }

          userMap.get(followerId).addFollower(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if(!userMap.containsKey(followerId) || !userMap.containsKey(followeeId)){
            return;
        }

        User u = userMap.get(followerId);
        u.removeFollower(followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */