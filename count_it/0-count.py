#!/usr/bin/python3
"""
Module for counting occurrences of keywords in Reddit hot posts
"""
import re
import requests


def count_words(subreddit, word_list, after=None, count_dict=None):
    """
    Recursive function that queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords (case-insensitive).

    Args:
        subreddit (str): The subreddit to search in
        word_list (list): List of keywords to count
        after (str, optional): Token for pagination. Defaults to None.
        count_dict (dict, optional): Dictionary to store word counts. Defaults to None.

    Returns:
        None: Function prints results directly
    """
    # Initialize dictionary on first call
    if count_dict is None:
        # Create a case-insensitive dictionary with lowercase keys
        count_dict = {}
        for word in word_list:
            word_lower = word.lower()
            if word_lower in count_dict:
                continue
            count_dict[word_lower] = 0

    # Base case: if word_list is empty, no need to continue
    if not word_list:
        return None

    # Set up the API request
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {
        "User-Agent": "linux:reddit_keyword_counter:v1.0 (by /u/your_username)"
    }
    params = {"limit": 100}  # Max 100 posts per request

    if after:
        params["after"] = after

    try:
        response = requests.get(url, headers=headers, params=params, allow_redirects=False)

        # Check if the response is valid
        if response.status_code != 200:
            # If we reached this point and have counts, print them; otherwise return
            if any(value > 0 for value in count_dict.values()):
                print_results(count_dict)
            return None

        data = response.json()
        posts = data["data"]["children"]

        # Process each post title
        for post in posts:
            title = post["data"]["title"].lower()
            # Split the title into words, keeping only word boundaries
            words = re.findall(r'\b[a-zA-Z0-9]+\b', title)

            # Count occurrences of each keyword
            for word in words:
                if word in count_dict:
                    count_dict[word] += 1

        # Get the "after" value for the next page
        after = data["data"]["after"]

        # If there's another page, make a recursive call
        if after:
            return count_words(subreddit, word_list, after, count_dict)
        else:
            # No more pages, print the results if any counts are greater than 0
            if any(value > 0 for value in count_dict.values()):
                print_results(count_dict)
            return None

    except Exception:
        # If any error occurs, return None
        return None


def print_results(count_dict):
    """
    Print the results as specified:
    - In descending order by count
    - If counts are equal, sort alphabetically
    - Skip words with no matches
    - Print words in lowercase

    Args:
        count_dict (dict): Dictionary with word counts
    """
    # Filter out words with no matches
    filtered_dict = {k: v for k, v in count_dict.items() if v > 0}

    # Sort by count (descending) and then alphabetically
    sorted_items = sorted(filtered_dict.items(), key=lambda x: (-x[1], x[0]))

    # Print the results
    for word, count in sorted_items:
        print(f"{word}: {count}")
