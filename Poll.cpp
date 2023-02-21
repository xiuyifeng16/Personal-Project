/*Name:xiuyi feng
  Due date:09/23/2022 
  Poll.cpp*/ 
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include "Poll.hpp"

//Constructor to store title, body, username, and the vector of poll options.
Poll::Poll(const std::string& title, const std::string& body, const std::string& username, const std::vector<std::string>& post) : Post(title, body, username)
{

    poll_options = post;

    for (int i = 0; i < poll_options.size(); i++)
    {
        int newVote = 0;
        vote_for_options.push_back(newVote);
    }
}

//increase 1 vote for the poll option that you choosed
bool Poll::votePoll(const int& num)
{
    if (num < 0 || num >= poll_options.size())
    {
        return false;
    }
    else
    {
        vote_for_options[num]++;
    }
    return true;
}

//change or add a poll option in to vector, 
//and will reset the number of vote to zero in this option.
void Poll::changePollOption(const std::string& newOption, const int& newNum)
{
    if (newNum >= poll_options.size())
    {
        poll_options.push_back(newOption);
        int newVote = 0;
        vote_for_options.push_back(newVote);
    }
    else if (newNum > 0 && newNum < poll_options.size())
    {
        poll_options[newNum] = newOption;
        vote_for_options[newNum] = 0;
    }
}

//show all the options and votes.
void Poll::getPollOptions() const
{
    for (int i = 0; i < poll_options.size(); i++)
    {
        std::cout << vote_for_options[i] << " votes for: " << poll_options[i] << std::endl;
    }
}

//get the number of vote of the poll option you have choosen
int Poll::getPollVotes(const int& ind)
{
    return vote_for_options[ind];
}

//display the post, number of vote, and poll options  in a proper way
void Poll::displayPost() const
{
    std::cout << '\n' << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << std::endl;
    getPollOptions();
}