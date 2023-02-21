/*Name:xiuyi feng
  Due date:09/23/2022 
  Promotional.cpp*/   
#include<iostream>
#include<string>
#include<regex>
#include"Promotional.hpp"
#include"Post.hpp"
using namespace std;

Promotional::Promotional(const string& name,const string& body,const string& username,const string& link):Post(name,body,username)//Sets the title, body, username and link of the Promotional to the value of the parameters.It will also generate the current time and store it.
{
    setLink(link);
}
string Promotional::getLink()const
{
    return url;
}
bool Promotional::setLink(const string& link)//If the link is not correctly formatted, store "Broken Link"in the link member variable, otherwise store the value of the parameter
{
    if(regex_match(link,regex("((^http://)|(^https://))?(www)(.[^./?#]{1,20})(.[^./?#]{2,})")))
    {
        url=link;
        return true;  
    }
    else
    {
        url="Broken Link";
        return false;
    }
}
void Promotional::displayPost()const
{
    std::cout << '\n' << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << std::endl;
    std::cout << getLink() << std::endl;
}