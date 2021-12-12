// chaining 은 해시 테이블의 특정 위체엇 하나의 연결리스트를 저장한다. 충돌이 발생하면 리스트 맨 뒤에 새로운 키 집어넣음.
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class hash_map{
    vector<list<int>> data;
    public:
        hash_map(size_t n){
            data.resize(n);
        }
        void insert(int value){
            int n = data.size();
            data[value%n].push_back(value);
            printf("%d insert completed!\n", value);
        }
        bool find(int value){
            int n = data.size();
            auto& entries = data[value%n];
            return (std::find(entries.begin(), entries.end(), value) != entries.end());
        }
        void erase(int value){
            int n = data.size();
            auto& entries = data[value%n];
            auto iter = std::find(entries.begin(), entries.end(), value);
            if(iter != entries.end()){
                entries.erase(iter);
                printf("%d delete completed!\n", value);
            }
        }
};
int main(){
    hash_map map(7);
    map.insert(100);
    map.insert(2);
    map.insert(55);
    map.insert(25);
    map.insert(10);
    if(map.find(100)){
        printf("%d existed\n", 100);
    }
    map.erase(2);
}