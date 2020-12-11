import tweepy

def main():
    twitter_auth_keys = { 
        "consumer_key"        : "Cle consumeur",
        "consumer_secret"     : "Cle consumeur secret",
        "access_token"        : "acces token",
        "access_token_secret" : "acces token secret"
    }

    auth = tweepy.OAuthHandler(
            twitter_auth_keys['consumer_key'],
            twitter_auth_keys['consumer_secret']
            )
    auth.set_access_token(
            twitter_auth_keys['access_token'],
            twitter_auth_keys['access_token_secret']
            )
    api = tweepy.API(auth)

    tweet = "test 1, i'm a bot"
    status = api.update_status(status=tweet) 

if __name__ == "__main__":
    main()
