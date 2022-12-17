#include<iostream>
#include<vector>

#include<fstream>
#include<string>


class task {
public:
    task() : title_(""), description_("") {}
  task(std::string title, std::string description) : title_(title), description_(description) {}

  // Define operator<< to allow writing a Task object to an fstream
  friend std::ofstream& operator <<(std::ofstream& out, const task& t) {
  //  out << t.title_ <<std::endl<< t.description_;
   out << t.title_ << std::endl << t.description_ << std::endl;
    return out;
  }

  // Define operator>> to allow reading a Task object from an fstream
  friend std::ifstream& operator >>(std::ifstream& in, task& t) {
    //in >> t.title_ >> t.description_;
    std::getline(in, t.title_);
    std::getline(in, t.description_);
         return in;
  }

       std::string getitle(){return title_;}
       std::string getdes(){return description_;}
       void print(){
           std::cout<<" "<<getitle()<<std::endl<<"   "<<getdes()<<std::endl;
       }
private:
  std::string title_;
  std::string description_;

};
std::ofstream& operator<<(std::ofstream& out, const std::vector<task>& tasks) {
  for (const auto& t : tasks) {
    out << t;
  }
  return out;
}

// Define operator>> to allow reading a vector of Task objects from an fstream
std::ifstream& operator>>(std::ifstream& in, std::vector<task>& tasks) {
  tasks.clear();
  task t;
  while (in >> t) {
    tasks.push_back(t);
  }
}
int main(){
char ch;
   bool loop=false;
   
   std::ifstream in("tasks.txt");
    std::vector<task> tasks;
       in >> tasks;
       in.close();
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
     
        std::getline(std::cin, tdescription);
    tasks.push_back(task(ttitle, tdescription));
      }
    else if(ans==1){
    for(int i=0; i<tasks.size();i++){
        tasks[i].print();

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
       std::remove("tasks.txt");
       std::ofstream out("tasks.txt");
    out << tasks;
    out.close();
return 0;
}
