//
// Created by Howard_Yu on 2021/6/17.
//

#include <ctime>
#include "ig.h"

Emoji::Emoji(std::string faceType):shape(std::move(faceType)), count(0){}

void Emoji::operator ++ () { this->count++; }
void Emoji::operator -- () { this->count--; }

void Poster::rate(){
    int rater=0;
    std::cout << "input (1:like 2:angry 3:happy 4:cry 5:break) :";
    std::cin >> rater;
    if(!emojied){
        switch(rater){
            case 1:++this->like;emojied = 1;break;
            case 2:++this->angry;emojied = 2;break;
            case 3:++this->cry;emojied = 3;break;
            case 4:++this->happy;emojied = 4;break;
            case 5:break;
            default:std::cout << "error .";
        }
    } else if(emojied == rater){
        switch(emojied){
            case 1:--this->like;break;
            case 2:--this->angry;break;
            case 3:--this->cry;break;
            case 4:--this->happy;break;
            case 5:break;
            default:std::cout << "error .";
        }
        emojied = 0;
    } else if(emojied){
        switch(emojied){
            case 1:--this->like;break;
            case 2:--this->angry;break;
            case 3:--this->cry;break;
            case 4:--this->happy;break;
            case 5:break;
            default:std::cout << "error .";
        }
        switch(rater){
            case 1:++this->like;emojied = 1;break;
            case 2:++this->angry;emojied = 2;break;
            case 3:++this->cry;emojied = 3;break;
            case 4:++this->happy;emojied = 4;break;
            case 5:break;
            default:std::cout << "error .";
        }
    }
}

Poster::Poster():like(u8"\U00002665"), angry(u8"\U0001F4A2"),
                 happy(u8"\U0001F603"), cry(u8"\U0001F622"), emojied(0){}

std::ostream & operator <<(std::ostream & out, const Emoji& a){
    out << a.shape << " " << a.count << "   ";
    return out;
}

std::istream & operator >> (std::istream & in, Poster & a){
    std::cout << "at (stop with input '*'):";
    std::string input;
    in>>input;
    while(input != "*")
    {
        a.at.push_back(input);
        in>>input;
    }
    a.now = time(nullptr);
    std::cout << "content :";getline(in, a.content) ;
    return in;
}

std::ostream & operator <<(std::ostream & outer, const Poster& a){
    outer << " @ " ;
    for (const auto& tempForOut : a.at)
        outer << tempForOut  << " ";
    outer << (time(nullptr)-a.now) << "second ago "
          << std::endl << "----------"<< std::endl
          << a.content
          << std::endl << "----------"<< std::endl
          << a.like << a.angry << a.cry << a.happy
          << std::endl;
    return outer;
}

void IgServer::login(){
    std::cout << "Input login account (you don't need password) :";
    std::cin >> this->loginUser;
}

void IgServer::batchInput() {
    Poster batchPost;
    std::cin >> batchPost;
    this->PostStack::push(batchPost);
}

std::basic_ostream<char> & operator << (std::basic_ostream<char> & out, IgServer & a){
    for(auto it = a.begin(); it != a.end(); it++){
        out << a.loginUser;
        std::cout << *it;
        out << std::endl;
    }
    return out;
}

std::basic_istream<char> & operator >> (std::basic_istream<char> & in, IgServer & a){
    do{
        std::string flag;
        std::cout << "enter q to quit :";
        std::cin >> flag;
        if(flag =="q"){
            break;
        }
        a.batchInput();
    }while(true);
    return in;
}

void IgServer::reaction(){
    int post_num;
    while(true){
        std::cout <<"add faces to ...(0:exit, 1:first post, ......) :";
        std::cin >> post_num;
        if(!post_num){
            break;
        } else {
            (this->begin()+post_num-1)->rate();
        }
        system("clear");
        operator << (std::cout, *this);
    }
}

int main(){
    IgServer mainProcess;
    mainProcess.login();
    std::cin >> mainProcess;
    system("clear");
    std::cout << mainProcess;
    mainProcess.reaction();
}
