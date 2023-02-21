/*Name:xiuyi feng
  Due date:09/23/2022 
  Promotional.hpp*/   
#ifndef PROMOTIONAL_H
#define PROMOTIONAL_H

#include<iostream>
#include<string>
#include"Post.hpp"
using namespace std;
class Promotional:public Post
{
    private:
            string url;
    public:
            Promotional(const string& name,const string& body,const string& username,const string& link);
            string getLink()const;
            bool setLink(const string& link);
            virtual void displayPost()const override;
};
#endif