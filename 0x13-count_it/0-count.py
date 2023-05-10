#!/usr/bin/python3
"""This module defines the count_words function"""
import requests


def count_words(subreddit, word_list, word_dict={}, after=""):
    """This method requests the api reddit to return the number time that
    a word is counted in the title of all article for a given subreddit"""
    lower_word_list = [word.lower() for word in word_list]

    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent': 'elodieriou3685'}
    params = {'after': after,
              'limit': 100}

    req_reddit = requests.get(url,
                              headers=headers,
                              params=params,
                              allow_redirects=False)

    if req_reddit.status_code > 300:
        return None

    hot = req_reddit.json().get('data')
    after = hot.get('after')

    for child in hot.get('children'):
        titles = child.get('data').get('title')
        lower_word_title = [title.lower() for title in titles.split(' ')]

        for word in lower_word_list:
            word_dict[word] = word_dict.setdefault(word, 0) + \
                              lower_word_title.count(word)

    if after is not None:
        return count_words(subreddit, lower_word_list, word_dict, after)

    sorted_word_dict = sorted(word_dict.items(), key=lambda w: (-w[1], w[0]))
    for key, value in sorted_word_dict:
        if value > 0:
            print("{}: {}".format(key, value))

    return word_dict
