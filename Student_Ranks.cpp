
#include <iostream>
#include <string>
#include <fstream>
#include<map>
#include <vector>
#include <algorithm>
using namespace std;

ofstream Myfile;
ifstream fin;

class  stream{
public:
    string sub1;
    string sub2;
    string sub3;
    int mark1;
    int mark2;
    int mark3;
    string className;
    int tot;
    double avg;
    string name;
    map<string,double>School;
    map<string,double>BioClass;
    map<string,double>MathsClass;
    int Total(){
        tot=mark1+mark2+mark3;
        return tot;

    }
    void clz(string a){
        className=a;
        fin.open("C:/Users/Shiny/OneDrive/Desktop/StuData.txt");
        Myfile.open("C:/Users/Shiny/OneDrive/Desktop/StuData.txt",ios::app);
        Myfile<<"Class "<<className<<"\n\n";
        fin.close();
        Myfile.close();

    }

    void GetName(){
        cout<<"Enter Student Name: ";
        cin>>name;
        }

    void Calculate_school_rank(){
        cout<<"School Ranks"<<"\n";
        vector<pair<string, double>> v {make_move_iterator(begin(School)),make_move_iterator(end(School))};
       sort(begin(v), end(v),[](auto p1, auto p2){return p1.second > p2.second;});
       for (size_t i = 0; i < v.size(); ++i){
          cout << i+1<< "\t" << v[i].first << "\n\n";
        }
    }

    };

class Bio_Stream:public stream{;
public:
    string sub1="Biology";
    string sub2="Physics";
    string sub3="Chemistry";
    void Marks(){
        cout<<"Enter "+sub1+" Marks: ";
        cin>>mark1;
        cout<<"Enter "+sub2+" Marks: ";
        cin>>mark2;
        cout<<"Enter "+sub3+" Marks: ";
        cin>>mark3;
    }



    void save(){
            fin.open("C:/Users/Shiny/OneDrive/Desktop/StuData.txt");
            Myfile.open("C:/Users/Shiny/OneDrive/Desktop/StuData.txt",ios::app);
            Myfile<<"Student Name : "<<name<<"\n";
            Myfile<<sub1<<" : "<<mark1<<"\n";
            Myfile<<sub2<<" : "<<mark2<<"\n";
            Myfile<<sub3<<" : "<<mark3<<"\n\n";
            fin.close();
            Myfile.close();
        }

    void Map_Class_Rank(){
        avg=float(tot)/3;
        cout<<"Average is "<<avg<<"\n\n";
        School.insert(pair<string,double>(name,avg));
        BioClass.insert(pair<string,double>(name,avg));
    }


    void Calculate_class_rank(){
        cout<<"Class Ranks of class "<<className<<"\n";
        vector<pair<string, double>> v {make_move_iterator(begin(BioClass)),make_move_iterator(end(BioClass))};
       sort(begin(v), end(v),[](auto p1, auto p2){return p1.second > p2.second;});
       for (size_t i = 0; i < v.size(); ++i){
          cout << i+1<< "\t" << v[i].first << "\n\n";
        }
        BioClass.clear();
    }


};

class Maths_Stream:public stream{;
public:
    string sub1="Combined Maths";
    string sub2="Physics";
    string sub3="Chemistry";
    void Marks(){
        cout<<"Enter "+sub1+" Marks: ";
        cin>>mark1;
        cout<<"Enter "+sub2+" Marks: ";
        cin>>mark2;
        cout<<"Enter "+sub3+" Marks: ";
        cin>>mark3;

    }


    void save(){
            fin.open("C:/Users/Shiny/OneDrive/Desktop/StuData.txt");
            Myfile.open("C:/Users/Shiny/OneDrive/Desktop/StuData.txt",ios::app);
            Myfile<<"Student Name : "<<name<<"\n";
            Myfile<<sub1<<" : "<<mark1<<"\n";
            Myfile<<sub2<<" : "<<mark2<<"\n";
            Myfile<<sub3<<" : "<<mark3<<"\n\n";
            fin.close();
            Myfile.close();
        }

    void Map_Class_Rank(){
        avg=float(tot)/3;
        cout<<"Average is "<<avg<<"\n\n";
        School.insert(pair<string,double>(name,avg));
        MathsClass.insert(pair<string,double>(name,avg));
    }

    void Calculate_class_rank(){
        cout<<"Class Ranks of class "<<className<<"\n";
        vector<pair<string, double>> v {make_move_iterator(begin(MathsClass)),make_move_iterator(end(MathsClass))};
       sort(begin(v), end(v),[](auto p1, auto p2){return p1.second > p2.second;});
       for (size_t i = 0; i < v.size(); ++i){
          cout << i+1<< "\t" << v[i].first << "\n\n";
        }
        MathsClass.clear();
    }



};

int main() {
    Bio_Stream bioObj;
    Maths_Stream MathsObj;
    stream streamObj;
    string Bio_Class[3]={"A","B","C"};
    string Maths_Class[5]={"A","B","C","D","E"};
    cout<<"Enter Bio Stream Marks"<<"\n\n";
    for (string i:Bio_Class){
        cout<<"Class "<<i<<"\n\n";
        bioObj.clz(i);
        for (int j=1; j<41; j++){
            cout<<"Student "<<j<<"\n";
            bioObj.GetName();
            bioObj.Marks();
            cout<<bioObj.Total()<<"\n";
            bioObj.save();
            bioObj.Map_Class_Rank();

        }
        bioObj.Calculate_class_rank();

    }
    bioObj.Calculate_school_rank();

    cout<<"Enter Maths Stream Marks"<<"\n\n";
    for (string i:Maths_Class){
        cout<<"Class "<<i<<"\n\n";
        MathsObj.clz(i);
        for (int j=1; j<41; j++){
            cout<<"Student "<<j<<"\n";
            MathsObj.GetName();
            MathsObj.Marks();
            cout<<MathsObj.Total()<<"\n";
            MathsObj.save();
            MathsObj.Map_Class_Rank();

        }
        MathsObj.Calculate_class_rank();
    }
    MathsObj.Calculate_school_rank();


    return 0;
}
