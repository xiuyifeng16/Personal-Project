/*
/*Name:xiuyi feng
  Due date:09/23/2022 
  Poll.hpp*/ 
#ifndef POLL_H
#define POLL_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Post.hpp"

class Poll : public Post
{
public:
    Poll(const std::string& title, const std::string& body, const std::string& username, const std::vector<std::string>& post);
    bool votePoll(const int& num);
    void changePollOption(const std::string& newOption, const int& newNum);
    void getPollOptions() const;
    int getPollVotes(const int& ind);
    virtual void displayPost() const override;
private:
    std::vector<std::string> poll_options;
    std::vector<int> vote_for_options;
};

#endif