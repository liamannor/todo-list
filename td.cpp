
#include<iostream>
#include<vector>
#include<ctime>


class task{
    private:
        std::string title;
        std::string description;

    public:
    task(std::string Title, std::string Description){
            title=Title;
            description=Description;
        }

       std::string getitle(){return title;}
       std::string getdes(){return description;}



       void print(){
           std::cout<<" "<<getitle()<<std::endl<<"   "<<getdes()<<std::endl;
       }


};


int main(){
char ch;
   bool loop=false;

       

    std::vector<task> tasks;
    while(loop ==false){
    std::cout<<"add task(0), print all tasks(1), delete task(2)"<<std::endl;
    int ans;
    std::cin>>ans;
    if(ans==0){
        std::cout<<"title:";
        std::string ttitle;
        std::cin>>std::ws;
        std::getline( std::cin,ttitle);
        std::cout<<std::endl<<"description:";
        std::string tdescription;
        //std::cin.ignore();
        std::getline(std::cin, tdescription);
    tasks.push_back(task(ttitle, tdescription));
      }
    else if(ans==1){
    for(int i=0; i<tasks.size();i++){
        tasks[i].print();
   //     std::cout<<tasks[i].getitle();
     //   std::cout<<tasks.size();
    }}
    else if(ans==2){
    int del;
    std::cout<<"which one should i delete?"<<std::endl;
    std::cin>>del;
if(del<=tasks.size()&& del>-1){tasks.erase(tasks.begin()+del-1);}
    }
    std::cout<<"press any key to continue, esc to leave"<<std::endl;
    std::cin>>ch;
if(ch==27){loop=true;}
    }
return 0;
}
