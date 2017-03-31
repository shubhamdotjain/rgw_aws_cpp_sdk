#include<iostream>
#include<map>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
using namespace std;

//This function would create unique name for the bucket in 
string get_new_bucket_name(){ 
    string s;
    cin>>s;
    return s;
  }
class bucket
{
    public:
    int num_key;
    vector<string> keys;
    string name;
    vector<string> list_access_keys();
    bucket()
    {
        name='\0';
    }

};
bucket get_new_bucket()
{
bucket b;
cin>>b.num_key;
string key;
for(int i=0;i<b.num_key;i++)
{
    cin>>key;
    b.keys.push_back(key);
}
return b;
}
vector<string> bucket::list_access_keys()
{
    return keys;
}
vector<bucket> get_all_buckets()
{
    string name;
    name=get_new_bucket_name();
    //cout<<name<<" ";
    bucket b;
    b=get_new_bucket(); 
    b.name=name;
    vector<bucket> bu;
    bu.push_back(b);
    return bu;
}
vector<bucket> get_all_buckets2(vector<bucket> v)
{
    return v;
}




void test_buckets_create_then_list(){
    string name2;
    vector<bucket> create_buckets(2);
    for(int i=0;i<2;i++){
    	name2= get_new_bucket_name(); // would create a unique name of the bucket
        //cout<<name2<<" ";
        create_buckets[i]=get_new_bucket();
        create_buckets[i].name=name2;
        }

    vector<bucket> list_buckets;
    list_buckets=get_all_buckets2(create_buckets);
    //list_buckets=create_buckets; 
    set<string> name_temp;
    for(int i=0;i<list_buckets.size();i++){
        name_temp.insert(list_buckets[i].name);
        }

    const set<string> name=name_temp;
    std::set<string>::iterator it;
    for(int i=0;i<create_buckets.size();i++){
        it=name.find(create_buckets[i].name);
        //cout<<*it<<" ";
        if(it==name.end()){
            cout<<"runtime_error";
            exit(0);
        }
            //cout<<*it;
    }
}
int main()
{

 test_buckets_create_then_list();


    return 0;
}